/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "xpl.y" /* yacc.c:339  */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "nodetype.h"
extern FILE *yyin;
extern int regCount;
extern FILE *fp;

//For Debugging
    int lineNumber=1;


//For the current Local symbol Table
    struct Lsymbol * currLocalTable;
//For the Global symbol Table of current function
    struct Gsymbol * currFunction;

//For Variable Declarations
    struct variableDecl * makeVariableNode(char * name,int size);
    struct argumentDecl * makeArgumentNode(char * name);

//Yacc Basic Functions

    int yylex(void); 
    void yyerror(char *s); 
    void outOfMemory();


#line 96 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    START = 258,
    NUMBER = 259,
    VARIABLE = 260,
    READ = 261,
    WRITE = 262,
    IF = 263,
    AND = 264,
    OR = 265,
    NOT = 266,
    TRUE = 267,
    FALSE = 268,
    THEN = 269,
    ELSE = 270,
    ENDIF = 271,
    WHILE = 272,
    DO = 273,
    ENDWHILE = 274,
    END = 275,
    DECL = 276,
    ENDDECL = 277,
    INT = 278,
    MAIN = 279,
    CHAR = 280,
    BOOL = 281,
    RETURN = 282,
    exitcode = 283
  };
#endif
/* Tokens.  */
#define START 258
#define NUMBER 259
#define VARIABLE 260
#define READ 261
#define WRITE 262
#define IF 263
#define AND 264
#define OR 265
#define NOT 266
#define TRUE 267
#define FALSE 268
#define THEN 269
#define ELSE 270
#define ENDIF 271
#define WHILE 272
#define DO 273
#define ENDWHILE 274
#define END 275
#define DECL 276
#define ENDDECL 277
#define INT 278
#define MAIN 279
#define CHAR 280
#define BOOL 281
#define RETURN 282
#define exitcode 283

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 32 "xpl.y" /* yacc.c:355  */
 
    int iValue;                            /* integer value */ 
    char * strPointer;                     /* symbol table index */ 
    struct nodeTypeTag * nPtr;             /* node pointer */ 
    struct Gsymbol * IDs;                  /* Global Identfiers */ 
    struct Lsymbol * Locals;               /* Local Identfiers */ 
    struct argList * args;                 /* Arguments for function */ 
    struct argumentDecl *arg;              /* Temporary */
    struct Lsymbol * localVars;            /* Local Variable SymbolTable Head */ 
    struct fArgExpression *fArgExpr;        /* For storing function arguments during function call */

#line 201 "y.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 216 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   381

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  66
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  184

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   283

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    36,    45,     2,
      41,    42,    34,    32,    38,    33,     2,    35,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    37,
      30,    29,    31,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    39,     2,    40,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    43,     2,    44,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    96,    96,   102,   109,   112,   126,   130,   136,   145,
     158,   169,   176,   180,   185,   198,   203,   209,   254,   301,
     304,   311,   326,   331,   357,   385,   388,   393,   403,   413,
     420,   430,   445,   450,   457,   477,   482,   487,   492,   497,
     502,   507,   512,   517,   521,   527,   531,   535,   539,   543,
     547,   551,   555,   559,   563,   567,   571,   576,   580,   585,
     589,   592,   595,   598,   601,   607,   617
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "START", "NUMBER", "VARIABLE", "READ",
  "WRITE", "IF", "AND", "OR", "NOT", "TRUE", "FALSE", "THEN", "ELSE",
  "ENDIF", "WHILE", "DO", "ENDWHILE", "END", "DECL", "ENDDECL", "INT",
  "MAIN", "CHAR", "BOOL", "RETURN", "exitcode", "'='", "'<'", "'>'", "'+'",
  "'-'", "'*'", "'/'", "'%'", "';'", "','", "'['", "']'", "'('", "')'",
  "'{'", "'}'", "'&'", "$accept", "start", "statement_list",
  "decl_statement_list", "decl_statement", "declarations", "declaration",
  "Fdef_list", "Fdef", "Fname", "Farg_list", "Farg", "FargsId",
  "ldecl_statement_list", "ldecl_statement", "ldeclarations",
  "ldeclaration", "statement", "expr", "FcallExpressions", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,    61,
      60,    62,    43,    45,    42,    47,    37,    59,    44,    91,
      93,    40,    41,   123,   125,    38
};
# endif

#define YYPACT_NINF -83

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-83)))

