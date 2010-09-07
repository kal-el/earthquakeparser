/* $Id: parser.yy 48 2009-09-05 08:07:10Z tb $ -*- mode: c++ -*- */
/** \file parser.yy Contains the example Bison parser source */

%{ /*** C/C++ Declarations ***/

#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include "Struttura.h"
//#include "EarthquakeScanner.h"
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
    double 			doubleVal;
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

%token PARETE  
%token LINEAPIANO
%token CORDOLO
%token APERTURA
%token APERTURE
%token ARCHITRAVE
%token MASCHIO
%token INTERPIANO
%token floatingp


%token			END	     0	"end of file"
%token			EOL		"end of line"


%type <struttura>	struttura 
%type <piani>	piani
//%type <interpiano>	interpiano
//%type <token>	CORDOLO PARETE LINEAPIANO ARCHITRAVE MASCHIO APERTURA
%type <apertura>	apertura



//%destructor { delete $$; } CORDOLO //PARETE LINEAPIANO ARCHITRAVE APERTURA

%destructor { delete $$; } struttura piani apertura //interpiano

 /*** END EXAMPLE - Change the example grammar's tokens above ***/

%{

%}

%% /*** Grammar Rules ***/

 /*** BEGIN EXAMPLE - Change the example grammar rules below ***/
 
			/** piani <contains, not intersect> aperture **/
struttura : piani aperture
           {
		   //Struttura's contructor checks the <contains, not intersect> property
	       $$ = new Struttura(*($1), ($<ap>2)->getList());
		   list<token_*> maschi = $$->calcolaMaschi();
		   try{
				$$->verificaProprietaMaschio(maschi);
		   }
		   catch(PropertyViolationException *ex) {
				printf("I maschi non rispettano le proprieta \n");
		   }
		}
     

		/** piani <contains> interpiani **/
piani : piani interpiani
           {
				list<Interpiano> interpianiList = $<piani>1->getInterpiani();
				interpianiList.push_back(*($<interpiano>2));
				$$ = new Piani(interpianiList, $1->getParete());
	       }
		   
		| parete_tk
			{
				$$ = new Piani($<element>1);
			}
	   

			/** LINEAPIANO <isUnder, Height(0.2,0.4)> CORDOLO **/
interpiani : lineapiano_tk cordolo_tk
				{
					$<interpiano>$ = new Interpiano($<element>1, $<element>2);
				}
			| lineapiano_tk
				{
					$<interpiano>$ = new Interpiano($<element>1);
				}
           

			/** aperture <not intersect> apertura **/
aperture	: aperture apertura
				{
					($<ap>1)->getList().push_back(*($2));
					$<ap>$ = $<ap>1;
				}
			| apertura
				{
					list<Apertura> apertureList;
					apertureList.push_back(*$1);
					$<ap>$ = new Aperture(apertureList);
				}

				
			/** APERTURA <isAbove, Height(0.1,0.2),isCentered,isLarger(0.15,0.3)> ARCHITRAVE **/
apertura : apertura_tk architrave_tk
			{
				$$ = new Apertura($<element>1, $<element>2);
			}
			
	
apertura_tk : APERTURA floatingp floatingp floatingp floatingp
			{
				token_ * t = (token_ *)malloc(sizeof(token_*));
				t->type = $<integerVal>1;
				t->x1 = $<floatVal>2;
				t->y1 = $<floatVal>3;
				t->x2 = $<floatVal>4;
				t->y2 = $<floatVal>5;
				
				$<element>$ = t;
			}
			
			
architrave_tk : ARCHITRAVE floatingp floatingp floatingp floatingp
			{
				token_ * t = (token_ *)malloc(sizeof(token_*));
				t->type = $<integerVal>1;
				t->x1 = $<floatVal>2;
				t->y1 = $<floatVal>3;
				t->x2 = $<floatVal>4;
				t->y2 = $<floatVal>5;
				
				$<element>$ = t;
			}
			
			
lineapiano_tk : LINEAPIANO floatingp floatingp floatingp floatingp
			{
				token_ * t = (token_ *)malloc(sizeof(token_*));
				t->type = $<integerVal>1;
				t->x1 = $<floatVal>2;
				t->x2 = $<floatVal>3;
				t->y1 = $<floatVal>4;
				t->y2 = $<floatVal>5;
				
				$<element>$ = t;
			}
			
			
cordolo_tk : CORDOLO floatingp floatingp floatingp floatingp
			{
				token_ * t = (token_ *)malloc(sizeof(token_*));
				t->type = $<integerVal>1;
				t->x1 = $<floatVal>2;
				t->x2 = $<floatVal>3;
				t->y1 = $<floatVal>4;
				t->y2 = $<floatVal>5;
				
				$<element>$ = t;
			}
			
			
parete_tk : PARETE floatingp floatingp floatingp floatingp
			{
				token_ * t = (token_ *)malloc(sizeof(token_*));
				t->type = $<integerVal>1;
				t->x1 = $<floatVal>2;
				t->x2 = $<floatVal>3;
				t->y1 = $<floatVal>4;
				t->y2 = $<floatVal>5;
				
				$<element>$ = t;
			}
			
			
            
			
 /*** END EXAMPLE - Change the example grammar rules above ***/

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
