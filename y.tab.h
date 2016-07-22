/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

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
#line 43 "xpl.y" /* yacc.c:1909  */
 
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

#line 132 "y.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