#define YYTABLE_NINF -20

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-20)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -1,    58,    82,    49,    59,    48,    48,     2,   -83,   -83,
     -83,   207,   -83,    28,   -83,    46,    63,   -83,   -83,    87,
     -83,    48,   -83,   -83,   266,   109,   -83,   -19,   -83,    52,
      52,   -83,   -83,     6,     6,   -83,   -83,   -83,    93,   148,
     -83,   158,    69,   110,   -83,   -83,   -83,   -83,     6,   -83,
     -11,    -9,   139,   160,   162,   185,   196,   152,   152,   214,
     214,    51,   -83,    70,   -83,   124,   -83,   154,   217,   -83,
     228,   -83,   214,   -83,   354,   354,   -83,   -10,   193,   234,
     236,   246,    43,   300,   -83,   323,    43,    43,   242,    57,
      43,    43,   -83,   221,    43,   -83,   -83,    43,   271,   247,
     206,   189,   -83,   265,   220,   136,    36,   222,    80,    94,
     108,    43,   -83,   122,   251,    43,    43,    43,   262,    43,
      43,    43,    43,    43,    43,    43,   -83,   -83,   -83,   -83,
     281,    43,   277,    43,   278,   302,   301,   150,   -83,    43,
     249,    22,   282,   282,    43,   264,   264,    85,    85,   282,
     282,   -83,    43,   164,   -83,   178,   -83,   354,   354,   -83,
     192,    43,   -83,   264,   235,   279,   280,   296,   327,   -83,
     249,   -83,   287,   288,   354,   289,   304,   -83,   -83,   331,
     -83,   -83,   305,   -83
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     7,     1,
       3,    13,    20,     0,    11,     0,     0,    16,     6,     0,
       8,     0,    22,     9,     0,     0,    10,     0,     2,     0,
       0,    15,    12,     0,     0,    14,    21,    19,     0,     0,
      25,     0,     0,     0,    22,    22,    26,    23,     0,    24,
       0,     0,    27,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    29,     0,    34,     0,    33,     0,     0,    28,
       0,    30,     0,    31,     0,     0,    32,     0,     0,     0,
       0,     0,     0,     0,     5,     0,     0,     0,     0,     0,
       0,     0,    59,    55,     0,    62,    63,     0,     0,     0,
       0,     0,     4,     0,     0,     0,     0,    55,     0,     0,
       0,     0,    54,     0,    56,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    44,    17,    18,    37,
       0,     0,     0,     0,     0,     0,     0,     0,    53,     0,
      66,     0,    60,    61,     0,    49,    50,    45,    46,    47,
      51,    52,     0,     0,    39,     0,    41,     0,     0,    57,
       0,     0,    64,    48,     0,     0,    57,     0,     0,    58,
      65,    38,     0,     0,     0,     0,     0,    40,    42,     0,
      36,    43,     0,    35
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -83,   -83,   -75,   -83,   338,   343,   330,   -83,   -83,    16,
     -18,   -83,   -16,   294,    72,   293,   283,   -82,   -81,   -83
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,    83,     7,     8,    13,    14,    24,    31,    99,
      27,    36,    42,    61,    62,    65,    66,    84,   100,   141
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      85,   102,     1,   102,    33,   104,   105,    34,   108,   109,
     110,    40,    33,   112,    33,    34,   113,    34,    43,    86,
       2,    15,    15,    35,    17,     5,    50,    51,     6,    87,
     137,    53,    52,    54,   140,   142,   143,    15,   145,   146,
     147,   148,   149,   150,   151,    38,    39,    92,    93,     9,
     153,    41,   155,    11,    94,    95,    96,    37,   160,     4,
     161,    92,   107,   163,   162,    20,    21,    12,    94,    95,
      96,   164,    12,    68,    59,   131,    12,    60,   132,    10,
     170,    12,   167,   168,    97,   102,   102,    22,    98,   116,
     117,    25,    70,    59,   116,   117,    60,   102,    97,   179,
      23,    21,    98,   116,   117,     5,    47,    48,     6,   118,
     119,   120,   121,   122,   123,   124,   125,   116,   117,   123,
     124,   125,   134,   118,   119,   120,   121,   122,   123,   124,
     125,   116,   117,    69,    44,    69,   135,   118,   119,   120,
     121,   122,   123,   124,   125,   116,   117,    49,    48,    32,
     136,   118,   119,   120,   121,   122,   123,   124,   125,   116,
     117,    71,    72,    46,   138,   118,   119,   120,   121,   122,
     123,   124,   125,   116,   117,    59,   130,    48,    60,   118,
     119,   120,   121,   122,   123,   124,   125,   116,   117,    45,
     159,    73,    72,   118,   119,   120,   121,   122,   123,   124,
     125,   116,   117,    55,   165,    56,    57,   118,   119,   120,
     121,   122,   123,   124,   125,   116,   117,    58,   166,    64,
      74,   118,   119,   120,   121,   122,   123,   124,   125,   116,
     117,    75,   169,   127,    88,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   116,   117,    19,   106,   -19,   118,
     119,   120,   121,   122,   123,   124,   125,   129,   116,   117,
     111,   133,   -19,   -19,   118,   119,   120,   121,   122,   123,
     124,   125,   171,   116,   117,    89,   114,    90,   118,   119,
     120,   121,   122,   123,   124,   125,    28,    91,   115,    29,
     139,   144,    30,   -20,   -20,   -20,   121,   122,   123,   124,
     125,    77,    78,    79,    80,    77,    78,    79,    80,   128,
     152,   174,   175,    81,   154,   156,   157,    81,   125,   158,
     101,   172,   173,    82,   177,   178,   180,    82,    77,    78,
      79,    80,    77,    78,    79,    80,    77,    78,    79,    80,
      81,   181,   183,   103,    81,    18,   176,   182,    81,    16,
      82,    26,    63,    67,    82,    76,     0,     0,    82,    77,
      78,    79,    80,     0,     0,     0,     0,     0,     0,     0,
       0,    81,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    82
};

