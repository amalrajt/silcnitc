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
#define INVALID -22
struct fileNodes{
    char * filename;
    struct fileNodes * next;
};
extern FILE *yyin;
extern int regCount;
extern int preprocessed;
extern char * filename;
extern struct fileNodes * fileHeader;
extern FILE *fp;

//extern struct Gsymbol * GsymbolHead;
//For Debugging
    int lineNumber=1;


    void preprocess(char * filename);

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


#line 107 "y.tab.c" /* yacc.c:339  */

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

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    READMEM = 275,
    WRITEMEM = 276,
    END = 277,
    DECL = 278,
    ENDDECL = 279,
    INT = 280,
    MAIN = 281,
    CHAR = 282,
    BOOL = 283,
    RETURN = 284,
    TYPE = 285,
    ENDTYPE = 286,
    exitcode = 287
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
#define READMEM 275
#define WRITEMEM 276
#define END 277
#define DECL 278
#define ENDDECL 279
#define INT 280
#define MAIN 281
#define CHAR 282
#define BOOL 283
#define RETURN 284
#define TYPE 285
#define ENDTYPE 286
#define exitcode 287

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 43 "xpl.y" /* yacc.c:355  */
 
    int iValue;                            /* integer value */ 
    char * strPointer;                     /* symbol table index */ 
    struct nodeTypeTag * nPtr;             /* node pointer */ 
    struct Gsymbol * IDs;                  /* Global Identfiers */ 
    struct Lsymbol * Locals;               /* Local Identfiers */ 
    struct argList * args;                 /* Arguments for function */ 
    struct argumentDecl *arg;              /* Temporary */
    struct Lsymbol * localVars;            /* Local Variable SymbolTable Head */ 
    struct fArgExpression *fArgExpr;        /* For storing function arguments during function call */
    struct typeTable *dataType;        /* For storing function arguments during function call */
    struct Fieldlist * field;

#line 225 "y.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 240 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   532

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  85
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  250

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   287

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    40,    49,     2,
      47,    48,    38,    36,    44,    37,    50,    39,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    43,
      34,    33,    35,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    45,     2,    46,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    41,     2,    42,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   116,   116,   127,   139,   146,   149,   158,   161,   166,
     186,   191,   196,   208,   214,   227,   231,   237,   246,   254,
     269,   280,   287,   291,   296,   310,   314,   321,   375,   423,
     470,   473,   480,   495,   500,   526,   553,   582,   585,   590,
     598,   611,   621,   628,   638,   648,   664,   669,   676,   685,
     690,   695,   701,   706,   711,   716,   721,   725,   728,   736,
     740,   744,   748,   752,   756,   760,   764,   768,   772,   776,
     779,   784,   789,   794,   798,   803,   807,   810,   813,   816,
     819,   826,   829,   834,   850,   853
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "START", "NUMBER", "VARIABLE", "READ",
  "WRITE", "IF", "AND", "OR", "NOT", "TRUE", "FALSE", "THEN", "ELSE",
  "ENDIF", "WHILE", "DO", "ENDWHILE", "READMEM", "WRITEMEM", "END", "DECL",
  "ENDDECL", "INT", "MAIN", "CHAR", "BOOL", "RETURN", "TYPE", "ENDTYPE",
  "exitcode", "'='", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "'%'",
  "'{'", "'}'", "';'", "','", "'['", "']'", "'('", "')'", "'&'", "'.'",
  "$accept", "start", "statement_list", "type_declaration_list",
  "type_declaration", "type_attributes_decl", "type_attribute_decl",
  "decl_statement_list", "decl_statement", "declarations", "declaration",
  "Fdef_list", "Fdef", "Fname", "Farg_list", "Farg", "FargsId",
  "ldecl_statement_list", "ldecl_statement", "ldeclarations",
  "ldeclaration", "statement", "expr", "InnerVar", "FcallExpressions", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,    61,    60,    62,    43,    45,    42,    47,
      37,   123,   125,    59,    44,    91,    93,    40,    41,    38,
      46
};
# endif

#define YYPACT_NINF -119

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-119)))

