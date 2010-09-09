/* A Bison parser, made by GNU Bison 2.4.3.  */

/* Skeleton implementation for Bison LALR(1) parsers in C++
   
      Copyright (C) 2002, 2003, 2004, 2005, 2006, 2007, 2008, 2009, 2010 Free
   Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* First part of user declarations.  */

/* Line 311 of lalr1.cc  */
#line 4 "normeantisismiche.yy"
 /*** C/C++ Declarations ***/
#include "Struttura.h"
#include <stdio.h>
#define ELEMENT $<element>


/* Line 311 of lalr1.cc  */
#line 47 "normeantisismiche.tab.cc"


#include "normeantisismiche.tab.hh"

/* User implementation prologue.  */

/* Line 317 of lalr1.cc  */
#line 93 "normeantisismiche.yy"




/* Line 317 of lalr1.cc  */
#line 61 "normeantisismiche.tab.cc"
/* Unqualified %code blocks.  */

/* Line 318 of lalr1.cc  */
#line 31 "normeantisismiche.yy"

	// Prototype for the yylex function
	static int yylex(Earthquake::BisonParser::semantic_type * yylval, Earthquake::FlexScanner &scanner);
	



/* Line 318 of lalr1.cc  */
#line 74 "normeantisismiche.tab.cc"

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* FIXME: INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#define YYUSE(e) ((void) (e))

/* Enable debugging if requested.  */
#if YYDEBUG

/* A pseudo ostream that takes yydebug_ into account.  */
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)	\
do {							\
  if (yydebug_)						\
    {							\
      *yycdebug_ << Title << ' ';			\
      yy_symbol_print_ ((Type), (Value), (Location));	\
      *yycdebug_ << std::endl;				\
    }							\
} while (false)

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug_)				\
    yy_reduce_print_ (Rule);		\
} while (false)

# define YY_STACK_PRINT()		\
do {					\
  if (yydebug_)				\
    yystack_print_ ();			\
} while (false)

#else /* !YYDEBUG */

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_REDUCE_PRINT(Rule)
# define YY_STACK_PRINT()

#endif /* !YYDEBUG */

#define yyerrok		(yyerrstatus_ = 0)
#define yyclearin	(yychar = yyempty_)

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


/* Line 380 of lalr1.cc  */
#line 12 "normeantisismiche.yy"
namespace Earthquake {

/* Line 380 of lalr1.cc  */
#line 142 "normeantisismiche.tab.cc"
#if YYERROR_VERBOSE

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  BisonParser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr = "";
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              /* Fall through.  */
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

#endif

  /// Build a parser object.
  BisonParser::BisonParser (Earthquake::FlexScanner &scanner_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      scanner (scanner_yyarg)
  {
  }

  BisonParser::~BisonParser ()
  {
  }

#if YYDEBUG
  /*--------------------------------.
  | Print this symbol on YYOUTPUT.  |
  `--------------------------------*/

  inline void
  BisonParser::yy_symbol_value_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yyvaluep);
    switch (yytype)
      {
         default:
	  break;
      }
  }


  void
  BisonParser::yy_symbol_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    *yycdebug_ << (yytype < yyntokens_ ? "token" : "nterm")
	       << ' ' << yytname_[yytype] << " ("
	       << *yylocationp << ": ";
    yy_symbol_value_print_ (yytype, yyvaluep, yylocationp);
    *yycdebug_ << ')';
  }
