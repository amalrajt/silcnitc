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
extern FILE *yyin;
extern int regCount;
extern FILE *fp;

//extern struct Gsymbol * GsymbolHead;
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


#line 98 "y.tab.c" /* yacc.c:339  */

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
#line 34 "xpl.y" /* yacc.c:355  */
 
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

#line 216 "y.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 231 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   485

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  83
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  236

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
       0,   107,   107,   119,   126,   129,   138,   141,   146,   166,
     171,   176,   188,   194,   207,   211,   217,   226,   234,   249,
     260,   267,   271,   276,   290,   294,   301,   355,   403,   450,
     453,   460,   475,   480,   506,   533,   562,   565,   570,   578,
     591,   601,   608,   618,   628,   644,   649,   656,   665,   670,
     675,   681,   686,   691,   696,   701,   705,   711,   715,   719,
     723,   727,   731,   735,   739,   743,   747,   751,   754,   759,
     764,   769,   773,   778,   782,   785,   788,   791,   794,   801,
     804,   809,   825,   828
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

#define YYPACT_NINF -117

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-117)))

#define YYTABLE_NINF -30

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-30)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      12,    30,  -117,    41,    48,    17,  -117,  -117,    37,    61,
    -117,    64,    97,   118,   125,   137,     1,  -117,    40,    40,
      40,   147,  -117,   194,   209,   210,  -117,  -117,    38,  -117,
      89,  -117,   140,    91,    96,   440,  -117,  -117,  -117,  -117,
     199,  -117,    40,  -117,  -117,  -117,    74,    74,    74,     2,
    -117,   205,  -117,    62,  -117,   172,   220,   221,  -117,  -117,
    -117,     0,     0,     0,  -117,  -117,  -117,  -117,  -117,  -117,
     250,   116,   130,   145,    83,    88,    93,  -117,  -117,     4,
    -117,  -117,   215,   228,   230,  -117,   267,   260,   261,   262,
    -117,   457,   457,   457,   282,   282,   282,   414,  -117,   439,
     456,  -117,   161,  -117,   163,   177,   285,  -117,   296,   297,
    -117,   282,  -117,  -117,   449,   449,   449,  -117,   258,   254,
     257,   268,   270,    60,   392,  -117,   -16,   405,   418,    60,
     313,    60,    60,    60,  -117,    79,    60,  -117,  -117,   273,
     286,    60,   314,   287,   288,   298,   290,  -117,    60,   330,
     294,   307,   208,    -8,   110,   128,   144,    60,  -117,    60,
      60,   160,   305,    60,    60,    60,   318,    60,    60,    60,
      60,    60,    60,    60,  -117,  -117,   304,  -117,  -117,  -117,
     319,    60,   321,   322,   353,   348,   224,   176,   272,  -117,
      60,   336,   -23,   328,   328,    60,   352,   352,    23,    23,
     328,   328,  -117,  -117,    60,   240,  -117,  -117,   449,   449,
    -117,  -117,    60,   256,    60,  -117,   352,   320,   329,   388,
     424,   192,  -117,   336,  -117,   335,   449,   337,   338,  -117,
    -117,   443,  -117,  -117,   339,  -117
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     7,     0,     0,     0,     1,     3,     0,     0,
       6,     0,     0,     0,     0,     0,     0,    10,     0,     0,
       0,     0,    15,     0,     0,     0,     8,     9,    22,    30,
       0,    20,     0,     0,     0,     0,    14,    11,    12,    13,
       0,    18,     0,    32,    16,    17,     0,     0,     0,     0,
      25,     0,    19,     0,    29,     0,     0,     0,     2,    24,
      21,     0,     0,     0,    23,    31,    32,    32,    32,    36,
       0,     0,     0,     0,     0,     0,     0,    37,    35,     0,
      33,    34,     0,     0,     0,    38,     0,     0,     0,     0,
      39,     0,     0,     0,     0,     0,     0,     0,    41,     0,
       0,    47,     0,    46,     0,     0,     0,    40,     0,     0,
      44,     0,    42,    43,     0,     0,     0,    45,    80,     0,
       0,     0,     0,     0,     0,     5,     0,     0,     0,     0,
       0,     0,     0,     0,    73,    80,     0,    76,    77,     0,
       0,     0,     0,     0,     0,    69,     0,     4,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    66,     0,
       0,     0,    70,    83,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    56,    28,     0,    79,    26,    27,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    65,
       0,    82,     0,    74,    75,     0,    61,    62,    57,    58,
      59,    63,    64,    50,     0,     0,    52,    54,     0,     0,
      71,    67,     0,     0,     0,    78,    60,     0,     0,     0,
       0,     0,    72,    81,    51,     0,     0,     0,     0,    68,
      53,     0,    49,    55,     0,    48
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -117,  -117,  -112,  -117,  -117,  -117,   363,  -117,   362,   171,
     342,  -117,   357,   109,     8,  -117,   173,   146,   -61,   127,
     291,  -116,  -113,  -114,  -117
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,   124,     5,    10,    16,    17,    21,    22,    30,
      31,    49,    50,   143,    53,    65,    71,    97,    98,   102,
     103,   125,   144,   145,   192
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     126,   126,   126,   127,   128,    69,    13,    46,   147,    85,
     126,   147,   147,   126,   126,     1,   152,   148,   154,   155,
     156,   214,     8,   158,    58,   215,    14,    47,   161,    15,
      48,     4,   164,   165,   149,   176,   107,   181,   107,   107,
     182,     6,     2,    26,   186,    28,   187,   188,     9,    70,
     191,   193,   194,    86,   196,   197,   198,   199,   200,   201,
     202,   171,   172,   173,   134,   135,    29,    61,   205,    13,
       7,   136,   137,   138,    74,    75,    76,   213,    11,    54,
     139,   140,   216,    40,    12,   -29,    29,    62,    61,    14,
      63,   217,    15,    61,   126,   126,   219,   220,    61,   221,
      29,   223,    18,   147,   147,   126,   126,   141,    62,   142,
      64,    63,   126,    62,   231,   147,    63,   126,    62,   164,
     165,    63,    19,    23,   157,    20,   -29,    32,    32,    32,
      24,    82,    41,    42,    44,    42,    83,   164,   165,    45,
      42,    84,    25,   166,   167,   168,   169,   170,   171,   172,
     173,    32,    18,   164,   165,    55,    56,    57,   183,    78,
      79,   166,   167,   168,   169,   170,   171,   172,   173,   164,
     165,    35,    19,    80,    79,    20,   184,   166,   167,   168,
     169,   170,   171,   172,   173,   164,   165,    43,    81,    79,
      33,    34,   185,   166,   167,   168,   169,   170,   171,   172,
     173,   164,   165,    51,   110,   111,   112,   111,   189,   166,
     167,   168,   169,   170,   171,   172,   173,   164,   165,    66,
     113,   111,   104,   105,   211,   166,   167,   168,   169,   170,
     171,   172,   173,   164,   165,    72,    73,    37,    99,   100,
     229,   166,   167,   168,   169,   170,   171,   172,   173,   164,
     165,    60,    38,    39,   180,    77,    87,   166,   167,   168,
     169,   170,   171,   172,   173,   164,   165,    67,    68,    88,
     210,    89,    90,   166,   167,   168,   169,   170,   171,   172,
     173,   164,   165,    91,    92,    93,   218,   101,   114,   166,
     167,   168,   169,   170,   171,   172,   173,   164,   165,   115,
     116,   130,   222,   129,   131,   166,   167,   168,   169,   170,
     171,   172,   173,   164,   165,   132,   212,   133,   153,   162,
     159,   166,   167,   168,   169,   170,   171,   172,   173,   164,
     165,   174,   175,   160,   163,   177,   178,   166,   167,   168,
     169,   170,   171,   172,   173,   164,   165,   203,   149,   179,
     190,   195,   204,   166,   167,   168,   169,   170,   171,   172,
     173,   164,   165,   224,   206,   207,   209,   208,   173,   166,
     167,   168,   169,   170,   171,   172,   173,   225,   230,    27,
     232,   233,   235,    36,    52,   -30,   -30,   -30,   169,   170,
     171,   172,   173,   118,   119,   120,   121,   118,   119,   120,
     121,     0,   117,   226,   227,   122,    59,     0,     0,   122,
     118,   119,   120,   121,   146,     0,     0,   123,     0,    94,
       0,   123,   122,   118,   119,   120,   121,   150,     0,   118,
     119,   120,   121,     0,   123,   122,     0,     0,   106,    95,
     151,   122,    96,   228,    94,    46,     0,   123,   118,   119,
     120,   121,     0,   123,   118,   119,   120,   121,     0,   234,
     122,    94,    94,   108,    95,    47,   122,    96,    48,     0,
       0,     0,   123,     0,     0,     0,     0,     0,   123,     0,
     109,    95,    95,     0,    96,    96
};

