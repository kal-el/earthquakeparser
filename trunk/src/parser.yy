/* $Id: parser.yy 48 2009-09-05 08:07:10Z tb $ -*- mode: c++ -*- */
/** \file parser.yy Contains the example Bison parser source */

%{ /*** C/C++ Declarations ***/

#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include "Struttura.h"

%}

/*** yacc/bison Declarations ***/

/* Require bison 2.3 or later */
%require "2.3"

/* add debug output code to generated parser. disable this for release
 * versions. */
%debug

/* start symbol is named "start" */
%start struttura

/* write out a header file containing the token defines */
%defines

/* use newer C++ skeleton file */
%skeleton "lalr1.cc"

/* namespace to enclose parser in */
%name-prefix="example"

/* set the parser's class identifier */
%define "parser_class_name" "Parser"

/* keep track of the current position within the input */
%locations
%initial-action
{
    // initialize the initial location object
    @$.begin.filename = @$.end.filename = &driver.streamname;
};

/* The driver is passed by reference to the parser and to the scanner. This
 * provides a simple but effective pure interface, not relying on global
 * variables. */
%parse-param { class Driver& driver }

/* verbose error messages */
%error-verbose

 /*** BEGIN EXAMPLE - Change the example grammar's tokens below ***/

%union {
    int  			integerVal;
    //double 			doubleVal;
    //std::string*		stringVal;
    float a;
    struct token_	*element;
    class Apertura	*apertura;
	class Interpiano *interpiano;
	class Piani		*piani;
	class Struttura *struttura;
	std::list<Apertura>	ap;
}

//Token List
//if we need it, we can use %token TOKEN "blabla" to see blabla as a literal token (not yacc compatible)
%token <token_ *> PARETE  
%token <token_ *> LINEA_PIANO
%token <token_ *> CORDOLO
%token <token_ *> APERTURA
%token <token_ *> ARCHITRAVE
%token <token_ *> MASCHIO


%token			END	     0	"end of file"
%token			EOL		"end of line"


%type <struttura>	struttura 
%type <piani>	piani
//%type <interpiano>	interpiano
//%type <token>	CORDOLO PARETE LINEA_PIANO ARCHITRAVE MASCHIO APERTURA
%type <apertura>	apertura


%destructor { delete $$; } CORDOLO PARETE LINEA_PIANO ARCHITRAVE APERTURA
%destructor { delete $$; } struttura piani apertura //interpiano

 /*** END EXAMPLE - Change the example grammar's tokens above ***/

%{

#include "driver.h"
#include "scanner.h"

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer->lex

%}

%% /*** Grammar Rules ***/

 /*** BEGIN EXAMPLE - Change the example grammar rules below ***/
 
			/** piani <contains, not intersect> aperture **/
struttura : piani aperture
           {
		   //Struttura's contructor checks the <contains, not intersect> property
	       $$ = new Struttura($1, $<ap>2);
		   list<token*> maschi = $$.calcolaMaschi();
		   try{
				verificaProprietaMaschio(maschi);
		   }
		   catch(PropertyViolationException *ex) {
				cout >> "I maschi non rispettano le propriet�\n";
		   }
		}
     

		/** piani <contains> interpiani **/
piani : piani interpiani
           {
				list<Interpiano> interpianiList = $1.getInterpiani();
				interpianiList.push_back($<Piani>2);
				$$ = new Piani(interpianiList, $1.getParete());
	       }
		   
		| PARETE
			{
				$$ = new Piani($<token_ *>1);
			}
	   

			/** LINEA_PIANO <isUnder, Height(0.2,0.4)> CORDOLO **/
interpiani : LINEA_PIANO CORDOLO
				{
					$<Interpiano>$ = new Interpiano($<token_ *>1, $<token_ *>2);
				}
			| LINEA_PIANO
				{
					$<Interpiano>$ = new Interpiano($<token_ *>1);
				}
           

			/** aperture <not intersect> apertura **/
aperture	: aperture apertura
				{
					$<ap>1.push_back($2);
					$<ap>$ = $<ap>1;
				}
			| apertura
				{
					list<Apertura> apertureList;
					apertureList.push_back($1);
					$<ap>$ = apertureList;
				}

				
			/** APERTURA <isAbove, Height(0.1,0.2),isCentered,isLarger(0.15,0.3)> ARCHITRAVE **/
apertura : APERTURA ARCHITRAVE
			{
				$$ = new Apertura($<token_ *>1, $<token_ *>2);
			}
            
			
 /*** END EXAMPLE - Change the example grammar rules above ***/

%% /*** Additional Code ***/

void example::Parser::error(const Parser::location_type& l,
			    const std::string& m)
{
    driver.error(l, m);
}