static const yytype_int16 yycheck[] =
{
      75,    83,     3,    85,    23,    86,    87,    26,    89,    90,
      91,     5,    23,    94,    23,    26,    97,    26,    34,    29,
      21,     5,     6,    42,    22,    23,    44,    45,    26,    39,
     111,    42,    48,    42,   115,   116,   117,    21,   119,   120,
     121,   122,   123,   124,   125,    29,    30,     4,     5,     0,
     131,    45,   133,     5,    11,    12,    13,     5,   139,     1,
      38,     4,     5,   144,    42,    37,    38,    24,    11,    12,
      13,   152,    24,    22,    23,    39,    24,    26,    42,    20,
     161,    24,   157,   158,    41,   167,   168,    41,    45,     9,
      10,     4,    22,    23,     9,    10,    26,   179,    41,   174,
      37,    38,    45,     9,    10,    23,    37,    38,    26,    29,
      30,    31,    32,    33,    34,    35,    36,     9,    10,    34,
      35,    36,    42,    29,    30,    31,    32,    33,    34,    35,
      36,     9,    10,    61,    41,    63,    42,    29,    30,    31,
      32,    33,    34,    35,    36,     9,    10,    37,    38,    40,
      42,    29,    30,    31,    32,    33,    34,    35,    36,     9,
      10,    37,    38,     5,    42,    29,    30,    31,    32,    33,
      34,    35,    36,     9,    10,    23,    40,    38,    26,    29,
      30,    31,    32,    33,    34,    35,    36,     9,    10,    41,
      40,    37,    38,    29,    30,    31,    32,    33,    34,    35,
      36,     9,    10,    43,    40,    43,    21,    29,    30,    31,
      32,    33,    34,    35,    36,     9,    10,    21,    40,     5,
       3,    29,    30,    31,    32,    33,    34,    35,    36,     9,
      10,     3,    40,    44,    41,    29,    30,    31,    32,    33,
      34,    35,    36,    37,     9,    10,    39,     5,    41,    29,
      30,    31,    32,    33,    34,    35,    36,    37,     9,    10,
      39,    39,    41,    41,    29,    30,    31,    32,    33,    34,
      35,    36,    37,     9,    10,    41,     5,    41,    29,    30,
      31,    32,    33,    34,    35,    36,    20,    41,    41,    23,
      39,    29,    26,    29,    30,    31,    32,    33,    34,    35,
      36,     5,     6,     7,     8,     5,     6,     7,     8,    44,
      29,    15,    16,    17,    37,    37,    14,    17,    36,    18,
      20,    42,    42,    27,    37,    37,    37,    27,     5,     6,
       7,     8,     5,     6,     7,     8,     5,     6,     7,     8,
      17,    37,    37,    20,    17,     7,    19,    16,    17,     6,
      27,    21,    58,    60,    27,    72,    -1,    -1,    27,     5,
       6,     7,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    27
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    21,    47,     1,    23,    26,    49,    50,     0,
      20,     5,    24,    51,    52,    55,    51,    22,    50,    39,
      37,    38,    41,    37,    53,     4,    52,    56,    20,    23,
      26,    54,    40,    23,    26,    42,    57,     5,    55,    55,
       5,    45,    58,    58,    41,    41,     5,    37,    38,    37,
      56,    56,    58,    42,    42,    43,    43,    21,    21,    23,
      26,    59,    60,    59,     5,    61,    62,    61,    22,    60,
      22,    37,    38,    37,     3,     3,    62,     5,     6,     7,
       8,    17,    27,    48,    63,    48,    29,    39,    41,    41,
      41,    41,     4,     5,    11,    12,    13,    41,    45,    55,
      64,    20,    63,    20,    64,    64,     5,     5,    64,    64,
      64,    39,    64,    64,     5,    41,     9,    10,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    44,    44,    37,
      40,    39,    42,    39,    42,    42,    42,    64,    42,    39,
      64,    65,    64,    64,    29,    64,    64,    64,    64,    64,
      64,    64,    29,    64,    37,    64,    37,    14,    18,    40,
      64,    38,    42,    64,    64,    40,    40,    48,    48,    40,
      64,    37,    42,    42,    15,    16,    19,    37,    37,    48,
      37,    37,    16,    37
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    47,    48,    48,    49,    49,    50,    50,
      51,    51,    52,    52,    52,    53,    53,    54,    54,    55,
      55,    56,    56,    57,    57,    58,    58,    58,    59,    59,
      60,    60,    61,    61,    62,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    65,    65
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     3,     2,     1,     2,     1,     3,     3,
       3,     1,     4,     1,     4,     2,     0,    13,    13,     1,
       1,     2,     0,     3,     3,     1,     2,     3,     2,     1,
       3,     3,     3,     1,     1,    10,     8,     4,     7,     5,
       8,     5,     8,     8,     3,     3,     3,     3,     4,     3,
       3,     3,     3,     3,     2,     1,     2,     4,     5,     1,
       3,     3,     1,     1,     4,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 97 "xpl.y" /* yacc.c:1646  */
    {
                                            printAllVariables();
                                            return 0;
                                        }
#line 1449 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 102 "xpl.y" /* yacc.c:1646  */
    {
                                            printf("ERROR\n");
                                            exit(0);
                                        }
#line 1458 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 109 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = makeOperationNode('S', 2, (yyvsp[-1].nPtr), (yyvsp[0].nPtr));
                                        }
