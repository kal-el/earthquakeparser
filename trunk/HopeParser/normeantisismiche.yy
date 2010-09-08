/* $Id: parser.yy 48 2009-09-05 08:07:10Z tb $ -*- mode: c++ -*- */
/** \file parser.yy Contains the example Bison parser source */

%{ /*** C/C++ Declarations ***/
#include "Struttura.h"
#include <stdio.h>
#define ELEMENT $<element>
%}

%skeleton "lalr1.cc"
%defines
%define namespace "Earthquake"
%define parser_class_name "BisonParser"
%parse-param { Earthquake::FlexScanner &scanner }
%lex-param   { Earthquake::FlexScanner &scanner }

%code requires {
	// Forward-declare the Scanner class; the Parser needs to be assigned a 
	// Scanner, but the Scanner can't be declared without the Parser
	namespace Earthquake {
		class FlexScanner;
		class Apertura;
		class Aperture;
		class Interpiano;
		class Piani;
		class Struttura;
	}
	
}

%code {
	// Prototype for the yylex function
	static int yylex(Earthquake::BisonParser::semantic_type * yylval, Earthquake::FlexScanner &scanner);
	
}

 /*** BEGIN EXAMPLE - Change the example grammar's tokens below ***/

%union {
    int  			integerVal;
    //double 			floatVal;
    std::string*		stringVal;
    float floatVal;
    struct token_	*element;
    Apertura	*apertura;
	Interpiano *interpiano;
	Piani		*piani;
	Struttura *struttura;
	Aperture	*ap;
}

//Token List
//if we need it, we can use %token TOKEN "blabla" to see blabla as a literal token (not yacc compatible)

/* %token <struct token_ *> PARETE  
	%token <struct token_ *> LINEA_PIANO
	%token <struct token_ *> CORDOLO
	%token <struct token_ *> APERTURA
	%token <struct token_ *> ARCHITRAVE
	%token <struct token_ *> MASCHIO
*/

%token PARETE 37 
%token LINEAPIANO	59
%token CORDOLO	43
%token APERTURA	44
//%token APERTURE	"APERTURE"
%token ARCHITRAVE	65
//%token MASCHIO
//%token INTERPIANO	"INTERPIANO"
%token f_const_		111
%token ERROR	"ERROR"


%token			END	     0	"end of file"
%token			EOL		"end of line"


%type <struttura>	struttura 
%type <piani>	piani
//%type <interpiano>	interpiano
//%type <token>	CORDOLO PARETE LINEAPIANO ARCHITRAVE MASCHIO APERTURA
%type <apertura>	APERTURA



//%destructor { delete $$; } CORDOLO //PARETE LINEAPIANO ARCHITRAVE APERTURA

%destructor { delete $$; } struttura piani APERTURA //interpiano

 /*** END EXAMPLE - Change the example grammar's tokens above ***/

%{

%}

%% /*** Grammar Rules ***/

%start struttura;

 
			/** piani <contains, not intersect> aperture **/
struttura : piani aperture
           {
           cout << "STRUTTURAAAAAAHHHHH\n\n";
		   //Struttura's contructor checks the <contains, not intersect> property
	       $$ = new Struttura(*($1), ($<ap>2)->getList());
		   list<token_*> maschi = $$->calcolaMaschi();
		   try{
				$$->verificaProprietaMaschio(maschi);
		   }
		   catch(PropertyViolationException *ex) {
				cout << "I maschi non rispettano le proprieta \n";
		   }
		}
     

		/** piani <contains> interpiani **/
piani : piani interpiani
           {
           		printf("INTERPIANI %d %f %f %f %f",$<element>2->type,$<element>2->x1,$<element>2->y1,
           			$<element>2->x2,$<element>2->y2);
				list<Interpiano> interpianiList = $<piani>1->getInterpiani();
				interpianiList.push_back(*($<interpiano>2));
				$$ = new Piani(interpianiList, $1->getParete());
	       }
		   
		| parete_tk
			{
			//int tipo = $<element>1->type;
			//float
			printf("PIANI_pr2: %d %.1f %f %f %f",$<element>1->type,(float)$<element>1->x1,$<element>1->y1,$<element>1->x2,
					$<element>1->y2);
				$$ = new Piani($<element>1);
			}
	   

			/** LINEAPIANO <isUnder, Height(0.2,0.4)> CORDOLO **/
interpiani : lineapiano_tk cordolo_tk
				{
				cout << "INTERPIANI_pr1: " << $<element>1->type << " || " << $<element>1->x1 << " || " << $<element>1->y1 << $<element>2->x2 << " || " << $<element>1->y2
					<< "\n-" << $<element>2->type << " || " << $<element>2->x1 << " || " << $<element>2->y1 << $<element>2->x2 << " || " << $<element>2->y2 << "\n\n";

					$<interpiano>$ = new Interpiano($<element>1, $<element>2);
				}
			| lineapiano_tk
				{
				cout << "INTERPIANI_pr2: " << $<element>1->type << " || " << $<element>1->x1 << " || " << $<element>1->y1 << $<element>1->x2 << " || " << $<element>1->y2 <<"\n\n";
				
					$<interpiano>$ = new Interpiano($<element>1);
				}
           

			/** aperture <not intersect> apertura **/