static const yytype_int16 yycheck[] =
{
     114,   115,   116,   115,   116,     5,     5,     5,   124,     5,
     124,   127,   128,   127,   128,     3,   129,    33,   131,   132,
     133,    44,     5,   136,    22,    48,    25,    25,   141,    28,
      28,     1,     9,    10,    50,   148,    97,    45,    99,   100,
      48,     0,    30,    42,   157,     5,   159,   160,    31,    49,
     163,   164,   165,    49,   167,   168,   169,   170,   171,   172,
     173,    38,    39,    40,     4,     5,    26,     5,   181,     5,
      22,    11,    12,    13,    66,    67,    68,   190,    41,     5,
      20,    21,   195,    45,    23,    47,    26,    25,     5,    25,
      28,   204,    28,     5,   208,   209,   208,   209,     5,   212,
      26,   214,     5,   219,   220,   219,   220,    47,    25,    49,
      48,    28,   226,    25,   226,   231,    28,   231,    25,     9,
      10,    28,    25,     5,    45,    28,    47,    18,    19,    20,
       5,    48,    43,    44,    43,    44,    48,     9,    10,    43,
      44,    48,     5,    33,    34,    35,    36,    37,    38,    39,
      40,    42,     5,     9,    10,    46,    47,    48,    48,    43,
      44,    33,    34,    35,    36,    37,    38,    39,    40,     9,
      10,    24,    25,    43,    44,    28,    48,    33,    34,    35,
      36,    37,    38,    39,    40,     9,    10,    47,    43,    44,
      19,    20,    48,    33,    34,    35,    36,    37,    38,    39,
      40,     9,    10,     4,    43,    44,    43,    44,    48,    33,
      34,    35,    36,    37,    38,    39,    40,     9,    10,    47,
      43,    44,    95,    96,    48,    33,    34,    35,    36,    37,
      38,    39,    40,     9,    10,    62,    63,    43,    92,    93,
      48,    33,    34,    35,    36,    37,    38,    39,    40,     9,
      10,    46,    43,    43,    46,     5,    41,    33,    34,    35,
      36,    37,    38,    39,    40,     9,    10,    47,    47,    41,
      46,    41,     5,    33,    34,    35,    36,    37,    38,    39,
      40,     9,    10,    23,    23,    23,    46,     5,     3,    33,
      34,    35,    36,    37,    38,    39,    40,     9,    10,     3,
       3,    47,    46,    45,    47,    33,    34,    35,    36,    37,
      38,    39,    40,     9,    10,    47,    44,    47,     5,     5,
      47,    33,    34,    35,    36,    37,    38,    39,    40,     9,
      10,    43,    42,    47,    47,     5,    42,    33,    34,    35,
      36,    37,    38,    39,    40,     9,    10,    43,    50,    42,
      45,    33,    33,    33,    34,    35,    36,    37,    38,    39,
      40,     9,    10,    43,    43,    43,    18,    14,    40,    33,
      34,    35,    36,    37,    38,    39,    40,    48,    43,    16,
      43,    43,    43,    21,    42,    33,    34,    35,    36,    37,
      38,    39,    40,     5,     6,     7,     8,     5,     6,     7,
       8,    -1,   111,    15,    16,    17,    49,    -1,    -1,    17,
       5,     6,     7,     8,    22,    -1,    -1,    29,    -1,     5,
      -1,    29,    17,     5,     6,     7,     8,    22,    -1,     5,
       6,     7,     8,    -1,    29,    17,    -1,    -1,    24,    25,
      22,    17,    28,    19,     5,     5,    -1,    29,     5,     6,
       7,     8,    -1,    29,     5,     6,     7,     8,    -1,    16,
      17,     5,     5,    24,    25,    25,    17,    28,    28,    -1,
      -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    29,    -1,
      24,    25,    25,    -1,    28,    28
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    30,    52,     1,    54,     0,    22,     5,    31,
      55,    41,    23,     5,    25,    28,    56,    57,     5,    25,
      28,    58,    59,     5,     5,     5,    42,    57,     5,    26,
      60,    61,    64,    60,    60,    24,    59,    43,    43,    43,
      45,    43,    44,    47,    43,    43,     5,    25,    28,    62,
      63,     4,    61,    65,     5,    64,    64,    64,    22,    63,
      46,     5,    25,    28,    48,    66,    47,    47,    47,     5,
      49,    67,    67,    67,    65,    65,    65,     5,    43,    44,
      43,    43,    48,    48,    48,     5,    49,    41,    41,    41,
       5,    23,    23,    23,     5,    25,    28,    68,    69,    68,
      68,     5,    70,    71,    70,    70,    24,    69,    24,    24,
      43,    44,    43,    43,     3,     3,     3,    71,     5,     6,
       7,     8,    17,    29,    53,    72,    74,    53,    53,    45,
      47,    47,    47,    47,     4,     5,    11,    12,    13,    20,
      21,    47,    49,    64,    73,    74,    22,    72,    33,    50,
      22,    22,    73,     5,    73,    73,    73,    45,    73,    47,
      47,    73,     5,    47,     9,    10,    33,    34,    35,    36,
      37,    38,    39,    40,    43,    42,    73,     5,    42,    42,
      46,    45,    48,    48,    48,    48,    73,    73,    73,    48,
      45,    73,    75,    73,    73,    33,    73,    73,    73,    73,
      73,    73,    73,    43,    33,    73,    43,    43,    14,    18,
      46,    48,    44,    73,    44,    48,    73,    73,    46,    53,
      53,    73,    46,    73,    43,    48,    15,    16,    19,    48,
      43,    53,    43,    43,    16,    43
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    52,    52,    53,    53,    54,    54,    55,    56,
      56,    57,    57,    57,    58,    58,    59,    59,    59,    60,
      60,    61,    61,    61,    62,    62,    63,    63,    63,    64,
      64,    65,    65,    66,    66,    66,    67,    67,    67,    67,
      68,    68,    69,    69,    69,    70,    70,    71,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    74,
      74,    75,    75,    75
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     8,     3,     2,     1,     2,     0,     4,     2,
       1,     3,     3,     3,     2,     1,     3,     3,     3,     3,
       1,     4,     1,     4,     2,     1,    13,    13,    13,     1,
       1,     2,     0,     3,     3,     3,     1,     2,     3,     4,
       2,     1,     3,     3,     3,     3,     1,     1,    10,     8,
       4,     7,     5,     8,     5,     8,     3,     3,     3,     3,
       4,     3,     3,     3,     3,     3,     2,     4,     6,     1,
       2,     4,     5,     1,     3,     3,     1,     1,     4,     3,
       1,     3,     1,     0
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
#line 108 "xpl.y" /* yacc.c:1646  */
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
#line 1516 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 119 "xpl.y" /* yacc.c:1646  */
    {
                                            printf("ERROR\n");
                                            exit(0);
                                        }
#line 1525 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 126 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = makeOperationNode('S', 2, (yyvsp[-1].nPtr), (yyvsp[0].nPtr));
                                        }