#line 1466 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 112 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = (yyvsp[0].nPtr);
                                        }
#line 1474 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 127 "xpl.y" /* yacc.c:1646  */
    {
                                            
                                        }
#line 1482 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 130 "xpl.y" /* yacc.c:1646  */
    {
                                            
                                        }
#line 1490 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 137 "xpl.y" /* yacc.c:1646  */
    {
                                            struct typeTable * typeTableTuple;
                                            char *dataType;
                                            dataType = copyString("int");
                                            typeTableTuple = getTypeTuple(dataType);
                                            installAllVariables((yyvsp[-1].IDs),typeTableTuple);
                                        }
#line 1502 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 146 "xpl.y" /* yacc.c:1646  */
    {
                                            struct typeTable * typeTableTuple;
                                            char *dataType;
                                            dataType = copyString("boolean");
                                            typeTableTuple = getTypeTuple(dataType);
                                            installAllVariables((yyvsp[-1].IDs),typeTableTuple);
                                        }
#line 1514 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 159 "xpl.y" /* yacc.c:1646  */
    {
                                            struct Gsymbol * head;
                                            head = (yyvsp[-2].IDs);
                                            while(head->next){
                                                head = head->next;
                                            }
                                            head->next = (yyvsp[0].IDs);
                                            (yyvsp[0].IDs)->next = NULL;
                                            (yyval.IDs) = (yyvsp[-2].IDs);
                                        }
#line 1529 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 170 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.IDs) = (yyvsp[0].IDs);
                                        }
#line 1537 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 177 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.IDs) = installVariable((yyvsp[-3].strPointer),NULL,(yyvsp[-1].iValue));
                                        }
