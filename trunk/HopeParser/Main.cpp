#include "EarthquakeScanner.h"
#include "EarthquakeParser.h"
#include <iostream>
#include <stdio.h>
#include "normeAntisismiche-parse.h"
#include "utilities.h"
FILE *fin = fopen("fileIntermedio.bd", "r");
int curr_lineno = 1;
YYSTYPE normeAntisismiche_yylval;
// Entry Point
int main(int argc, char * argv[]) {

	Earthquake::Parser parser;

	return parser.parse();
}