#line 1533 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 129 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = (yyvsp[0].nPtr);
                                        }
#line 1541 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 138 "xpl.y" /* yacc.c:1646  */
    {

                                                }
#line 1549 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 141 "xpl.y" /* yacc.c:1646  */
    {

                                                }
#line 1557 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 146 "xpl.y" /* yacc.c:1646  */
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
#line 1580 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 167 "xpl.y" /* yacc.c:1646  */
    {
                                                    (yyvsp[0].field)->next = (yyvsp[-1].field);
                                                    (yyval.field) = (yyvsp[0].field);
                                                }
#line 1589 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 171 "xpl.y" /* yacc.c:1646  */
    {
                                                    (yyval.field) = (yyvsp[0].field);
                                                }
#line 1597 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 176 "xpl.y" /* yacc.c:1646  */
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
#line 1613 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 188 "xpl.y" /* yacc.c:1646  */
    {
                                                    struct typeTable * t;
                                                    t = getTypeTuple("integer");
                                                    (yyval.field) = installFieldList((yyvsp[-1].strPointer),t);
                                                }
#line 1623 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 194 "xpl.y" /* yacc.c:1646  */
    {
                                                    struct typeTable * t;
                                                    t = getTypeTuple("boolean");
                                                    (yyval.field) = installFieldList((yyvsp[-1].strPointer),t);
                                                }