#endif

  void
  BisonParser::yydestruct_ (const char* yymsg,
			   int yytype, semantic_type* yyvaluep, location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yymsg);
    YYUSE (yyvaluep);

    YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

    switch (yytype)
      {
        case 6: /* "APERTURA" */

/* Line 480 of lalr1.cc  */
#line 89 "normeantisismiche.yy"
	{ delete (yyvaluep->apertura); };

/* Line 480 of lalr1.cc  */
#line 249 "normeantisismiche.tab.cc"
	break;
      case 12: /* "struttura" */

/* Line 480 of lalr1.cc  */
#line 89 "normeantisismiche.yy"
	{ delete (yyvaluep->struttura); };

/* Line 480 of lalr1.cc  */
#line 258 "normeantisismiche.tab.cc"
	break;
      case 13: /* "piani" */

/* Line 480 of lalr1.cc  */
#line 89 "normeantisismiche.yy"
	{ delete (yyvaluep->piani); };

/* Line 480 of lalr1.cc  */
#line 267 "normeantisismiche.tab.cc"
	break;

	default:
	  break;
      }
  }

  void
  BisonParser::yypop_ (unsigned int n)
  {
    yystate_stack_.pop (n);
    yysemantic_stack_.pop (n);
    yylocation_stack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  BisonParser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  BisonParser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  BisonParser::debug_level_type
  BisonParser::debug_level () const
  {
    return yydebug_;
  }

  void
  BisonParser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif

  int
  BisonParser::parse ()
  {
    /// Lookahead and lookahead in internal form.
    int yychar = yyempty_;
    int yytoken = 0;

    /* State.  */
    int yyn;
    int yylen = 0;
    int yystate = 0;

    /* Error handling.  */
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// Semantic value of the lookahead.
    semantic_type yylval;
    /// Location of the lookahead.
    location_type yylloc;
    /// The locations where the error started and ended.
    location_type yyerror_range[3];

    /// $$.
    semantic_type yyval;
    /// @$.
    location_type yyloc;

    int yyresult;

    YYCDEBUG << "Starting parse" << std::endl;


    /* Initialize the stacks.  The initial state will be pushed in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystate_stack_ = state_stack_type (0);
    yysemantic_stack_ = semantic_stack_type (0);
    yylocation_stack_ = location_stack_type (0);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* New state.  */
  yynewstate:
    yystate_stack_.push (yystate);
    YYCDEBUG << "Entering state " << yystate << std::endl;

    /* Accept?  */
    if (yystate == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    /* Backup.  */
  yybackup:

    /* Try to take a decision without lookahead.  */
    yyn = yypact_[yystate];
    if (yyn == yypact_ninf_)
      goto yydefault;

    /* Read a lookahead token.  */
    if (yychar == yyempty_)
      {
	YYCDEBUG << "Reading a token: ";
	yychar = yylex (&yylval, scanner);
      }


    /* Convert token to internal form.  */
    if (yychar <= yyeof_)
      {
	yychar = yytoken = yyeof_;
	YYCDEBUG << "Now at end of input." << std::endl;
      }
    else
      {
	yytoken = yytranslate_ (yychar);
	YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
      }

    /* If the proper action on seeing token YYTOKEN is to reduce or to
       detect an error, take that action.  */
    yyn += yytoken;
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yytoken)
      goto yydefault;

    /* Reduce or error.  */
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
	if (yyn == 0 || yyn == yytable_ninf_)
	goto yyerrlab;
	yyn = -yyn;
	goto yyreduce;
      }

    /* Shift the lookahead token.  */
    YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

    /* Discard the token being shifted.  */
    yychar = yyempty_;

    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* Count tokens shifted since error; after three, turn off error
       status.  */
    if (yyerrstatus_)
      --yyerrstatus_;

    yystate = yyn;
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystate];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    /* If YYLEN is nonzero, implement the default value of the action:
       `$$ = $1'.  Otherwise, use the top of the stack.

       Otherwise, the following line sets YYVAL to garbage.
       This behavior is undocumented and Bison
       users should not rely upon it.  */
    if (yylen)
      yyval = yysemantic_stack_[yylen - 1];
    else
      yyval = yysemantic_stack_[0];

    {
      slice<location_type, location_stack_type> slice (yylocation_stack_, yylen);
      YYLLOC_DEFAULT (yyloc, slice, yylen);
    }
    YY_REDUCE_PRINT (yyn);
    switch (yyn)
      {
	  case 2:

/* Line 678 of lalr1.cc  */
#line 104 "normeantisismiche.yy"
    {
           cout << "STRUTTURAAAAAAHHHHH\n\n";
		   //Struttura's contructor checks the <contains, not intersect> property
	       (yyval.struttura) = new Struttura(*((yysemantic_stack_[(2) - (1)].piani)), ((yysemantic_stack_[(2) - (2)].ap))->getList());
		   list<token_*> maschi = (yyval.struttura)->calcolaMaschi();
		   try{
				(yyval.struttura)->verificaProprietaMaschio(maschi);
		   }
		   catch(PropertyViolationException *ex) {
				cout << "I maschi non rispettano le proprieta \n";
		   }
		}
    break;

  case 3:

/* Line 678 of lalr1.cc  */
#line 120 "normeantisismiche.yy"
    {
           		printf("INTERPIANI %d %f %f %f %f",(yysemantic_stack_[(2) - (2)].element)->type,(yysemantic_stack_[(2) - (2)].element)->x1,
           			(yysemantic_stack_[(2) - (2)].element)->y1,(yysemantic_stack_[(2) - (2)].element)->x2,(yysemantic_stack_[(2) - (2)].element)->y2);
				list<Interpiano> interpianiList = (yysemantic_stack_[(2) - (1)].piani)->getInterpiani();
				interpianiList.push_back(*((yysemantic_stack_[(2) - (2)].interpiano)));
				(yyval.piani) = new Piani(interpianiList, (yysemantic_stack_[(2) - (1)].piani)->getParete());
	       }
    break;

  case 4:

/* Line 678 of lalr1.cc  */
#line 129 "normeantisismiche.yy"
    {
			printf("PIANI_pr2: %d %.1f %f %f %f",(yysemantic_stack_[(1) - (1)].element)->type,
				(yysemantic_stack_[(1) - (1)].element)->x1,(yysemantic_stack_[(1) - (1)].element)->y1,(yysemantic_stack_[(1) - (1)].element)->x2,
			(yysemantic_stack_[(1) - (1)].element)->y2);
				(yyval.piani) = new Piani((yysemantic_stack_[(1) - (1)].element));
			}
    break;

  case 5:

/* Line 678 of lalr1.cc  */
#line 139 "normeantisismiche.yy"
    {
				cout << "INTERPIANI_pr1: " << (yysemantic_stack_[(2) - (1)].element)->type << " || " << (yysemantic_stack_[(2) - (1)].element)->x1 << " || " << (yysemantic_stack_[(2) - (1)].element)->y1 << (yysemantic_stack_[(2) - (2)].element)->x2 << " || " << (yysemantic_stack_[(2) - (1)].element)->y2
					<< "\n-" << (yysemantic_stack_[(2) - (2)].element)->type << " || " << (yysemantic_stack_[(2) - (2)].element)->x1 << " || " << (yysemantic_stack_[(2) - (2)].element)->y1 << (yysemantic_stack_[(2) - (2)].element)->x2 << " || " << (yysemantic_stack_[(2) - (2)].element)->y2 << "\n\n";

					(yyval.interpiano) = new Interpiano((yysemantic_stack_[(2) - (1)].element), (yysemantic_stack_[(2) - (2)].element));
				}
    break;

  case 6:

/* Line 678 of lalr1.cc  */
#line 146 "normeantisismiche.yy"
    {
				cout << "INTERPIANI_pr2: " << (yysemantic_stack_[(1) - (1)].element)->type << " || " << (yysemantic_stack_[(1) - (1)].element)->x1 << " || " << (yysemantic_stack_[(1) - (1)].element)->y1 << (yysemantic_stack_[(1) - (1)].element)->x2 << " || " << (yysemantic_stack_[(1) - (1)].element)->y2 <<"\n\n";
				
					(yyval.interpiano) = new Interpiano((yysemantic_stack_[(1) - (1)].element));
				}
    break;

  case 7:

/* Line 678 of lalr1.cc  */
#line 155 "normeantisismiche.yy"
    {
				cout << "APERTURA_pr1: " << (yysemantic_stack_[(2) - (2)].element)->type << " || " << (yysemantic_stack_[(2) - (2)].element)->x1 << " || " << (yysemantic_stack_[(2) - (2)].element)->y1 << (yysemantic_stack_[(2) - (2)].element)->x2 << " || " << (yysemantic_stack_[(2) - (2)].element)->y2 <<"\n\n";
				
					((yysemantic_stack_[(2) - (1)].ap))->getList().push_back(*((yysemantic_stack_[(2) - (2)].apertura)));
					(yyval.ap) = (yysemantic_stack_[(2) - (1)].ap);
				}
    break;

  case 8:

/* Line 678 of lalr1.cc  */
#line 162 "normeantisismiche.yy"
    {
				cout << "APERTURA_pr2: " << (yysemantic_stack_[(1) - (1)].element)->type << " || " << (yysemantic_stack_[(1) - (1)].element)->x1 << " || " << (yysemantic_stack_[(1) - (1)].element)->y1 << " || " << (yysemantic_stack_[(1) - (1)].element)->x2 << " || " << (yysemantic_stack_[(1) - (1)].element)->y2 << "\n\n";
				
					list<Apertura> apertureList;
					apertureList.push_back(*((yysemantic_stack_[(1) - (1)].apertura)));
					(yyval.ap) = new Aperture(apertureList);
				}
    break;

  case 9:

/* Line 678 of lalr1.cc  */
#line 173 "normeantisismiche.yy"
    {
			cout << "APERTURA_PR: " << (yysemantic_stack_[(2) - (1)].element)->type << " || " << (yysemantic_stack_[(2) - (1)].element)->x1 << " || " << (yysemantic_stack_[(2) - (1)].element)->y1 << " || " << (yysemantic_stack_[(2) - (1)].element)->x2 << " || " << (yysemantic_stack_[(2) - (1)].element)->y2 
				<< "\n-" << (yysemantic_stack_[(2) - (2)].element)->type << " || " << (yysemantic_stack_[(2) - (2)].element)->x1 << " || " << (yysemantic_stack_[(2) - (2)].element)->y1 << (yysemantic_stack_[(2) - (2)].element)->x2 << " || " << (yysemantic_stack_[(2) - (2)].element)->y2 <<"\n\n";
				(yyval.apertura) = new Apertura((yysemantic_stack_[(2) - (1)].element), (yysemantic_stack_[(2) - (2)].element));
			}
    break;

  case 10:

/* Line 678 of lalr1.cc  */
#line 181 "normeantisismiche.yy"
    {
			cout << "APERTURA: " << APERTURA_ << ": " << (yysemantic_stack_[(5) - (2)].floatVal) << " || " << (yysemantic_stack_[(5) - (3)].floatVal) << " || " << (yysemantic_stack_[(5) - (4)].floatVal) << " || " << (yysemantic_stack_[(5) - (5)].floatVal) << "\n\n";
				token_ * t = (token_ *)malloc(sizeof(token_*));
				t->type = (yysemantic_stack_[(5) - (1)].integerVal);
				t->x1 = (yysemantic_stack_[(5) - (2)].floatVal);
				t->y1 = (yysemantic_stack_[(5) - (3)].floatVal);
				t->x2 = (yysemantic_stack_[(5) - (4)].floatVal);
				t->y2 = (yysemantic_stack_[(5) - (5)].floatVal);
				(yyval.element) = t;
			}
    break;

  case 11:

/* Line 678 of lalr1.cc  */
#line 193 "normeantisismiche.yy"
    {
					//error(@$, "che palleeee\n");
					cout << "NOOOOOO\n";
				}
    break;

  case 12:

/* Line 678 of lalr1.cc  */
#line 198 "normeantisismiche.yy"
    {
					//error(@$, "che palleeee\n");
					cout << "NOOOOOO\n";
				}
    break;

  case 13:

/* Line 678 of lalr1.cc  */
#line 205 "normeantisismiche.yy"
    {
			cout << "ARCHITRAVE: " << ARCHITRAVE_ << ": " << (yysemantic_stack_[(5) - (2)].floatVal) << " || " << (yysemantic_stack_[(5) - (3)].floatVal) << " || " << (yysemantic_stack_[(5) - (4)].floatVal) << " || " << (yysemantic_stack_[(5) - (5)].floatVal) << "\n\n";
			
				token_ * t = (token_ *)malloc(sizeof(token_*));
				t->type = ARCHITRAVE_;
				t->x1 = (yysemantic_stack_[(5) - (2)].floatVal);
				t->y1 = (yysemantic_stack_[(5) - (3)].floatVal);
				t->x2 = (yysemantic_stack_[(5) - (4)].floatVal);
				t->y2 = (yysemantic_stack_[(5) - (5)].floatVal);
				(yyval.element) = t;
			}
    break;

  case 14:

/* Line 678 of lalr1.cc  */
#line 218 "normeantisismiche.yy"
    {
					//error(@$, "che palleeee\n");
					cout << "NOOOOOO\n";
				}
    break;

  case 15:

/* Line 678 of lalr1.cc  */
#line 225 "normeantisismiche.yy"
    {
			cout << "LINEAPIANO: " << ": " << (yysemantic_stack_[(5) - (2)].floatVal) << " || " << (yysemantic_stack_[(5) - (3)].floatVal) << " || " << (yysemantic_stack_[(5) - (4)].floatVal) << " || " << (yysemantic_stack_[(5) - (5)].floatVal) << "\n\n";
			
				token_ * t = (token_ *)malloc(sizeof(token_*));
				t->type = LINEA_PIANO_;
				t->x1 = (yysemantic_stack_[(5) - (2)].floatVal);
				t->x2 = (yysemantic_stack_[(5) - (3)].floatVal);
				t->y1 = (yysemantic_stack_[(5) - (4)].floatVal);
				t->y2 = (yysemantic_stack_[(5) - (5)].floatVal);
				(yyval.element) = t;
			}
    break;

  case 16:

/* Line 678 of lalr1.cc  */
#line 238 "normeantisismiche.yy"
    {
					//error(@$, "che palleeee\n");
					cout << "NOOOOOO\n";
				}
    break;

  case 17:

/* Line 678 of lalr1.cc  */
#line 245 "normeantisismiche.yy"
    {
			//cout << "CORDOLO: " << CORDOLO_ << ": " << $<floatVal>2 << " || " << $<floatVal>3 << " || " << $<floatVal>4 << " || " << $<floatVal>5 << "\n\n";
				token_ * t = (token_ *)malloc(sizeof(token_*));
				t->type = CORDOLO_;
				t->x1 = (yysemantic_stack_[(5) - (2)].floatVal);
				t->x2 = (yysemantic_stack_[(5) - (3)].floatVal);
				t->y1 = (yysemantic_stack_[(5) - (4)].floatVal);
				t->y2 = (yysemantic_stack_[(5) - (5)].floatVal);
				(yyval.element) = t;
			}
    break;

  case 18:

/* Line 678 of lalr1.cc  */
#line 257 "normeantisismiche.yy"
    {
					//error(@$, "che palleeee\n");
					cout << "NOOOOOO\n";
				}
    break;

  case 19:

/* Line 678 of lalr1.cc  */
#line 264 "normeantisismiche.yy"
    {
				token_ * t = (token_ *)malloc(sizeof(token_*));
				t->type = PARETE_;
				t->x1 = (yysemantic_stack_[(5) - (2)].floatVal);
				t->x2 = (yysemantic_stack_[(5) - (3)].floatVal);
				t->y1 = (yysemantic_stack_[(5) - (4)].floatVal);
				t->y2 = (yysemantic_stack_[(5) - (5)].floatVal);
				cout << "PARETEEEEEEEE " << " %.2f" << t->x1 << " " << t->y1 
				<< " " << (yysemantic_stack_[(5) - (4)].floatVal) << " " << (yysemantic_stack_[(5) - (5)].floatVal) << endl;
				(yyval.element) = t;
			}
    break;

  case 20:

/* Line 678 of lalr1.cc  */
#line 277 "normeantisismiche.yy"
    {
					cout << "CCCCCCC\n";
				}
    break;



/* Line 678 of lalr1.cc  */
#line 704 "normeantisismiche.tab.cc"
	default:
          break;
      }
    YY_SYMBOL_PRINT ("-> $$ =", yyr1_[yyn], &yyval, &yyloc);

    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();

    yysemantic_stack_.push (yyval);
    yylocation_stack_.push (yyloc);

    /* Shift the result of the reduction.  */
    yyn = yyr1_[yyn];
    yystate = yypgoto_[yyn - yyntokens_] + yystate_stack_[0];
    if (0 <= yystate && yystate <= yylast_
	&& yycheck_[yystate] == yystate_stack_[0])
      yystate = yytable_[yystate];
    else
      yystate = yydefgoto_[yyn - yyntokens_];
    goto yynewstate;

  /*------------------------------------.
  | yyerrlab -- here on detecting error |
  `------------------------------------*/
  yyerrlab:
    /* If not already recovering from an error, report this error.  */
    if (!yyerrstatus_)
      {
	++yynerrs_;
	error (yylloc, yysyntax_error_ (yystate));
      }

    yyerror_range[1] = yylloc;
    if (yyerrstatus_ == 3)
      {
	/* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

	if (yychar <= yyeof_)
	  {
	  /* Return failure if at end of input.  */
	  if (yychar == yyeof_)
	    YYABORT;
	  }
	else
	  {
	    yydestruct_ ("Error: discarding", yytoken, &yylval, &yylloc);
	    yychar = yyempty_;
	  }
      }

    /* Else will try to reuse lookahead token after shifting the error
       token.  */
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;

    yyerror_range[1] = yylocation_stack_[yylen - 1];
    /* Do not reclaim the symbols of the rule which action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    yystate = yystate_stack_[0];
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;	/* Each real token shifted decrements this.  */

    for (;;)
      {
	yyn = yypact_[yystate];
	if (yyn != yypact_ninf_)
	{
	  yyn += yyterror_;
	  if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
	    {
	      yyn = yytable_[yyn];
	      if (0 < yyn)
		break;
	    }
	}

	/* Pop the current state because it cannot handle the error token.  */
	if (yystate_stack_.height () == 1)
	YYABORT;

	yyerror_range[1] = yylocation_stack_[0];
	yydestruct_ ("Error: popping",
		     yystos_[yystate],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);
	yypop_ ();
	yystate = yystate_stack_[0];
	YY_STACK_PRINT ();
      }

    yyerror_range[2] = yylloc;
    // Using YYLLOC is tempting, but would change the location of
    // the lookahead.  YYLOC is available though.
    YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yyloc);

    /* Shift the error token.  */
    YY_SYMBOL_PRINT ("Shifting", yystos_[yyn],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);

    yystate = yyn;
    goto yynewstate;

    /* Accept.  */
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    /* Abort.  */
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (yychar != yyempty_)
      yydestruct_ ("Cleanup: discarding lookahead", yytoken, &yylval, &yylloc);

    /* Do not reclaim the symbols of the rule which action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (yystate_stack_.height () != 1)
      {
	yydestruct_ ("Cleanup: popping",
		   yystos_[yystate_stack_[0]],
		   &yysemantic_stack_[0],
		   &yylocation_stack_[0]);
	yypop_ ();
      }

    return yyresult;
  }

  // Generate an error message.
  std::string
  BisonParser::yysyntax_error_ (int yystate)
  {
    std::string res;
    YYUSE (yystate);
#if YYERROR_VERBOSE
    int yyn = yypact_[yystate];
    if (yypact_ninf_ < yyn && yyn <= yylast_)
      {
	/* Start YYX at -YYN if negative to avoid negative indexes in
	   YYCHECK.  */
	int yyxbegin = yyn < 0 ? -yyn : 0;

	/* Stay within bounds of both yycheck and yytname.  */
	int yychecklim = yylast_ - yyn + 1;
	int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
	int count = 0;
	for (int x = yyxbegin; x < yyxend; ++x)
	  if (yycheck_[x + yyn] == x && x != yyterror_)
	    ++count;

	// FIXME: This method of building the message is not compatible
	// with internationalization.  It should work like yacc.c does it.
	// That is, first build a string that looks like this:
	// "syntax error, unexpected %s or %s or %s"
	// Then, invoke YY_ on this string.
	// Finally, use the string as a format to output
	// yytname_[tok], etc.
	// Until this gets fixed, this message appears in English only.
	res = "syntax error, unexpected ";
	res += yytnamerr_ (yytname_[tok]);
	if (count < 5)
	  {
	    count = 0;
	    for (int x = yyxbegin; x < yyxend; ++x)
	      if (yycheck_[x + yyn] == x && x != yyterror_)
		{
		  res += (!count++) ? ", expecting " : " or ";
		  res += yytnamerr_ (yytname_[x]);
		}
	  }
      }
    else
