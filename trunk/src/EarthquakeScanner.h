#pragma once

// Only include FlexLexer.h if it hasn't been already included
#include <FlexLexer.h>


// Override the interface for yylex since we namespaced it
#undef YY_DECL
#define YY_DECL int Earthquake::FlexScanner::yylex()
#define yylex normeAntisismiche_yylex
#define yyFlexLexer FlexLexer
// Include Bison for types / tokens
#include "normeantisismiche.tab.hh"
#include <iostream>
using namespace std;
namespace Earthquake {
	class FlexScanner : public yyFlexLexer{
		public:

			// save the pointer to yylval so we can change it, and invoke scanner
			int yylex(Earthquake::BisonParser::semantic_type * lval)
			{
				yylval = lval;
				return yylex(lval);
			}
		
		private:
			// Scanning function created by Flex; make this private to force usage
			// of the overloaded method so we can get a pointer to Bison's yylval
			int yylex(Earthquake::BisonParser::semantic_type * yylval, Earthquake::FlexScanner &scanner);
			
			// point to yylval (provided by Bison in overloaded yylex)
			Earthquake::BisonParser::semantic_type * yylval;
	};


};