#line 1633 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 208 "xpl.y" /* yacc.c:1646  */
    {
                                            
                                        }
#line 1641 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 211 "xpl.y" /* yacc.c:1646  */
    {
                                            
                                        }
#line 1649 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 218 "xpl.y" /* yacc.c:1646  */
    {
                                            struct typeTable * typeTableTuple;
                                            char *dataType;
                                            dataType = copyString("integer");
                                            typeTableTuple = getTypeTuple(dataType);
                                            installAllVariables((yyvsp[-1].IDs),typeTableTuple);
                                        }
#line 1661 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 227 "xpl.y" /* yacc.c:1646  */
    {
                                            struct typeTable * typeTableTuple;
                                            char *dataType;
                                            dataType = copyString("boolean");
                                            typeTableTuple = getTypeTuple(dataType);
                                            installAllVariables((yyvsp[-1].IDs),typeTableTuple);
                                        }
#line 1673 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 234 "xpl.y" /* yacc.c:1646  */
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
#line 1688 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 250 "xpl.y" /* yacc.c:1646  */
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
#line 1703 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 261 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.IDs) = (yyvsp[0].IDs);
                                        }
#line 1711 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 268 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.IDs) = installVariable((yyvsp[-3].strPointer),NULL,(yyvsp[-1].iValue));
                                        }