#endif
      res = YY_("syntax error");
    return res;
  }


  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
  const signed char BisonParser::yypact_ninf_ = -3;
  const signed char
  BisonParser::yypact_[] =
  {
        17,    -1,     5,    13,    -3,    -3,    -2,    -3,     7,     0,
       1,    -3,    12,    -3,     9,    16,    14,    15,    -3,    18,
      -3,    19,    -3,     2,    -3,     3,    -3,    20,    21,    22,
      23,    -3,    24,    -3,    25,    -3,    26,    27,    28,    29,
      30,    -3,    -3,    -3,    31,    32,    -3,    -3
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned char
  BisonParser::yydefact_[] =
  {
         0,     0,     0,     0,     4,    20,     0,     1,     0,     0,
       0,     3,     0,     8,     0,     6,     0,     0,    16,     0,
      11,     0,     7,     0,     9,     0,     5,     0,     0,     0,
       0,    14,     0,    18,     0,    19,     0,     0,     0,     0,
       0,    12,    15,    10,     0,     0,    13,    17
  };

  /* YYPGOTO[NTERM-NUM].  */
  const signed char
  BisonParser::yypgoto_[] =
  {
        -3,    -3,    -3,    -3,    -3,    33,    -3,    -3,    -3,    -3,
      -3
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const signed char
  BisonParser::yydefgoto_[] =
  {
        -1,     2,     3,    11,    12,    13,    14,    24,    15,    26,
       4
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char BisonParser::yytable_ninf_ = -3;
  const signed char
  BisonParser::yytable_[] =
  {
         5,    18,    20,    31,    33,     7,    16,     6,    19,    21,
      32,    34,    -2,     8,     8,    17,    23,     9,    10,    10,
       1,    25,    27,    28,     0,     0,    29,    30,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,     0,     0,     0,     0,    22
  };

  /* YYCHECK.  */
  const signed char
  BisonParser::yycheck_[] =
  {
         1,     1,     1,     1,     1,     0,     8,     8,     8,     8,
       8,     8,     0,     1,     1,     8,     7,     4,     6,     6,
       3,     5,     8,     8,    -1,    -1,     8,     8,     8,     8,
       8,     8,     8,     8,     8,     8,     8,     8,     8,     8,
       8,    -1,    -1,    -1,    -1,    12
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  BisonParser::yystos_[] =
  {
         0,     3,    12,    13,    21,     1,     8,     0,     1,     4,
       6,    14,    15,    16,    17,    19,     8,     8,     1,     8,
       1,     8,    16,     7,    18,     5,    20,     8,     8,     8,
       8,     1,     8,     1,     8,     8,     8,     8,     8,     8,
       8,     8,     8,     8,     8,     8,     8,     8
  };

#if YYDEBUG
  /* TOKEN_NUMBER_[YYLEX-NUM] -- Internal symbol number corresponding
     to YYLEX-NUM.  */
  const unsigned short int
  BisonParser::yytoken_number_[] =
  {
         0,   256,   257,    37,    59,    43,    44,    65,   111,   113,
     258
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  BisonParser::yyr1_[] =
  {
         0,    11,    12,    13,    13,    14,    14,    15,    15,    16,
      17,    17,    17,    18,    18,    19,    19,    20,    20,    21,
      21
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  BisonParser::yyr2_[] =
  {
         0,     2,     2,     2,     1,     2,     1,     2,     1,     2,
       5,     2,     5,     5,     2,     5,     2,     5,     2,     5,
       2
  };

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const BisonParser::yytname_[] =
  {
    "\"end of file\"", "error", "$undefined", "PARETE", "LINEAPIANO",
  "CORDOLO", "APERTURA", "ARCHITRAVE", "f_const_", "ERROR",
  "\"end of line\"", "$accept", "struttura", "piani", "interpiani",
  "aperture", "apertura_pr", "apertura_tk", "architrave_tk",
  "lineapiano_tk", "cordolo_tk", "parete_tk", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const BisonParser::rhs_number_type
  BisonParser::yyrhs_[] =
  {
        12,     0,    -1,    13,    15,    -1,    13,    14,    -1,    21,
      -1,    19,    20,    -1,    19,    -1,    15,    16,    -1,    16,
      -1,    17,    18,    -1,     6,     8,     8,     8,     8,    -1,
       6,     1,    -1,     1,     8,     8,     8,     8,    -1,     7,
       8,     8,     8,     8,    -1,     7,     1,    -1,     4,     8,
       8,     8,     8,    -1,     4,     1,    -1,     5,     8,     8,
       8,     8,    -1,     5,     1,    -1,     3,     8,     8,     8,
       8,    -1,     3,     1,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned char
  BisonParser::yyprhs_[] =
  {
         0,     0,     3,     6,     9,    11,    14,    16,    19,    21,
      24,    30,    33,    39,    45,    48,    54,    57,    63,    66,
      72
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  BisonParser::yyrline_[] =
  {
         0,   103,   103,   119,   128,   138,   145,   154,   161,   172,
     180,   192,   197,   204,   217,   224,   237,   244,   256,   263,
     276
  };

  // Print the state stack on the debug stream.
  void
  BisonParser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (state_stack_type::const_iterator i = yystate_stack_.begin ();
	 i != yystate_stack_.end (); ++i)
      *yycdebug_ << ' ' << *i;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  BisonParser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    /* Print the symbols being reduced, and their result.  */
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
	       << " (line " << yylno << "):" << std::endl;
    /* The symbols being reduced.  */
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
		       yyrhs_[yyprhs_[yyrule] + yyi],
		       &(yysemantic_stack_[(yynrhs) - (yyi + 1)]),
		       &(yylocation_stack_[(yynrhs) - (yyi + 1)]));
  }
#endif // YYDEBUG

  /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
  BisonParser::token_number_type
  BisonParser::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
    {
           0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     3,     2,     2,
       2,     2,     2,     5,     6,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     4,
       2,     2,     2,     2,     2,     7,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     8,     2,     9,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,    10
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int BisonParser::yyeof_ = 0;
  const int BisonParser::yylast_ = 45;
  const int BisonParser::yynnts_ = 11;
  const int BisonParser::yyempty_ = -2;
  const int BisonParser::yyfinal_ = 7;
  const int BisonParser::yyterror_ = 1;
  const int BisonParser::yyerrcode_ = 256;
  const int BisonParser::yyntokens_ = 11;

  const unsigned int BisonParser::yyuser_token_number_max_ = 258;
  const BisonParser::token_number_type BisonParser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 12 "normeantisismiche.yy"
} // Earthquake

/* Line 1054 of lalr1.cc  */
#line 1151 "normeantisismiche.tab.cc"


/* Line 1056 of lalr1.cc  */
#line 283 "normeantisismiche.yy"
 /*** Additional Code ***/

void Earthquake::BisonParser::error(const Earthquake::BisonParser::location_type &loc, const std::string &msg) {
	std::cerr << "Error: " << msg << std::endl;
}

// Now that we have the Parser declared, we can declare the Scanner and implement
// the yylex function
#include "EarthquakeScanner.h"
static int yylex(Earthquake::BisonParser::semantic_type * yylval, Earthquake::FlexScanner &scanner) {
	return scanner.yylex(yylval);
}