#line 1545 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 181 "xpl.y" /* yacc.c:1646  */
    {
                                            int size = 1;
                                            (yyval.IDs) = installVariable((yyvsp[0].strPointer),NULL,size);
                                        }
#line 1554 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 185 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.IDs) = installFunction((yyvsp[-3].strPointer),(yyvsp[-1].args),NULL,NULL);
                                        }
#line 1562 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 199 "xpl.y" /* yacc.c:1646  */
    {

                                        }
#line 1570 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 203 "xpl.y" /* yacc.c:1646  */
    {

                                        }
#line 1578 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 210 "xpl.y" /* yacc.c:1646  */
    {
                                            struct typeTable * typeTableTuple;
                                            char * dataType;
                                            dataType = copyString("int");
                                            typeTableTuple = getTypeTuple(dataType);
                                            if(strcmp((yyvsp[-11].strPointer),"MAIN") == 0){
                                                installFunction((yyvsp[-11].strPointer),NULL,typeTableTuple,NULL);
                                            }
                                            struct Gsymbol * symbolTableEntry;
                                            symbolTableEntry = getSymbolTableTuple((yyvsp[-11].strPointer));
                                            if(symbolTableEntry != NULL){
                                                symbolTableEntry->lsymbols = (yyvsp[-5].localVars);//To link local symbols
                                                writeBindingsAndArgs(symbolTableEntry->lsymbols,(yyvsp[-9].args));
                                            }
                                            else{
                                                printf("Undeclared Function %s",(yyvsp[-11].strPointer));
                                                return 0;
                                            }
                                            if(!isCorrectDeclaration((yyvsp[-9].args),symbolTableEntry->args)){
                                                printf("Invalid Arguments for Function %s\n",(yyvsp[-11].strPointer));
                                                return 0;
                                            }
                                            if(!hasReturnState((yyvsp[-2].nPtr))){
                                                printf("No return statement for Function %s\n",(yyvsp[-11].strPointer));
                                                return 0;
                                            }
                                            //printAllVariables();
                                            //installFunction($2,$4,typeTableTuple,$8);
                                            currLocalTable = symbolTableEntry->lsymbols;
                                            currFunction   = symbolTableEntry;
                                            
                                            if(analyse((yyvsp[-2].nPtr))){
                                                fprintf(fp,"MOV R0, R0//\tFunction %s Begins here\n",(yyvsp[-11].strPointer));
                                                fprintf(fp,"%s:\n",(yyvsp[-11].strPointer));
                                                fprintf(fp,"PUSH BP\n");
                                                fprintf(fp,"MOV BP,SP\n");
                                                pushForLocalVariables(currLocalTable);
                                                evaluate((yyvsp[-2].nPtr));
                                                fprintf(fp,"MOV R0, R0//\tFunction %s ends here\n",(yyvsp[-11].strPointer));
                                            }
                                            else{
                                                printf("ERROR in Function %s\n",(yyvsp[-11].strPointer));
                                            }
                                        }
#line 1627 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 255 "xpl.y" /* yacc.c:1646  */
    {
                                            struct typeTable * typeTableTuple;
                                            char * dataType;
                                            dataType = copyString("boolean");
                                            typeTableTuple = getTypeTuple(dataType);
                                            if(strcmp((yyvsp[-11].strPointer),"MAIN") == 0){
                                                installFunction((yyvsp[-11].strPointer),NULL,typeTableTuple,NULL);
                                            }
                                            struct Gsymbol * symbolTableEntry;
                                            symbolTableEntry = getSymbolTableTuple((yyvsp[-11].strPointer));
                                            if(symbolTableEntry != NULL){
                                                symbolTableEntry->lsymbols = (yyvsp[-5].localVars);//To link local symbols
                                                writeBindingsAndArgs(symbolTableEntry->lsymbols,(yyvsp[-9].args));
                                            }
                                            else{
                                                printf("Undeclared Function %s",(yyvsp[-11].strPointer));
                                                return 0;
                                            }
                                            if(!isCorrectDeclaration((yyvsp[-9].args),symbolTableEntry->args)){
                                                printf("Invalid Arguments for Function %s\n",(yyvsp[-11].strPointer));
                                                return 0;
                                            }
                                            if(!hasReturnState((yyvsp[-2].nPtr))){
                                                printf("No return statement for Function %s\n",(yyvsp[-11].strPointer));
                                                return 0;
                                            }
                                            //printAllVariables();
                                            //installFunction($2,$4,typeTableTuple,$8);
                                            currLocalTable = symbolTableEntry->lsymbols;
                                            currFunction   = symbolTableEntry;
                                            
                                            if(analyse((yyvsp[-2].nPtr))){
                                                fprintf(fp,"MOV R0, R0//\tFunction %s Begins here\n",(yyvsp[-11].strPointer));
                                                fprintf(fp,"%s:\n",(yyvsp[-11].strPointer));
                                                fprintf(fp,"PUSH BP\n");
                                                fprintf(fp,"MOV BP,SP\n");
                                                pushForLocalVariables(currLocalTable);
                                                evaluate((yyvsp[-2].nPtr));
                                                fprintf(fp,"MOV R0, R0//\tFunction %s ends here\n",(yyvsp[-11].strPointer));
                                            }
                                            else{
                                                printf("ERROR in Function %s\n",(yyvsp[-11].strPointer));
                                            }
                                        }