#define YYTABLE_NINF -31

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-31)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      76,    44,    22,    11,    35,  -119,  -119,  -119,  -119,    19,
      20,    30,    40,  -119,    90,    50,   139,   139,   113,   132,
     135,    41,  -119,    16,    16,    16,    49,  -119,   124,   110,
     117,   126,  -119,  -119,   127,  -119,   122,  -119,   109,   170,
     180,   500,  -119,   500,  -119,  -119,  -119,   169,  -119,    16,
    -119,  -119,  -119,   121,   121,   121,   103,  -119,   133,   131,
    -119,    12,  -119,   138,   155,   159,  -119,  -119,  -119,  -119,
      -2,    -2,    -2,  -119,  -119,  -119,  -119,  -119,  -119,   204,
     197,   212,   228,    28,    33,    34,  -119,  -119,    -1,  -119,
    -119,   175,   184,   186,  -119,   249,   247,   263,   281,  -119,
     504,   504,   504,   313,   313,   313,   214,  -119,   494,   496,
    -119,   230,  -119,   244,   246,   319,  -119,   320,   331,  -119,
     313,  -119,  -119,   485,   485,   485,  -119,   150,   288,   289,
     292,   303,    23,   128,   304,  -119,   -21,   444,   452,    23,
     333,    23,    23,    23,  -119,   151,    23,  -119,  -119,   305,
     308,    23,   349,   321,   339,   316,   327,  -119,    23,    23,
     365,   329,   341,   259,   -32,    55,   153,   195,    23,  -119,
      23,    23,   211,   340,    23,    23,    23,   351,    23,    23,
      23,    23,    23,    23,    23,  -119,  -119,   387,   -34,   355,
    -119,  -119,  -119,   353,    23,   344,   356,   386,   383,   275,
     227,   323,  -119,    23,    36,   362,   362,    23,   403,   403,
      58,    58,   362,   362,  -119,    23,   360,  -119,    23,   291,
    -119,  -119,   485,   485,  -119,  -119,    23,   307,  -119,   403,
     387,  -119,   371,   367,   439,   477,   243,  -119,  -119,   373,
     485,   374,   375,  -119,  -119,   481,  -119,  -119,   376,  -119
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     8,     1,     8,     4,     0,
       0,     0,     0,     7,     0,     0,     0,     0,     0,     0,
       0,     0,    11,     0,     0,     0,     0,    16,     0,     0,
       0,     0,     9,    10,    23,    31,     0,    21,     0,     0,
       0,     0,    15,     0,    12,    13,    14,     0,    19,     0,
      33,    17,    18,     0,     0,     0,     0,    26,     0,     0,
      20,     0,    30,     0,     0,     0,     2,    25,     3,    22,
       0,     0,     0,    24,    32,    33,    33,    33,    37,     0,
       0,     0,     0,     0,     0,     0,    38,    36,     0,    34,
      35,     0,     0,     0,    39,     0,     0,     0,     0,    40,
       0,     0,     0,     0,     0,     0,     0,    42,     0,     0,
      48,     0,    47,     0,     0,     0,    41,     0,     0,    45,
       0,    43,    44,     0,     0,     0,    46,    82,     0,     0,
       0,     0,     0,     0,     0,     6,     0,     0,     0,     0,
       0,     0,     0,     0,    75,    82,     0,    78,    79,     0,
       0,     0,     0,     0,     0,    71,     0,     5,    85,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    68,
       0,     0,     0,    72,    85,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    57,    29,    84,     0,     0,
      81,    27,    28,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    67,     0,     0,    76,    77,     0,    63,    64,
      59,    60,    61,    65,    66,     0,     0,    51,     0,     0,
      53,    55,     0,     0,    73,    69,     0,     0,    80,    62,
      83,    58,     0,     0,     0,     0,     0,    74,    52,     0,
       0,     0,     0,    70,    54,     0,    50,    56,     0,    49
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -119,  -119,  -116,   421,  -119,  -119,   408,   413,    95,   233,
     382,   389,   152,   -23,    10,  -119,   231,   205,     3,   215,
     314,  -115,     0,  -118,   261
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,   133,     9,    13,    21,    22,    26,    27,    36,
      37,    56,    57,   153,    61,    74,    80,   106,   107,   111,
     112,   135,   187,   155,   188
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      38,    38,    38,    78,    94,   136,   136,   136,   137,   138,
     215,     6,   159,   194,   216,   136,   195,    70,   157,   136,
     136,    34,   157,   157,    11,    11,    38,   144,   145,   160,
      63,    64,    65,    70,   146,   147,   148,    71,    70,    70,
      72,     7,    35,   149,   150,     4,    18,    79,    95,    35,
      12,    14,     5,    71,    23,    18,    72,     8,    71,    71,
      73,    72,    72,    16,   175,   176,    19,   175,   176,    20,
     151,    15,   152,    41,    24,    19,    91,    25,    20,     1,
     215,    92,    93,    32,   228,    83,    84,    85,   177,   178,
     179,   180,   181,   182,   183,   184,   182,   183,   184,     2,
     134,   134,   134,   196,   136,   136,   234,   235,    53,   116,
     134,   116,   116,    17,   134,   134,   136,   136,    29,   157,
     157,    42,   136,    42,   245,    66,    62,   136,    54,    23,
     157,    55,   154,   127,   128,   129,   130,    30,    53,   163,
      31,   165,   166,   167,    23,   131,   169,    35,    43,    24,
     156,   172,    25,    44,    35,    68,    50,   132,    54,   189,
      45,    55,   175,   176,    24,    48,    49,    25,   199,    46,
     200,   201,    47,    59,   -30,   205,   206,    69,   208,   209,
     210,   211,   212,   213,   214,    75,   177,   178,   179,   180,
     181,   182,   183,   184,   219,   139,   168,   -30,   -30,   134,
     134,   197,    76,   227,   175,   176,    77,   229,    67,    86,
      67,   134,   134,    51,    49,   230,    96,   134,   232,   103,
     175,   176,   134,    52,    49,    97,   236,    98,   177,   178,
     179,   180,   181,   182,   183,   184,   175,   176,   115,   104,
      87,    88,   105,   198,   177,   178,   179,   180,   181,   182,
     183,   184,   175,   176,    99,    89,    88,    39,    40,   202,
     177,   178,   179,   180,   181,   182,   183,   184,   175,   176,
     100,    90,    88,   119,   120,   225,   177,   178,   179,   180,
     181,   182,   183,   184,   175,   176,   101,   121,   120,   122,
     120,   243,   177,   178,   179,   180,   181,   182,   183,   184,
     175,   176,    81,    82,   102,   193,   108,   109,   177,   178,
     179,   180,   181,   182,   183,   184,   175,   176,   110,   113,
     114,   224,   123,   124,   177,   178,   179,   180,   181,   182,
     183,   184,   175,   176,   125,   140,   141,   233,   164,   142,
     177,   178,   179,   180,   181,   182,   183,   184,   175,   176,
     143,   158,   170,   237,   173,   171,   177,   178,   179,   180,
     181,   182,   183,   184,   175,   176,   160,   226,   174,   186,
     190,   191,   177,   178,   179,   180,   181,   182,   183,   184,
     175,   176,   185,   192,   207,   203,   218,   220,   177,   178,
     179,   180,   181,   182,   183,   184,   175,   176,   217,   221,
     222,   223,   184,   231,   177,   178,   179,   180,   181,   182,
     183,   184,   175,   176,   238,   239,   244,   246,   247,   249,
     177,   178,   179,   180,   181,   182,   183,   184,    10,    33,
      28,    60,    58,     0,   126,   204,   -31,   -31,   -31,   180,
     181,   182,   183,   184,   127,   128,   129,   130,     0,   127,
     128,   129,   130,     0,   240,   241,   131,   127,   128,   129,
     130,   131,     0,     0,     0,    35,   161,     0,   132,   131,
      35,     0,     0,   132,   162,     0,     0,     0,    35,     0,
       0,   132,   127,   128,   129,   130,   127,   128,   129,   130,
     127,   128,   129,   130,   131,     0,   242,   248,   131,   103,
       0,   103,   131,    35,     0,    53,   132,    35,     0,   103,
     132,    35,     0,     0,   132,     0,     0,     0,   117,   104,
     118,   104,   105,     0,   105,    54,     0,     0,    55,   104,
       0,     0,   105
};