#line 1719 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 272 "xpl.y" /* yacc.c:1646  */
    {
                                            int size = 1;
                                            (yyval.IDs) = installVariable((yyvsp[0].strPointer),NULL,size);
                                        }
#line 1728 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 276 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.IDs) = installFunction((yyvsp[-3].strPointer),(yyvsp[-1].args),NULL,NULL);
                                            (yyval.IDs)->isDefined = 0;
                                        }
#line 1737 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 291 "xpl.y" /* yacc.c:1646  */
    {

                                        }
#line 1745 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 295 "xpl.y" /* yacc.c:1646  */
    {

                                        }
#line 1753 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 302 "xpl.y" /* yacc.c:1646  */
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
#line 1811 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 356 "xpl.y" /* yacc.c:1646  */
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
#line 1862 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 404 "xpl.y" /* yacc.c:1646  */
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
#line 1911 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 450 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.strPointer) = (yyvsp[0].strPointer);
                                        }
#line 1919 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 453 "xpl.y" /* yacc.c:1646  */
    {
                                            char *fnName;
                                            fnName = copyString("MAIN");
                                            (yyval.strPointer) = fnName;
                                        }
#line 1929 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 461 "xpl.y" /* yacc.c:1646  */
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
#line 1948 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 475 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.args) = NULL;
                                        }