#line 1676 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 301 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.strPointer) = (yyvsp[0].strPointer);
                                        }
#line 1684 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 304 "xpl.y" /* yacc.c:1646  */
    {
                                            char *fnName;
                                            fnName = copyString("MAIN");
                                            (yyval.strPointer) = fnName;
                                        }
#line 1694 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 312 "xpl.y" /* yacc.c:1646  */
    {
                                            struct argList * arg;
                                            arg = (yyvsp[-1].args);
                                            if(arg == NULL){
                                                (yyval.args) = (yyvsp[0].args);
                                            }
                                            else{
                                                while(arg->next){
                                                    arg = arg->next;
                                                }
                                                arg->next = (yyvsp[0].args);
                                                (yyval.args) = (yyvsp[-1].args);
                                            }
                                        }
#line 1713 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 326 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.args) = NULL;
                                        }
#line 1721 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 332 "xpl.y" /* yacc.c:1646  */
    {
                                            struct typeTable * typeTableTuple;
                                            char *dataType;
                                            dataType = copyString("int");
                                            typeTableTuple = getTypeTuple(dataType);
                                            struct argList * argument;
                                            argument = NULL;
                                            while((yyvsp[-1].arg)){
                                                if(argument){
                                                    argument->next = saveFarg((yyvsp[-1].arg)->name,typeTableTuple);
                                                    if((yyvsp[-1].arg)->isRef == 1){
                                                        argument->next->isRef = 1;
                                                    }
                                                    argument       = argument->next;
                                                }
                                                else{
                                                    argument = saveFarg((yyvsp[-1].arg)->name,typeTableTuple);
                                                    if((yyvsp[-1].arg)->isRef == 1){
                                                        argument->isRef = 1;
                                                    }
                                                    (yyval.args)       = argument;
                                                }
                                                (yyvsp[-1].arg)=(yyvsp[-1].arg)->next;
                                            }
                                        }
#line 1751 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 358 "xpl.y" /* yacc.c:1646  */
    {
                                            struct typeTable * typeTableTuple;
                                            char *dataType;
                                            dataType = copyString("boolean");
                                            typeTableTuple = getTypeTuple(dataType);
                                            struct argList * argument;
                                            argument = NULL;
                                            while((yyvsp[-1].arg)){
                                                if(argument){
                                                    argument->next = saveFarg((yyvsp[-1].arg)->name,typeTableTuple);
                                                    if((yyvsp[-1].arg)->isRef == 1){
                                                        argument->next->isRef = 1;
                                                    }
                                                    argument       = argument->next;
                                                }
                                                else{
                                                    argument = saveFarg((yyvsp[-1].arg)->name,typeTableTuple);
                                                    if((yyvsp[-1].arg)->isRef == 1){
                                                        argument->isRef = 1;
                                                    }
                                                    (yyval.args)       = argument;
                                                }
                                                (yyvsp[-1].arg)=(yyvsp[-1].arg)->next;
                                            }
                                        }
#line 1781 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 385 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.arg) = makeArgumentNode((yyvsp[0].strPointer));//for saving arguments whose type is unknown(For temporary use)
                                        }
#line 1789 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 389 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.arg) = makeArgumentNode((yyvsp[0].strPointer));//for saving arguments whose type is unknown(For temporary use)
                                            (yyval.arg)->isRef = 1;
                                        }