static const yytype_int16 yycheck[] =
{
      23,    24,    25,     5,     5,   123,   124,   125,   124,   125,
      44,     0,    33,    45,    48,   133,    48,     5,   133,   137,
     138,     5,   137,   138,     5,     5,    49,     4,     5,    50,
      53,    54,    55,     5,    11,    12,    13,    25,     5,     5,
      28,    30,    26,    20,    21,     1,     5,    49,    49,    26,
      31,    31,    30,    25,     5,     5,    28,    22,    25,    25,
      48,    28,    28,    23,     9,    10,    25,     9,    10,    28,
      47,    41,    49,    24,    25,    25,    48,    28,    28,     3,
      44,    48,    48,    42,    48,    75,    76,    77,    33,    34,
      35,    36,    37,    38,    39,    40,    38,    39,    40,    23,
     123,   124,   125,    48,   222,   223,   222,   223,     5,   106,
     133,   108,   109,    23,   137,   138,   234,   235,     5,   234,
     235,    26,   240,    28,   240,    22,     5,   245,    25,     5,
     245,    28,   132,     5,     6,     7,     8,     5,     5,   139,
       5,   141,   142,   143,     5,    17,   146,    26,    24,    25,
      22,   151,    28,    43,    26,    22,    47,    29,    25,   159,
      43,    28,     9,    10,    25,    43,    44,    28,   168,    43,
     170,   171,    45,     4,    47,   175,   176,    46,   178,   179,
     180,   181,   182,   183,   184,    47,    33,    34,    35,    36,
      37,    38,    39,    40,   194,    45,    45,    47,    47,   222,
     223,    48,    47,   203,     9,    10,    47,   207,    56,     5,
      58,   234,   235,    43,    44,   215,    41,   240,   218,     5,
       9,    10,   245,    43,    44,    41,   226,    41,    33,    34,
      35,    36,    37,    38,    39,    40,     9,    10,    24,    25,
      43,    44,    28,    48,    33,    34,    35,    36,    37,    38,
      39,    40,     9,    10,     5,    43,    44,    24,    25,    48,
      33,    34,    35,    36,    37,    38,    39,    40,     9,    10,
      23,    43,    44,    43,    44,    48,    33,    34,    35,    36,
      37,    38,    39,    40,     9,    10,    23,    43,    44,    43,
      44,    48,    33,    34,    35,    36,    37,    38,    39,    40,
       9,    10,    71,    72,    23,    46,   101,   102,    33,    34,
      35,    36,    37,    38,    39,    40,     9,    10,     5,   104,
     105,    46,     3,     3,    33,    34,    35,    36,    37,    38,
      39,    40,     9,    10,     3,    47,    47,    46,     5,    47,
      33,    34,    35,    36,    37,    38,    39,    40,     9,    10,
      47,    47,    47,    46,     5,    47,    33,    34,    35,    36,
      37,    38,    39,    40,     9,    10,    50,    44,    47,    42,
       5,    42,    33,    34,    35,    36,    37,    38,    39,    40,
       9,    10,    43,    42,    33,    45,    33,    43,    33,    34,
      35,    36,    37,    38,    39,    40,     9,    10,    43,    43,
      14,    18,    40,    43,    33,    34,    35,    36,    37,    38,
      39,    40,     9,    10,    43,    48,    43,    43,    43,    43,
      33,    34,    35,    36,    37,    38,    39,    40,     7,    21,
      17,    49,    43,    -1,   120,   174,    33,    34,    35,    36,
      37,    38,    39,    40,     5,     6,     7,     8,    -1,     5,
       6,     7,     8,    -1,    15,    16,    17,     5,     6,     7,
       8,    17,    -1,    -1,    -1,    26,    22,    -1,    29,    17,
      26,    -1,    -1,    29,    22,    -1,    -1,    -1,    26,    -1,
      -1,    29,     5,     6,     7,     8,     5,     6,     7,     8,
       5,     6,     7,     8,    17,    -1,    19,    16,    17,     5,
      -1,     5,    17,    26,    -1,     5,    29,    26,    -1,     5,
      29,    26,    -1,    -1,    29,    -1,    -1,    -1,    24,    25,
      24,    25,    28,    -1,    28,    25,    -1,    -1,    28,    25,
      -1,    -1,    28
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    23,    52,     1,    30,     0,    30,    22,    54,
      54,     5,    31,    55,    31,    41,    23,    23,     5,    25,
      28,    56,    57,     5,    25,    28,    58,    59,    58,     5,
       5,     5,    42,    57,     5,    26,    60,    61,    64,    60,
      60,    24,    59,    24,    43,    43,    43,    45,    43,    44,
      47,    43,    43,     5,    25,    28,    62,    63,    62,     4,
      61,    65,     5,    64,    64,    64,    22,    63,    22,    46,
       5,    25,    28,    48,    66,    47,    47,    47,     5,    49,
      67,    67,    67,    65,    65,    65,     5,    43,    44,    43,
      43,    48,    48,    48,     5,    49,    41,    41,    41,     5,
      23,    23,    23,     5,    25,    28,    68,    69,    68,    68,
       5,    70,    71,    70,    70,    24,    69,    24,    24,    43,
      44,    43,    43,     3,     3,     3,    71,     5,     6,     7,
       8,    17,    29,    53,    64,    72,    74,    53,    53,    45,
      47,    47,    47,    47,     4,     5,    11,    12,    13,    20,
      21,    47,    49,    64,    73,    74,    22,    72,    47,    33,
      50,    22,    22,    73,     5,    73,    73,    73,    45,    73,
      47,    47,    73,     5,    47,     9,    10,    33,    34,    35,
      36,    37,    38,    39,    40,    43,    42,    73,    75,    73,
       5,    42,    42,    46,    45,    48,    48,    48,    48,    73,
      73,    73,    48,    45,    75,    73,    73,    33,    73,    73,
      73,    73,    73,    73,    73,    44,    48,    43,    33,    73,
      43,    43,    14,    18,    46,    48,    44,    73,    48,    73,
      73,    43,    73,    46,    53,    53,    73,    46,    43,    48,
      15,    16,    19,    48,    43,    53,    43,    43,    16,    43
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    52,    52,    52,    53,    53,    54,    54,    55,
      56,    56,    57,    57,    57,    58,    58,    59,    59,    59,
      60,    60,    61,    61,    61,    62,    62,    63,    63,    63,
      64,    64,    65,    65,    66,    66,    66,    67,    67,    67,
      67,    68,    68,    69,    69,    69,    70,    70,    71,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    74,    74,    75,    75,    75
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     9,     9,     3,     2,     1,     2,     0,     4,
       2,     1,     3,     3,     3,     2,     1,     3,     3,     3,
       3,     1,     4,     1,     4,     2,     1,    13,    13,    13,
       1,     1,     2,     0,     3,     3,     3,     1,     2,     3,
       4,     2,     1,     3,     3,     3,     3,     1,     1,    10,
       8,     4,     7,     5,     8,     5,     8,     3,     5,     3,
       3,     3,     4,     3,     3,     3,     3,     3,     2,     4,
       6,     1,     2,     4,     5,     1,     3,     3,     1,     1,
       4,     3,     1,     3,     1,     0
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
#line 117 "xpl.y" /* yacc.c:1646  */
    {
                                            if(isAllDefined() == 0){
                                                return 0;
                                            }
                                            if(checkMultipleDeclaration() == 1){
                                                return 0;
                                            }
                                            //printTypeTable();
                                        }
#line 1537 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 128 "xpl.y" /* yacc.c:1646  */
    {
                                            if(isAllDefined() == 0){
                                                return 0;
                                            }
                                            if(checkMultipleDeclaration() == 1){
                                                return 0;
                                            }
                                            //printTypeTable();
                                            return 0;
                                        }
#line 1552 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 139 "xpl.y" /* yacc.c:1646  */
    {
                                            printf("ERROR\n");
                                            exit(0);
                                        }
#line 1561 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 146 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = makeOperationNode('S', 2, (yyvsp[-1].nPtr), (yyvsp[0].nPtr));
                                        }
