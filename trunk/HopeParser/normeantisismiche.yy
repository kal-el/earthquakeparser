/* $Id: parser.yy 48 2009-09-05 08:07:10Z tb $ -*- mode: c++ -*- */
/** \file parser.yy Contains the example Bison parser source */

%{ /*** C/C++ Declarations ***/
#include "Struttura.h"
#include <stdio.h>
#include "stringtab.h"

# define	parete 		37
# define	linea_piano 59
# define	cordolo 	43
# define	apertura 	44
# define	architrave 	65
# define	float_const 111
# define	ERROR_CONST 103

%}
%defines
%skeleton "lalr1.cc"

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
		struct token_;
	}
	class FloatEntry;
	class Entry;
}

%code {
	// Prototype for the yylex function
	static int yylex(Earthquake::BisonParser::semantic_type * yylval, Earthquake::FlexScanner &scanner);
	
}

 /*** BEGIN EXAMPLE - Change the example grammar's tokens below ***/


%union {
    int  				integerVal;
    std::string*		stringVal;
    float 				floatVal;
    struct token_		*element;
    Apertura			*open;
	Interpiano 			*inter;
	Piani				*floors;
	Struttura 			*structure;
	Aperture			*openings;
	Entry				*entry;
};

//Token List
//if we need it, we can use %token TOKEN "blabla" to see blabla as a literal token (not yacc compatible)


%token PARETE 37 
%token LINEAPIANO	59
%token CORDOLO	43
%token APERTURA	44
//%token APERTURE	"APERTURE"
%token ARCHITRAVE	65
//%token MASCHIO
//%token INTERPIANO	"INTERPIANO"
%token <symbol> f_const_		111
%token ERROR 113



%token			END	     0	"end of file"
%token			EOL		"end of line"


%type <structure>	struttura 
%type <floors>	piani
//%type <inter>	interpiano
//%type <token>	CORDOLO PARETE LINEAPIANO ARCHITRAVE MASCHIO APERTURA
%type <open>	APERTURA



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
	       $$ = new Struttura(*($1), ($<openings>2)->getList());
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
           		printf("INTERPIANI %d %f %f %f %f",$<element>2->type,$<element>2->x1,
           			$<element>2->y1,$<element>2->x2,$<element>2->y2);
				list<Interpiano> interpianiList = $<floors>1->getInterpiani();
				interpianiList.push_back(*($<inter>2));
				$$ = new Piani(interpianiList, $1->getParete());
	       }
		   
		| parete_tk
			{
			printf("PIANI_pr2: %d %.1f %f %f %f",$<element>1->type,
				$<element>1->x1,$<element>1->y1,$<element>1->x2,
			$<element>1->y2);
				$$ = new Piani($<element>1);
			}
	   

			/** LINEAPIANO <isUnder, Height(0.2,0.4)> CORDOLO **/
interpiani : lineapiano_tk cordolo_tk
				{
				cout << "INTERPIANI_pr1: " << $<element>1->type << " || " << $<element>1->x1 << " || " << $<element>1->y1 << $<element>2->x2 << " || " << $<element>1->y2
					<< "\n-" << $<element>2->type << " || " << $<element>2->x1 << " || " << $<element>2->y1 << $<element>2->x2 << " || " << $<element>2->y2 << "\n\n";

					$<inter>$ = new Interpiano($<element>1, $<element>2);
				}
			| lineapiano_tk
				{
				cout << "INTERPIANI_pr2: " << $<element>1->type << " || " << $<element>1->x1 << " || " << $<element>1->y1 << $<element>1->x2 << " || " << $<element>1->y2 <<"\n\n";
				
					$<inter>$ = new Interpiano($<element>1);
				}
           

			/** aperture <not intersect> apertura **/
aperture	: aperture apertura_pr
				{
				cout << "APERTURA_pr1: " << $<element>2->type << " || " << $<element>2->x1 << " || " << $<element>2->y1 << $<element>2->x2 << " || " << $<element>2->y2 <<"\n\n";
				
					($<openings>1)->getList().push_back(*($<open>2));
					$<openings>$ = $<openings>1;
				}
			| apertura_pr
				{
				cout << "APERTURA_pr2: " << $<element>1->type << " || " << $<element>1->x1 << " || " << $<element>1->y1 << " || " << $<element>1->x2 << " || " << $<element>1->y2 << "\n\n";
				
					list<Apertura> apertureList;
					apertureList.push_back(*($<open>1));
					$<openings>$ = new Aperture(apertureList);
				}

				
			/** APERTURA <isAbove, Height(0.1,0.2),isCentered,isLarger(0.15,0.3)> ARCHITRAVE **/
apertura_pr : apertura_tk architrave_tk
			{
			cout << "APERTURA_PR: " << $<element>1->type << " || " << $<element>1->x1 << " || " << $<element>1->y1 << " || " << $<element>1->x2 << " || " << $<element>1->y2 
				<< "\n-" << $<element>2->type << " || " << $<element>2->x1 << " || " << $<element>2->y1 << $<element>2->x2 << " || " << $<element>2->y2 <<"\n\n";
				$<open>$ = new Apertura($<element>1, $<element>2);
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
			//cout << "CORDOLO: " << CORDOLO_ << ": " << $<floatVal>2 << " || " << $<floatVal>3 << " || " << $<floatVal>4 << " || " << $<floatVal>5 << "\n\n";
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
				token_ * t = (token_ *)malloc(sizeof(token_*));
				t->type = PARETE_;
				//t->x1 = $<symbol>2->get_string();
				
				t->x2 = $<floatVal>3;
				t->y1 = $<floatVal>4;
				t->y2 = $<floatVal>5;
				/*cout << "PARETEEEEEEEE " << " " << t->x1 << " " << t->y1 
				<< " " << $<symbol>4->get_string() << " " << $<floatVal>5 << endl;*/
				cout << "AZZ\n";
				cout << $<entry>2->str << endl;
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
