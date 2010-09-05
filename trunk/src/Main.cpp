#include "EarthquakeScanner.h"
#include "EarthquakeParser.h"
using namespace Earthquake;
// Entry Point
int main(int argc, char * argv[]) {
	Earthquake::Parser parser;
	return parser.parse();
}