#line 1569 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 149 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = (yyvsp[0].nPtr);
                                        }
#line 1577 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 158 "xpl.y" /* yacc.c:1646  */
    {

                                                }
#line 1585 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 161 "xpl.y" /* yacc.c:1646  */
    {

                                                }
#line 1593 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 166 "xpl.y" /* yacc.c:1646  */
    {
                                                    struct typeTable * t;
                                                    t = installType((yyvsp[-3].strPointer),(yyvsp[-1].field));
                                                    //check if any variable refer the this type
                                                    struct Fieldlist * f;
                                                    f = (yyvsp[-1].field);
                                                    while(f){
                                                        if(f->type->size == INVALID){
                                                            if(strcmp((yyvsp[-3].strPointer),f->type->name) == 0){
                                                                f->type = t;
                                                            }
                                                            else{
                                                                printf("Invalid data type %s",f->type->name);
                                                            }
                                                        }
                                                        f = f->next;
                                                    }
                                                }
#line 1616 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 187 "xpl.y" /* yacc.c:1646  */
    {
                                                    (yyvsp[0].field)->next = (yyvsp[-1].field);
                                                    (yyval.field) = (yyvsp[0].field);
                                                }
#line 1625 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 191 "xpl.y" /* yacc.c:1646  */
    {
                                                    (yyval.field) = (yyvsp[0].field);
                                                }
