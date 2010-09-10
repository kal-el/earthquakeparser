#ifndef _NORMEANTISISMICHE_PARSE_H
#define _NORMEANTISISMICHE_PARSE_H
//
// See copyright.h for copyright notice and limitation of liability
// and disclaimer of warranty provisions.
//


#ifndef _NORMEANTISISMICHE_H_
#define _NORMEANTISISMICHE_H_

#include "normeAntisismiche-io.h"
//#include "Struttura.h"

/* a type renaming */
typedef int Boolean;
class Entry;
typedef Entry *Symbol;

Boolean copy_Boolean(Boolean);
void assert_Boolean(Boolean);
void dump_Boolean(ostream &,int,Boolean);

Symbol copy_Symbol(Symbol);
void assert_Symbol(Symbol);
void dump_Symbol(ostream &,int,Symbol);

#endif
#include "tree.h"

#ifndef BISON_NORMEANTISISMICHE_TAB_H
#define BISON_NORMEANTISISMICHE_TAB_H

namespace Earthquake{
	class Apertura;
	class Aperture;
	class Interpiano;
	class Piani;
	class Struttura;
	struct token_;
}


#ifndef YYSTYPE
typedef union
{
// qui vanno definiti i vari nodi dell'albero sintattico
  Symbol 					symbol;
  Earthquake::Apertura 		*apertura;
  Earthquake::Aperture 		*aperture;
  Earthquake::Interpiano 	*interpiano;
  Earthquake::Piani 		*piani;
  Earthquake::Struttura 	*struttura;
  Earthquake::token_ 		*token;
  char			 			*error_msg;
} yystype;
# define YYSTYPE yystype
# define YYSTYPE_IS_TRIVIAL 1
#endif
# define	parete 37
# define	linea_piano 59
# define	cordolo 43
# define	apertura 44
# define	architrave 65
# define	float_const 111
# define	ERROR_CONST 103

extern YYSTYPE normeAntisismiche_yylval;

#endif /* not BISON_NORMEANTISISMICHE_TAB_H */
#endif
