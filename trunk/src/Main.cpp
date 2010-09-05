#include "EarthquakeScanner.h"
#include "EarthquakeParser.h"

// Entry Point
int main(int argc, char * argv[]) {
	Earthquake::FlexScanner scanner = new FlexScanner();
	Earthquake::Parser parser = new Parser(scanner);
	return parser.parse();
}