#line 1798 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 393 "xpl.y" /* yacc.c:1646  */
    {
                                            struct argumentDecl * poi;
                                            poi = (yyvsp[-2].arg);
                                            while(poi->next){
                                                poi = poi->next;
                                            }
                                            poi->next = (yyvsp[0].arg);
                                        }
#line 1811 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 404 "xpl.y" /* yacc.c:1646  */
    {
                                            struct Lsymbol * lsymbolHead;
                                            lsymbolHead = (yyvsp[-1].localVars);
                                            while(lsymbolHead->next){
                                                lsymbolHead = lsymbolHead->next;
                                            }
                                            lsymbolHead->next = (yyvsp[0].localVars);
                                            (yyval.localVars) = (yyvsp[-1].localVars);
                                        }
#line 1825 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 414 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.localVars) =(yyvsp[0].localVars);
                                        }
#line 1833 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 421 "xpl.y" /* yacc.c:1646  */
    {
                                            struct typeTable * typeTableTuple;
                                            char *dataType;
                                            dataType = copyString("int");
                                            typeTableTuple = getTypeTuple(dataType);
                                            (yyval.localVars) = installAllLocalVariables((yyvsp[-1].Locals),typeTableTuple);
                                            //freeVarList($2);
                                        }
#line 1846 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 431 "xpl.y" /* yacc.c:1646  */
    {
                                            struct typeTable * typeTableTuple;
                                            char *dataType;
                                            dataType = copyString("boolean");
                                            typeTableTuple = getTypeTuple(dataType);
                                            (yyval.localVars) = installAllLocalVariables((yyvsp[-1].Locals),typeTableTuple);
                                            //freeVarList($2);
                                        }
#line 1859 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 446 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyvsp[0].Locals)->next = (yyvsp[-2].Locals);
                                            (yyval.Locals) = (yyvsp[0].Locals);
                                        }
#line 1868 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 451 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.Locals) = (yyvsp[0].Locals);
                                        }
#line 1876 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 458 "xpl.y" /* yacc.c:1646  */
    {
                                            int size = 1;
                                            (yyval.Locals) = installLocalVariable((yyvsp[0].strPointer),NULL,size);
                                        }
#line 1885 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 478 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = makeOperationNode('I', 3, (yyvsp[-7].nPtr), (yyvsp[-4].nPtr), (yyvsp[-2].nPtr));
                                        }
#line 1893 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 483 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = makeOperationNode('I', 2, (yyvsp[-5].nPtr), (yyvsp[-2].nPtr));
                                        }
#line 1901 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 488 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = makeOperationNode('=', 2, makeIdNode((yyvsp[-3].strPointer),makeConstantNode(0,1)), (yyvsp[-1].nPtr));
                                        }
#line 1909 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 493 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = makeOperationNode('=', 2, makeIdNode((yyvsp[-6].strPointer),(yyvsp[-4].nPtr)), (yyvsp[-1].nPtr));
                                        }
#line 1917 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 498 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = makeOperationNode('R', 1, makeIdNode((yyvsp[-2].strPointer),makeConstantNode(0,1)));
                                        }
#line 1925 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 503 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = makeOperationNode('R', 1, makeIdNode((yyvsp[-5].strPointer),(yyvsp[-3].nPtr)));
                                        }
#line 1933 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 508 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = makeOperationNode('W', 1, (yyvsp[-2].nPtr));
                                        }
#line 1941 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 513 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = makeOperationNode('W', 1, makeIdNode((yyvsp[-5].strPointer),(yyvsp[-3].nPtr)));
                                        }
#line 1949 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 518 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = makeOperationNode('L', 2, (yyvsp[-5].nPtr), (yyvsp[-2].nPtr));
                                        }
#line 1957 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 521 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = makeOperationNode('^',1,(yyvsp[-1].nPtr));
                                        }
#line 1965 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 528 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = makeOperationNode('+', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));
                                        }
#line 1973 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 532 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = makeOperationNode('-', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));
                                        }
#line 1981 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 536 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = makeOperationNode('*', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));
                                        }
#line 1989 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 540 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = makeOperationNode('~', 2, (yyvsp[-3].nPtr), (yyvsp[0].nPtr));
                                        }
#line 1997 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 544 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = makeOperationNode('<', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));
                                        }
#line 2005 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 548 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = makeOperationNode('>', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));
                                        }