#line 1633 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 196 "xpl.y" /* yacc.c:1646  */
    {
                                                    struct typeTable * t;
                                                    t = getTypeTuple((yyvsp[-2].strPointer));
                                                    //Either invalid or referring the enclosed type
                                                    if(t == NULL){
                                                        t = newTypeTuple();
                                                        t->name = (yyvsp[-2].strPointer);
                                                        t->size = INVALID;
                                                    }
                                                    (yyval.field) = installFieldList((yyvsp[-1].strPointer),t);
                                                }
#line 1649 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 208 "xpl.y" /* yacc.c:1646  */
    {
                                                    struct typeTable * t;
                                                    t = getTypeTuple("integer");
                                                    (yyval.field) = installFieldList((yyvsp[-1].strPointer),t);
                                                }
#line 1659 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 214 "xpl.y" /* yacc.c:1646  */
    {
                                                    struct typeTable * t;
                                                    t = getTypeTuple("boolean");
                                                    (yyval.field) = installFieldList((yyvsp[-1].strPointer),t);
                                                }
#line 1669 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 228 "xpl.y" /* yacc.c:1646  */
    {
                                            
                                        }
#line 1677 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 231 "xpl.y" /* yacc.c:1646  */
    {
                                            
                                        }
#line 1685 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 238 "xpl.y" /* yacc.c:1646  */
    {
                                            struct typeTable * typeTableTuple;
                                            char *dataType;
                                            dataType = copyString("integer");
                                            typeTableTuple = getTypeTuple(dataType);
                                            installAllVariables((yyvsp[-1].IDs),typeTableTuple);
                                        }
#line 1697 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 247 "xpl.y" /* yacc.c:1646  */
    {
                                            struct typeTable * typeTableTuple;
                                            char *dataType;
                                            dataType = copyString("boolean");
                                            typeTableTuple = getTypeTuple(dataType);
                                            installAllVariables((yyvsp[-1].IDs),typeTableTuple);
                                        }
#line 1709 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 254 "xpl.y" /* yacc.c:1646  */
    {
                                            struct typeTable * typeTableTuple;
                                            typeTableTuple = getTypeTuple((yyvsp[-2].strPointer));
                                            if(typeTableTuple){ 
                                                installAllVariables((yyvsp[-1].IDs),typeTableTuple);
                                            }
                                            else{
                                                printf("Invalid type %s on %d",(yyvsp[-2].strPointer),lineNumber);
                                            }
                                        }
#line 1724 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 270 "xpl.y" /* yacc.c:1646  */
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
#line 1739 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 281 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.IDs) = (yyvsp[0].IDs);
                                        }
#line 1747 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 288 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.IDs) = installVariable((yyvsp[-3].strPointer),NULL,(yyvsp[-1].iValue));
                                        }
#line 1755 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 292 "xpl.y" /* yacc.c:1646  */
    {
                                            int size = 1;
                                            (yyval.IDs) = installVariable((yyvsp[0].strPointer),NULL,size);
                                        }
#line 1764 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 296 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.IDs) = installFunction((yyvsp[-3].strPointer),(yyvsp[-1].args),NULL,NULL);
                                            (yyval.IDs)->isDefined = 0;
                                        }
#line 1773 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 311 "xpl.y" /* yacc.c:1646  */
    {

                                        }
#line 1781 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 315 "xpl.y" /* yacc.c:1646  */
    {

                                        }