#line 1956 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 481 "xpl.y" /* yacc.c:1646  */
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
#line 1986 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 507 "xpl.y" /* yacc.c:1646  */
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
#line 2016 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 534 "xpl.y" /* yacc.c:1646  */
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
#line 2047 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 562 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.arg) = makeArgumentNode((yyvsp[0].strPointer));//for saving arguments whose type is unknown(For temporary use)
                                        }
#line 2055 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 566 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.arg) = makeArgumentNode((yyvsp[0].strPointer));//for saving arguments whose type is unknown(For temporary use)
                                            (yyval.arg)->isRef = 1;
                                        }
#line 2064 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 570 "xpl.y" /* yacc.c:1646  */
    {
                                            struct argumentDecl * poi;
                                            poi = (yyvsp[-2].arg);
                                            while(poi->next){
                                                poi = poi->next;
                                            }
                                            poi->next = makeArgumentNode((yyvsp[0].strPointer));
                                        }
#line 2077 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 578 "xpl.y" /* yacc.c:1646  */
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
#line 2093 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 592 "xpl.y" /* yacc.c:1646  */
    {
                                            struct Lsymbol * lsymbolHead;
                                            lsymbolHead = (yyvsp[-1].localVars);
                                            while(lsymbolHead->next){
                                                lsymbolHead = lsymbolHead->next;
                                            }
                                            lsymbolHead->next = (yyvsp[0].localVars);
                                            (yyval.localVars) = (yyvsp[-1].localVars);
                                        }
#line 2107 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 602 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.localVars) =(yyvsp[0].localVars);
                                        }
#line 2115 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 609 "xpl.y" /* yacc.c:1646  */
    {
                                            struct typeTable * typeTableTuple;
                                            char *dataType;
                                            dataType = copyString("integer");
                                            typeTableTuple = getTypeTuple(dataType);
                                            (yyval.localVars) = installAllLocalVariables((yyvsp[-1].Locals),typeTableTuple);
                                            //freeVarList($2);
                                        }
#line 2128 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 619 "xpl.y" /* yacc.c:1646  */
    {
                                            struct typeTable * typeTableTuple;
                                            char *dataType;
                                            dataType = copyString("boolean");
                                            typeTableTuple = getTypeTuple(dataType);
                                            (yyval.localVars) = installAllLocalVariables((yyvsp[-1].Locals),typeTableTuple);
                                            //freeVarList($2);
                                        }
#line 2141 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 629 "xpl.y" /* yacc.c:1646  */
    {
                                            struct typeTable * typeTableTuple;
                                            typeTableTuple = getTypeTuple((yyvsp[-2].strPointer));
                                            if(!typeTableTuple){
                                                printf("Invalid data type %s\n",(yyvsp[-2].strPointer));
                                            }
                                            (yyval.localVars) = installAllLocalVariables((yyvsp[-1].Locals),typeTableTuple);
                                            //freeVarList($2);
                                        }
#line 2155 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 645 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyvsp[0].Locals)->next = (yyvsp[-2].Locals);
                                            (yyval.Locals) = (yyvsp[0].Locals);
                                        }
#line 2164 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 650 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.Locals) = (yyvsp[0].Locals);
                                        }
#line 2172 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 657 "xpl.y" /* yacc.c:1646  */
    {
                                            int size = 1;
                                            (yyval.Locals) = installLocalVariable((yyvsp[0].strPointer),NULL,size);
                                        }
#line 2181 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 666 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = makeOperationNode('I', 3, (yyvsp[-7].nPtr), (yyvsp[-4].nPtr), (yyvsp[-2].nPtr));
                                        }
#line 2189 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 671 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = makeOperationNode('I', 2, (yyvsp[-5].nPtr), (yyvsp[-2].nPtr));
                                        }
#line 2197 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 676 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = makeOperationNode('=', 2, (yyvsp[-3].nPtr), (yyvsp[-1].nPtr));
                                        }
#line 2205 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 682 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = makeOperationNode('=', 2, makeIdNode((yyvsp[-6].strPointer),(yyvsp[-4].nPtr)), (yyvsp[-1].nPtr));
                                        }