#line 2013 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 552 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = makeOperationNode('/', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));
                                        }
#line 2021 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 556 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = makeOperationNode('%', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));
                                        }
#line 2029 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 560 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = (yyvsp[-1].nPtr);
                                        }
#line 2037 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 564 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = makeOperationNode('!', 1, (yyvsp[0].nPtr));
                                        }
#line 2045 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 568 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = makeIdNode((yyvsp[0].strPointer),makeConstantNode(0,1));
                                        }
#line 2053 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 572 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = makeIdNode((yyvsp[0].strPointer),makeConstantNode(0,1));
                                            (yyval.nPtr)->id.isRef = 1;
                                        }
#line 2062 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 577 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = makeIdNode((yyvsp[-3].strPointer),(yyvsp[-1].nPtr));
                                        }
#line 2070 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 581 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = makeIdNode((yyvsp[-3].strPointer),(yyvsp[-1].nPtr));
                                            (yyval.nPtr)->id.isRef = 1;
                                        }
#line 2079 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 586 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = makeConstantNode((yyvsp[0].iValue),1);
                                        }
#line 2087 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 589 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = makeOperationNode('&',2,(yyvsp[-2].nPtr),(yyvsp[0].nPtr));
                                        }
#line 2095 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 592 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = makeOperationNode('|',2,(yyvsp[-2].nPtr),(yyvsp[0].nPtr));
                                        }
#line 2103 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 595 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = makeConstantNode(1,3);
                                        }
#line 2111 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 598 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = makeConstantNode(0,3);
                                        }
#line 2119 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 602 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = makeFunctionNode((yyvsp[-3].strPointer),(yyvsp[-1].fArgExpr));
                                        }
#line 2127 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 608 "xpl.y" /* yacc.c:1646  */
    {
                                            struct fArgExpression *head;
                                            head = (yyvsp[-2].fArgExpr);
                                            while(head->next){
                                                head = head->next;
                                            }
                                            head->next = makeFargNode((yyvsp[0].nPtr));
                                            (yyval.fArgExpr) = (yyvsp[-2].fArgExpr);
                                        }
#line 2141 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 617 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.fArgExpr) = makeFargNode((yyvsp[0].nPtr));
                                        }
#line 2149 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2153 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
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
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 622 "xpl.y" /* yacc.c:1906  */



// Basic Function

        char * copyString(char * source){
            char * destination;
            int size = strlen(source);
            destination = malloc(size);
            strcpy(destination,source);
        }

//For Variable Declarations
        //Variable node is a temporary data structure for creating symbol table entries
        struct variableDecl * makeVariableNode(char * name,int size){
            struct variableDecl * varNode;
            varNode = malloc(sizeof(struct variableDecl));
            if(!varNode){
                outOfMemory();
            }
            varNode->name = copyString(name);
            varNode->size = size;
            varNode->next = NULL;
            return varNode;
        }

//For Argument Declarations
        //Argument node is a temporary data structure for creating symbol table entries
        struct argumentDecl * makeArgumentNode(char * name){
            struct argumentDecl * argNode;
            argNode = malloc(sizeof(struct argumentDecl));
            if(!argNode){
                outOfMemory();
            }
            argNode->name = copyString(name);
            argNode->next = NULL;
            argNode->isRef= 0;
            return argNode;
        }


//Expression Tree Related Functions






//BASIC YACC Functions 

        
        void yyerror(char *error)
        {
            printf("Error (%s) %d\n",error,lineNumber);
            exit(1);
        }
        void readInput(){
            yyparse();
        }
        void readFile(char *filename){
            FILE *sourceCode = fopen(filename, "r");
            extern FILE *yyin;
            yyin = sourceCode;
            yyparse();
        }
        void outOfMemory(){
            yyerror("Out of Memory");
        }

//Main Function

    int main(int argc,char *argv[])
    {
        makeBasicTypeTable();
        fp=fopen("temp.xsm","wb");
        fprintf(fp,"START\n");
        fprintf(fp,"MOV SP, 1535\n");
        fprintf(fp,"MOV BP, 1535\n");
        fprintf(fp,"CALL MAIN\n");
        fprintf(fp,"HALT\n");
        if(argc>1){
                readFile(argv[1]);
        }
        else{
            readInput();
        }
        fprintf(fp,"HALT\n");
        return 1;
    }
    