#line 1789 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 322 "xpl.y" /* yacc.c:1646  */
    {
                                            struct typeTable * typeTableTuple;
                                            char * dataType;
                                            dataType = copyString("integer");
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
                                            if(checkMultipleLocalDeclaration(symbolTableEntry->lsymbols) == 1){
                                                printf("Error in Function %s",(yyvsp[-11].strPointer));
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
                                            symbolTableEntry->isDefined = 1;
                                            //printAllVariables();
                                            //installFunction($2,$4,typeTableTuple,$8);
                                            currLocalTable = symbolTableEntry->lsymbols;
                                            currFunction   = symbolTableEntry;
                                            if(strcmp((yyvsp[-11].strPointer),"MAIN") == 0){
                                                printAllVariables();
                                            }
                                            if(analyse((yyvsp[-2].nPtr))){
                                                initializeRegister();
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
                                                return 0;
                                            }
                                        }
#line 1847 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 376 "xpl.y" /* yacc.c:1646  */
    {
                                            struct typeTable * typeTableTuple;
                                            char * dataType;
                                            dataType            = copyString("boolean");
                                            typeTableTuple      = getTypeTuple(dataType);
                                            if(strcmp((yyvsp[-11].strPointer),"MAIN") == 0){
                                                installFunction((yyvsp[-11].strPointer),NULL,typeTableTuple,NULL);
                                            }
                                            struct Gsymbol * symbolTableEntry;
                                            symbolTableEntry    = getSymbolTableTuple((yyvsp[-11].strPointer));
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
                                            symbolTableEntry->isDefined = 1;
                                            //printAllVariables();
                                            //installFunction($2,$4,typeTableTuple,$8);
                                            currLocalTable      = symbolTableEntry->lsymbols;
                                            currFunction        = symbolTableEntry;
                                            
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
                                                return 0;
                                            }
                                        }
#line 1898 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 424 "xpl.y" /* yacc.c:1646  */
    {
                                            struct typeTable * typeTableTuple;
                                            typeTableTuple      = getTypeTuple((yyvsp[-12].strPointer));
                                            if(strcmp((yyvsp[-11].strPointer),"MAIN") == 0){
                                                installFunction((yyvsp[-11].strPointer),NULL,typeTableTuple,NULL);
                                            }
                                            struct Gsymbol * symbolTableEntry;
                                            symbolTableEntry    = getSymbolTableTuple((yyvsp[-11].strPointer));
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
                                            symbolTableEntry->isDefined = 1;
                                            //printAllVariables();
                                            //installFunction($2,$4,typeTableTuple,$8);
                                            currLocalTable      = symbolTableEntry->lsymbols;
                                            currFunction        = symbolTableEntry;
                                            
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
                                                return 0;
                                            }
                                        }
#line 1947 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 470 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.strPointer) = (yyvsp[0].strPointer);
                                        }
#line 1955 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 473 "xpl.y" /* yacc.c:1646  */
    {
                                            char *fnName;
                                            fnName = copyString("MAIN");
                                            (yyval.strPointer) = fnName;
                                        }
#line 1965 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 481 "xpl.y" /* yacc.c:1646  */
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
#line 1984 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 495 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.args) = NULL;
                                        }
#line 1992 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 501 "xpl.y" /* yacc.c:1646  */
    {
                                            struct typeTable * typeTableTuple;
                                            char *dataType;
                                            dataType = copyString("integer");
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
#line 2022 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 527 "xpl.y" /* yacc.c:1646  */
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
#line 2052 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 554 "xpl.y" /* yacc.c:1646  */
    {
                                            struct typeTable * typeTableTuple;
                                            typeTableTuple = getTypeTuple((yyvsp[-2].strPointer));
                                            if(!typeTableTuple){
                                                printf("Invalid Data Type %s\n",(yyvsp[-2].strPointer));
                                            }
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
#line 2083 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 582 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.arg) = makeArgumentNode((yyvsp[0].strPointer));//for saving arguments whose type is unknown(For temporary use)
                                        }
#line 2091 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 586 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.arg) = makeArgumentNode((yyvsp[0].strPointer));//for saving arguments whose type is unknown(For temporary use)
                                            (yyval.arg)->isRef = 1;
                                        }
#line 2100 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 590 "xpl.y" /* yacc.c:1646  */
    {
                                            struct argumentDecl * poi;
                                            poi = (yyvsp[-2].arg);
                                            while(poi->next){
                                                poi = poi->next;
                                            }
                                            poi->next = makeArgumentNode((yyvsp[0].strPointer));
                                        }
#line 2113 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 598 "xpl.y" /* yacc.c:1646  */
    {
                                            struct argumentDecl * poi;
                                            struct argumentDecl * poi2;
                                            poi = (yyvsp[-3].arg);
                                            while(poi->next){
                                                poi = poi->next;
                                            }
                                            poi2 = makeArgumentNode((yyvsp[0].strPointer));
                                            poi2->isRef = 1;
                                            poi->next = poi2;
                                        }
#line 2129 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 612 "xpl.y" /* yacc.c:1646  */
    {
                                            struct Lsymbol * lsymbolHead;
                                            lsymbolHead = (yyvsp[-1].localVars);
                                            while(lsymbolHead->next){
                                                lsymbolHead = lsymbolHead->next;
                                            }
                                            lsymbolHead->next = (yyvsp[0].localVars);
                                            (yyval.localVars) = (yyvsp[-1].localVars);
                                        }
