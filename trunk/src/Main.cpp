#include "EarthquakeScanner.h"
#include "EarthquakeParser.h"

// Entry Point
int main(int argc, char * argv[]) {
	Earthquake::FlexScanner *scanner = new Earthquake::FlexScanner();
	Earthquake::Parser *parser = new Earthquake::Parser(scanner);
	return parser.parse();
}

