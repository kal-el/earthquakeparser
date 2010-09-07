#include "EarthquakeScanner.h"
#include "EarthquakeParser.h"

// Entry Point
int main(int argc, char * argv[]) {
	Earthquake::Parser parser;
	return parser.parse();
}