#line 2143 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 622 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.localVars) =(yyvsp[0].localVars);
                                        }
#line 2151 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 629 "xpl.y" /* yacc.c:1646  */
    {
                                            struct typeTable * typeTableTuple;
                                            char *dataType;
                                            dataType = copyString("integer");
                                            typeTableTuple = getTypeTuple(dataType);
                                            (yyval.localVars) = installAllLocalVariables((yyvsp[-1].Locals),typeTableTuple);
                                            //freeVarList($2);
                                        }
#line 2164 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 639 "xpl.y" /* yacc.c:1646  */
    {
                                            struct typeTable * typeTableTuple;
                                            char *dataType;
                                            dataType = copyString("boolean");
                                            typeTableTuple = getTypeTuple(dataType);
                                            (yyval.localVars) = installAllLocalVariables((yyvsp[-1].Locals),typeTableTuple);
                                            //freeVarList($2);
                                        }
#line 2177 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 649 "xpl.y" /* yacc.c:1646  */
    {
                                            struct typeTable * typeTableTuple;
                                            typeTableTuple = getTypeTuple((yyvsp[-2].strPointer));
                                            if(!typeTableTuple){
                                                printf("Invalid data type %s\n",(yyvsp[-2].strPointer));
                                            }
                                            (yyval.localVars) = installAllLocalVariables((yyvsp[-1].Locals),typeTableTuple);
                                            //freeVarList($2);
                                        }
#line 2191 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 665 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyvsp[0].Locals)->next = (yyvsp[-2].Locals);
                                            (yyval.Locals) = (yyvsp[0].Locals);
                                        }
#line 2200 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 670 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.Locals) = (yyvsp[0].Locals);
                                        }
#line 2208 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 677 "xpl.y" /* yacc.c:1646  */
    {
                                            int size = 1;
                                            (yyval.Locals) = installLocalVariable((yyvsp[0].strPointer),NULL,size);
                                        }
#line 2217 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 686 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = makeOperationNode('I', 3, (yyvsp[-7].nPtr), (yyvsp[-4].nPtr), (yyvsp[-2].nPtr));
                                        }
#line 2225 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 691 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = makeOperationNode('I', 2, (yyvsp[-5].nPtr), (yyvsp[-2].nPtr));
                                        }
#line 2233 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 696 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = makeOperationNode('=', 2, (yyvsp[-3].nPtr), (yyvsp[-1].nPtr));
                                        }
#line 2241 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 702 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = makeOperationNode('=', 2, makeIdNode((yyvsp[-6].strPointer),(yyvsp[-4].nPtr)), (yyvsp[-1].nPtr));
                                        }
#line 2249 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 707 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = makeOperationNode('R', 1, makeIdNode((yyvsp[-2].strPointer),makeConstantNode(0,1)));
                                        }
#line 2257 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 712 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = makeOperationNode('R', 1, makeIdNode((yyvsp[-5].strPointer),(yyvsp[-3].nPtr)));
                                        }
#line 2265 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 717 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = makeOperationNode('W', 1, (yyvsp[-2].nPtr));
                                        }
#line 2273 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 722 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = makeOperationNode('L', 2, (yyvsp[-5].nPtr), (yyvsp[-2].nPtr));
                                        }
#line 2281 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 725 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = makeOperationNode('^',1,(yyvsp[-1].nPtr));
                                        }
#line 2289 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 729 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = makeFunctionNode((yyvsp[-4].strPointer),(yyvsp[-2].fArgExpr));
                                            //printf("%s\n",$1);
                                        }
#line 2298 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 737 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = makeOperationNode('+', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));
                                        }
#line 2306 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 741 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = makeOperationNode('-', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));
                                        }
#line 2314 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 745 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = makeOperationNode('*', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));
                                        }
#line 2322 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 749 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = makeOperationNode('~', 2, (yyvsp[-3].nPtr), (yyvsp[0].nPtr));
                                        }
#line 2330 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 753 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = makeOperationNode('<', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));
                                        }
#line 2338 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 757 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = makeOperationNode('>', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));
                                        }
#line 2346 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 761 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = makeOperationNode('/', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));
                                        }
#line 2354 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 765 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = makeOperationNode('%', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));
                                        }
#line 2362 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 769 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = (yyvsp[-1].nPtr);
                                        }
#line 2370 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 773 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = makeOperationNode('!', 1, (yyvsp[0].nPtr));
                                        }
#line 2378 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 776 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = makeOperationNode('@',2,(yyvsp[-1].nPtr),(yyvsp[-1].nPtr));
                                        }
#line 2386 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 780 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = makeOperationNode('#',2,(yyvsp[-3].nPtr),(yyvsp[-1].nPtr));
                                        }
#line 2394 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 785 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = (yyvsp[0].nPtr);
                                        }
#line 2402 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 790 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = makeIdNode((yyvsp[0].strPointer),makeConstantNode(0,1));
                                            (yyval.nPtr)->id.isRef = 1;
                                        }
#line 2411 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 795 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = makeIdNode((yyvsp[-3].strPointer),(yyvsp[-1].nPtr));
                                        }
