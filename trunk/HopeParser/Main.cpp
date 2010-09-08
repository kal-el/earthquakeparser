#include "EarthquakeScanner.h"
#include "EarthquakeParser.h"
#include <iostream>
#include <stdio.h>
FILE *fin = fopen("fileIntermedio.bd", "r");
int curr_lineno = 1;
// Entry Point
int main(int argc, char * argv[]) {

	Earthquake::Parser parser;

	return parser.parse();
}

