#include "EarthquakeScanner.h"
#include "EarthquakeParser.h"
#include <iostream>
#include <stdio.h>
FILE *fin = fopen("fileIntermedio.bd", "r");

// Entry Point
int main(int argc, char * argv[]) {

	Earthquake::Parser parser;

	return parser.parse();
}