#line 2419 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 799 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = makeIdNode((yyvsp[-3].strPointer),(yyvsp[-1].nPtr));
                                            (yyval.nPtr)->id.isRef = 1;
                                        }
#line 2428 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 804 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = makeConstantNode((yyvsp[0].iValue),1);
                                        }
#line 2436 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 807 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = makeOperationNode('&',2,(yyvsp[-2].nPtr),(yyvsp[0].nPtr));
                                        }
#line 2444 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 810 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = makeOperationNode('|',2,(yyvsp[-2].nPtr),(yyvsp[0].nPtr));
                                        }
#line 2452 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 813 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = makeConstantNode(1,3);
                                        }
#line 2460 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 816 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = makeConstantNode(0,3);
                                        }
#line 2468 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 820 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = makeFunctionNode((yyvsp[-3].strPointer),(yyvsp[-1].fArgExpr));
                                            //printf("%s\n",$1);
                                        }
#line 2477 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 826 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = makeInnerVar((yyvsp[-2].nPtr),(yyvsp[0].strPointer));
                                        }
#line 2485 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 829 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = makeIdNode((yyvsp[0].strPointer),makeConstantNode(0,1));
                                        }
#line 2493 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 835 "xpl.y" /* yacc.c:1646  */
    {
                                            if((yyvsp[-2].fArgExpr)){
                                                struct fArgExpression *head;
                                                head = (yyvsp[-2].fArgExpr);
                                                while(head->next){
                                                    head = head->next;
                                                }
                                                head->next = makeFargNode((yyvsp[0].nPtr));
                                                (yyval.fArgExpr) = (yyvsp[-2].fArgExpr);
                                            }
                                            else{
                                                error("");
                                                return 0;
                                            }
                                        }
#line 2513 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 850 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.fArgExpr) = makeFargNode((yyvsp[0].nPtr));
                                        }
#line 2521 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 853 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.fArgExpr) = NULL;                                          
                                        }
#line 2529 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2533 "y.tab.c" /* yacc.c:1646  */
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
#line 858 "xpl.y" /* yacc.c:1906  */



// Basic Function
        char * copyString(char * source){
            char * destination;
            int size        = strlen(source);
            destination     = malloc(size);
            strcpy(destination,source);
        }

//For Variable Declarations
        //Variable node is a temporary data structure for creating symbol table entries
        struct variableDecl * makeVariableNode(char * name,int size){
            struct variableDecl * varNode;
            varNode         = malloc(sizeof(struct variableDecl));
            if(!varNode){
                outOfMemory();
            }
            varNode->name   = copyString(name);
            varNode->size   = size;
            varNode->next   = NULL;
            return varNode;
        }

//For Argument Declarations
        //Argument node is a temporary data structure for creating symbol table entries
        struct argumentDecl * makeArgumentNode(char * name){
            struct argumentDecl * argNode;
            argNode         = malloc(sizeof(struct argumentDecl));
            if(!argNode){
                outOfMemory();
            }
            argNode->name   = copyString(name);
            argNode->next   = NULL;
            argNode->isRef  = 0;
            return argNode;
        }


//Expression Tree Related Functions


//To check if all functions are defined
        int isAllDefined(){
            struct Gsymbol * head;
            head = GsymbolHead;
            while(head){
                if(head->size == 0){
                    if(head->isDefined == 0){
                        printf("Error : Function %s declared but not defined\n", head->name);
                        return 0;
                    }
                }
                head = head->next;
            }
            return 1;
        }



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
            /*
            FILE *sourceCode = fopen(filename, "r");
            extern FILE *yyin;
            yyin = sourceCode;
            */
            //yyparse();
        }
        void preprocess(char * filename){
            FILE *sourceCode = fopen(filename, "r");
            extern FILE *yyin;
            yyin = sourceCode;
            yyparse();
            printf("I'm Done");
            lineNumber = 0;
        }
        void outOfMemory(){
            yyerror("Out of Memory");
        }

//Main Function

    int main(int argc,char *argv[])
    {
        struct fileNodes * fileNamePoi;
        struct fileNodes * fileNamePoiTemp;
        int counter;
        makeBasicTypeTable();
        fp=fopen("temp.xsm","wb");
        fprintf(fp,"START\n");
        fprintf(fp,"MOV SP, 1535\n");
        fprintf(fp,"MOV BP, 1535\n");
        fprintf(fp,"CALL MAIN\n");
        fprintf(fp,"HALT\n");
        if(argc==1){
            readInput();
        }
        else{
            fileNamePoi = malloc(sizeof(struct fileNodes));
            fileNamePoi->filename = argv[1];
            fileNamePoi->next = NULL;
            fileHeader = fileNamePoi;
            counter = 2;
            while(counter < argc){
                fileNamePoiTemp = malloc(sizeof(struct fileNodes));
                fileNamePoiTemp->filename = argv[counter];
                fileNamePoiTemp->next = NULL;
                fileNamePoi->next = fileNamePoiTemp;
                fileNamePoi = fileNamePoiTemp;
                counter++;
            }
            filename = argv[1];
            //preprocess();
            //readFile(argv[1]);
            preprocess(fileHeader->filename);
        }
        fprintf(fp,"HALT\n");
        return 1;
    }
    
