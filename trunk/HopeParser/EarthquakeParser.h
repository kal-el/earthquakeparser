#pragma once

namespace Earthquake {
	class Parser {
		public:
			Parser() : parser(scanner) {}
		
			int parse() {

				return parser.parse();
			}
		
		private:
			Earthquake::FlexScanner scanner;
			Earthquake::BisonParser parser;
	};
}