aperture	: aperture apertura_pr
				{
				cout << "APERTURA_pr1: " << $<element>2->type << " || " << $<element>2->x1 << " || " << $<element>2->y1 << $<element>2->x2 << " || " << $<element>2->y2 <<"\n\n";
				
					($<ap>1)->getList().push_back(*($<apertura>2));
					$<ap>$ = $<ap>1;
				}
			| apertura_pr
				{
				cout << "APERTURA_pr2: " << $<element>1->type << " || " << $<element>1->x1 << " || " << $<element>1->y1 << " || " << $<element>1->x2 << " || " << $<element>1->y2 << "\n\n";
				
					list<Apertura> apertureList;
					apertureList.push_back(*($<apertura>1));
					$<ap>$ = new Aperture(apertureList);
				}

				
			/** APERTURA <isAbove, Height(0.1,0.2),isCentered,isLarger(0.15,0.3)> ARCHITRAVE **/
apertura_pr : apertura_tk architrave_tk
			{
			cout << "APERTURA_PR: " << $<element>1->type << " || " << $<element>1->x1 << " || " << $<element>1->y1 << " || " << $<element>1->x2 << " || " << $<element>1->y2 
				<< "\n-" << $<element>2->type << " || " << $<element>2->x1 << " || " << $<element>2->y1 << $<element>2->x2 << " || " << $<element>2->y2 <<"\n\n";
				$<apertura>$ = new Apertura($<element>1, $<element>2);
			}
			
	
apertura_tk : APERTURA f_const_ f_const_ f_const_ f_const_
			{
			cout << "APERTURA: " << APERTURA_ << ": " << $<floatVal>2 << " || " << $<floatVal>3 << " || " << $<floatVal>4 << " || " << $<floatVal>5 << "\n\n";
				token_ * t = (token_ *)malloc(sizeof(token_*));
				t->type = $<integerVal>1;
				t->x1 = $<floatVal>2;
				t->y1 = $<floatVal>3;
				t->x2 = $<floatVal>4;
				t->y2 = $<floatVal>5;
				
				$<element>$ = t;
			}
			
			| APERTURA error
				{
					//error(@$, "che palleeee\n");
					cout << "NOOOOOO\n";
				}
			| error f_const_ f_const_ f_const_ f_const_
				{
					//error(@$, "che palleeee\n");
					cout << "NOOOOOO\n";
				}
			
			
architrave_tk : ARCHITRAVE f_const_ f_const_ f_const_ f_const_
			{
			cout << "ARCHITRAVE: " << ARCHITRAVE_ << ": " << $<floatVal>2 << " || " << $<floatVal>3 << " || " << $<floatVal>4 << " || " << $<floatVal>5 << "\n\n";
			
				token_ * t = (token_ *)malloc(sizeof(token_*));
				t->type = ARCHITRAVE_;
				t->x1 = $<floatVal>2;
				t->y1 = $<floatVal>3;
				t->x2 = $<floatVal>4;
				t->y2 = $<floatVal>5;
				
				$<element>$ = t;
			}
			
			| ARCHITRAVE error
				{
					//error(@$, "che palleeee\n");
					cout << "NOOOOOO\n";
				}
			
			
lineapiano_tk : LINEAPIANO f_const_ f_const_ f_const_ f_const_
			{
			cout << "LINEAPIANO: " << ": " << $<floatVal>2 << " || " << $<floatVal>3 << " || " << $<floatVal>4 << " || " << $<floatVal>5 << "\n\n";
			
				token_ * t = (token_ *)malloc(sizeof(token_*));
				t->type = LINEA_PIANO_;
				t->x1 = $<floatVal>2;
				t->x2 = $<floatVal>3;
				t->y1 = $<floatVal>4;
				t->y2 = $<floatVal>5;
				
				$<element>$ = t;
			}
			
			| LINEAPIANO error
				{
					//error(@$, "che palleeee\n");
					cout << "NOOOOOO\n";
				}
			
			
cordolo_tk : CORDOLO f_const_ f_const_ f_const_ f_const_
			{
			cout << "CORDOLO: " << CORDOLO_ << ": " << $<floatVal>2 << " || " << $<floatVal>3 << " || " << $<floatVal>4 << " || " << $<floatVal>5 << "\n\n";
			
				token_ * t = (token_ *)malloc(sizeof(token_*));
				t->type = CORDOLO_;
				t->x1 = $<floatVal>2;
				t->x2 = $<floatVal>3;
				t->y1 = $<floatVal>4;
				t->y2 = $<floatVal>5;
				
				$<element>$ = t;
			}
			
			| CORDOLO error
				{
					//error(@$, "che palleeee\n");
					cout << "NOOOOOO\n";
				}
			
			
parete_tk : PARETE f_const_ f_const_ f_const_ f_const_
			{
			cout << "PARETE: " << PARETE_ << ": " << $<floatVal>2 << " || " << $<floatVal>3 << " || " << $<floatVal>4 << " || " << $<floatVal>5 << "\n\n";
			
				token_ * t = (token_ *)malloc(sizeof(token_*));
				t->type = PARETE_;
				t->x1 = $<floatVal>2;
				t->x2 = $<floatVal>3;
				t->y1 = $<floatVal>4;
				t->y2 = $<floatVal>5;
				
				$<element>$ = t;
			}
			
			| PARETE error
				{
					cout << "CCCCCCC\n";
				}



%% /*** Additional Code ***/

void Earthquake::BisonParser::error(const Earthquake::BisonParser::location_type &loc, const std::string &msg) {
	std::cerr << "Error: " << msg << std::endl;
}

// Now that we have the Parser declared, we can declare the Scanner and implement
// the yylex function
#include "EarthquakeScanner.h"
static int yylex(Earthquake::BisonParser::semantic_type * yylval, Earthquake::FlexScanner &scanner) {
	return scanner.yylex(yylval);
}
