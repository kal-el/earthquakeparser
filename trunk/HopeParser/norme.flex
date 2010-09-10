/*
 *  The scanner definition for normeAntisismiche.
 */

/*
 *  Stuff enclosed in %{ %} in the first section is copied verbatim to the
 *  output, so headers and global definitions are placed here to be visible
 * to the code in the file.  Don't remove anything that was here initially
 */
%{

#include "normeantisismiche.tab.hh"
#include "stringtab.h"
#include "utilities.h"
#include "EarthquakeScanner.h"
#include <stdio.h>
/* The compiler assumes these identifiers. */

# define	parete 		37
# define	linea_piano 59
# define	cordolo 	43
# define	apertura 	44
# define	architrave 	65
# define	float_const 111
# define	ERROR_CONST 103

/* Max size of string constants */
#define MAX_STR_CONST 1025
#define YY_NO_UNPUT   /* keep g++ happy */

extern FILE *fin; /* we read from this file */

/* define YY_INPUT so we read from the FILE fin:
 * This change makes it possible to use this scanner in
 * the normeAntisismiche compiler.
 */
#undef YY_INPUT
#define YY_INPUT(buf,result,max_size) \
	if ( (result = fread( (char*)buf, sizeof(char), max_size, fin)) < 0) \
		YY_FATAL_ERROR( "read() in flex scanner failed");

char string_buf[MAX_STR_CONST]; /* to assemble string constants */
char *string_buf_ptr;


extern int curr_lineno;
extern int verbose_flag;
extern YYSTYPE normeAntisismiche_yylval;
int begin = 1;
int prevstate;

/* altre eventuali inizializzazioni vanno qui*/ 

%}

%option nodefault yyclass="FlexScanner" noyywrap c++

%x INTERPIANO APERTURE PARETE LINEAPIANO APERTURA ARCHITRAVE CORDOLO ERROR
num          [0-9]+
floatingp    {num}"."{num}
%%


 /*
  *  Nested comment
 
  */



"struttura$$$" {
	if(!begin) {
		printf("L'elemento iniziale deve essere \"struttura\"!!");	
		exit(0);
	} else {
		begin = 0;
		prevstate = INITIAL;	
	}
}

"parete$" {
	prevstate = INITIAL;
	BEGIN(PARETE);
	return(parete);
}


<PARETE,LINEAPIANO,APERTURA,ARCHITRAVE,CORDOLO>[0-9]+("."[0-9]+)? {
	//normeAntisismiche_yylval.symbol = floattable.add_float(atof(yytext));
	normeAntisismiche_yylval.symbol = floattable.add_string(yytext,yyleng-1);
	//yytext[yyleng-1]='\0';
	//printf("LEEEEEEXEEEEER %s\n", yytext);		
	return(float_const);
}

<PARETE,LINEAPIANO,APERTURA,ARCHITRAVE,CORDOLO>";" {
	
}

<PARETE,LINEAPIANO,APERTURA,ARCHITRAVE,CORDOLO>"$$$" {
	BEGIN(prevstate);		
}


"interpiano$$$" {
	prevstate = INITIAL;
	BEGIN(INTERPIANO);
}

<INTERPIANO>"lineapiano$" {
	prevstate = INTERPIANO;
	BEGIN(LINEAPIANO);
	return(linea_piano);
}

<INTERPIANO>"cordolo$" {
	prevstate = INTERPIANO;
	BEGIN(CORDOLO);
	return(cordolo);	
}

<INTERPIANO>"&ip&" {
	BEGIN(INITIAL);

}

"aperture$$$" {
	BEGIN(APERTURE);
}

<APERTURE>"apertura$" {
	prevstate = APERTURE;
	BEGIN(APERTURA);
	return(apertura);
}

<APERTURE>"architrave$" {
	prevstate = APERTURE;
	BEGIN(ARCHITRAVE);
	return(architrave);
}

<APERTURE>"&ap&" {
	BEGIN(INITIAL);
}

<INITIAL,PARETE,LINEAPIANO,APERTURA,ARCHITRAVE,CORDOLO>"\n" {
	curr_lineno++;
}

<INITIAL,PARETE,LINEAPIANO,APERTURE,ARCHITRAVE,CORDOLO>. {
	printf("Lessema non riconosciuto: %s", yytext);
	return(ERROR);
}




%%


