#ifndef _NORMEANTISISMICHE_PARSE_H
#define _NORMEANTISISMICHE_PARSE_H
//
// See copyright.h for copyright notice and limitation of liability
// and disclaimer of warranty provisions.
//
//#include "copyright.h"

#ifndef _NORMEANTISISMICHE_H_
#define _NORMEANTISISMICHE_H_
#include "normeAntisismiche-io.h"
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

// qua vanno definite le varie classi utilizzate in fase di analisi sintattica
/* ad esempio:
typedef class Program_class *Program;
typedef class Class__class *Class_;
typedef class Feature_class *Feature;
typedef class Formal_class *Formal;
typedef class Expression_class *Expression;
*/
#ifndef BISON_NORMEANTISISMICHE_TAB_H
# define BISON_NORMEANTISISMICHE_TAB_H

#ifndef YYSTYPE
typedef union {
// qui vanno definiti i vari nodi dell'albero sintattico
  Symbol symbol;
/*  Boolean boolean;
  Program program;
  Class_ class_;
  Classes classes;
  Feature feature;
  Features features;
  Formal formal;
  Formals formals;
  Case case_;
  Cases cases;
  Expression expression;
  Expressions expressions; */
  char *error_msg; 
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

extern YYSTYPE normeAntisismiche_yylval;

#endif /* not BISON_NORMEANTISISMICHE_TAB_H */
#endif
