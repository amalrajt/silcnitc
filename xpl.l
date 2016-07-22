%{
#include "y.tab.h"
#include <stdlib.h>
#include <stdio.h>
struct fileNodes{
    char * filename;
    struct fileNodes * next;
};
extern int lineNumber;
int preprocessed = 0;
struct fileNodes * fileHeader;
char * filename;
%}

number          [0-9]+
idChars         [a-z]|[A-Z]|_
comment         [.\n]+

%%

{number}                                {
                                            yylval.iValue = atoi (yytext);
                                            return NUMBER;
                                        }

[ \t]                                   {

                                        }

[-+*/%()=<>{};.,&]                       {
                                            return *yytext;
                                        }

"]"|"["                                  {
                                            return *yytext;
                                        }

read|READ                               {
                                            return READ;
                                        }

write|WRITE                             {
                                            return WRITE;
                                        }

if|IF                                   {
                                            return IF;
                                        }

then|THEN                               {
                                            return THEN;
                                        }

ELSE|else                               {
                                            return ELSE;
                                        }

endif|ENDIF                             {
                                            return ENDIF;
                                        }

AND|and                                 {
                                            return AND;
                                        }

OR|or                                   {
                                            return OR;
                                        }

NOT|not                                 {
                                            return NOT;
                                        }

TRUE|true                               {
                                            return TRUE;
                                        }

FALSE|false                             {
                                            return FALSE;
                                        }

END|end                                 {
                                            return END;
                                        }

BEGIN|begin                             {
                                            return START;
                                        }

WHILE|while                             {
                                            return WHILE;
                                        }

DO|do                                   {
                                            return DO;
                                        }

ENDWHILE|endwhile                       {
                                            return ENDWHILE;
                                        }

READMEM|readmem                         {
                                            return READMEM;
                                        }

WRITEMEM|writemem                       {
                                            return WRITEMEM;
                                        }

DECL|decl                               {
                                            return DECL;
                                        }

INTEGER|integer                         {
                                            return INT;
                                        }

CHAR|char                               {
                                            return CHAR;
                                        }

BOOLEAN|boolean                         {
                                            return BOOL;
                                        }

ENDDECL|enddecl                         {
                                            return ENDDECL;
                                        }

MAIN|main                               {
                                            return MAIN;
                                        }

RETURN|return                           {
                                            return RETURN;
                                        }

TYPE|type                               {
                                            return TYPE;
                                        }

ENDTYPE|endtype                         {
                                            return ENDTYPE;
                                        }

{idChars}+                              {
                                            char * identifier;
                                            identifier = malloc(yyleng + 1);
                                            strcpy(identifier,yytext);
                                            yylval.strPointer = identifier;
                                            return VARIABLE;
                                        }

.                                       {
                                            
                                        }

\n                                      {
                                            lineNumber += 1;
                                        }


"/*"([a-z]|[0-9]|[A-Z]|" "|\n)+"*/"        {

                                        }
%%

int yywrap()
{
    if(!fileHeader->next){
        return 1;
    }
    fileHeader = fileHeader->next;
    printf("Processing %s",fileHeader->filename);
    FILE *sourceCode = fopen(fileHeader->filename, "r");
    extern FILE *yyin;
    yyin = sourceCode;
    filename = NULL;
    lineNumber = 0;
    return 0;
}


