#include "normeantisismiche.tab.hh"
#include "EarthquakeScanner.h"
#include "EarthquakeParser.h"
#include <iostream>
#include <stdio.h>
#include "utilities.h"
#include "Exceptions.h"

FILE *fin = fopen("fileIntermedio.bd", "r");
int curr_lineno = 1;

Earthquake::BisonParser::semantic_type normeAntisismiche_yylval;

// Entry Point
int main(int argc, char * argv[]) {

	Earthquake::Parser parser;

	return parser.parse();
}

