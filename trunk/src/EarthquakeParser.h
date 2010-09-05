#pragma once

namespace Earthquake {
	class Parser {
		public:
			Parser(FlexScanner s){
				parser = new BisonParser(s);
			}
		
			int parse() {
				return this->parser->parse();
			}
		
		private:
			//Earthquake::FlexScanner scanner;
			Earthquake::BisonParser *parser;
	};
}