#line 2213 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 687 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = makeOperationNode('R', 1, makeIdNode((yyvsp[-2].strPointer),makeConstantNode(0,1)));
                                        }
#line 2221 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 692 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = makeOperationNode('R', 1, makeIdNode((yyvsp[-5].strPointer),(yyvsp[-3].nPtr)));
                                        }
#line 2229 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 697 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = makeOperationNode('W', 1, (yyvsp[-2].nPtr));
                                        }
#line 2237 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 702 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = makeOperationNode('L', 2, (yyvsp[-5].nPtr), (yyvsp[-2].nPtr));
                                        }
#line 2245 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 705 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = makeOperationNode('^',1,(yyvsp[-1].nPtr));
                                        }
#line 2253 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 712 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = makeOperationNode('+', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));
                                        }
#line 2261 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 716 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = makeOperationNode('-', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));
                                        }
#line 2269 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 720 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = makeOperationNode('*', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));
                                        }
#line 2277 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 724 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = makeOperationNode('~', 2, (yyvsp[-3].nPtr), (yyvsp[0].nPtr));
                                        }
#line 2285 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 728 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = makeOperationNode('<', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));
                                        }
#line 2293 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 732 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = makeOperationNode('>', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));
                                        }
#line 2301 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 736 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = makeOperationNode('/', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));
                                        }
#line 2309 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 740 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = makeOperationNode('%', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));
                                        }
#line 2317 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 744 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = (yyvsp[-1].nPtr);
                                        }
#line 2325 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 748 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = makeOperationNode('!', 1, (yyvsp[0].nPtr));
                                        }
#line 2333 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 751 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = makeOperationNode('@',2,(yyvsp[-1].nPtr),(yyvsp[-1].nPtr));
                                        }
#line 2341 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 755 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = makeOperationNode('#',2,(yyvsp[-3].nPtr),(yyvsp[-1].nPtr));
                                        }
#line 2349 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 760 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = (yyvsp[0].nPtr);
                                        }
#line 2357 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 765 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = makeIdNode((yyvsp[0].strPointer),makeConstantNode(0,1));
                                            (yyval.nPtr)->id.isRef = 1;
                                        }
#line 2366 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 770 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = makeIdNode((yyvsp[-3].strPointer),(yyvsp[-1].nPtr));
                                        }
#line 2374 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 774 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = makeIdNode((yyvsp[-3].strPointer),(yyvsp[-1].nPtr));
                                            (yyval.nPtr)->id.isRef = 1;
                                        }
#line 2383 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 779 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = makeConstantNode((yyvsp[0].iValue),1);
                                        }
#line 2391 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 782 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = makeOperationNode('&',2,(yyvsp[-2].nPtr),(yyvsp[0].nPtr));
                                        }
#line 2399 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 785 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = makeOperationNode('|',2,(yyvsp[-2].nPtr),(yyvsp[0].nPtr));
                                        }
#line 2407 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 788 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = makeConstantNode(1,3);
                                        }
#line 2415 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 791 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = makeConstantNode(0,3);
                                        }
#line 2423 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 795 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = makeFunctionNode((yyvsp[-3].strPointer),(yyvsp[-1].fArgExpr));
                                            //printf("%s\n",$1);
                                        }
#line 2432 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 801 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = makeInnerVar((yyvsp[-2].nPtr),(yyvsp[0].strPointer));
                                        }
#line 2440 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 804 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.nPtr) = makeIdNode((yyvsp[0].strPointer),makeConstantNode(0,1));
                                        }
#line 2448 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 810 "xpl.y" /* yacc.c:1646  */
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
#line 2468 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 825 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.fArgExpr) = makeFargNode((yyvsp[0].nPtr));
                                        }
#line 2476 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 828 "xpl.y" /* yacc.c:1646  */
    {
                                            (yyval.fArgExpr) = NULL;                                          
                                        }
#line 2484 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2488 "y.tab.c" /* yacc.c:1646  */
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
#line 833 "xpl.y" /* yacc.c:1906  */



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
    
