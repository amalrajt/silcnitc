%{
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

%} 


%union { 
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
}

%type  <nPtr>       expr
%type  <nPtr>       statement
%type  <nPtr>       statement_list
%type  <nPtr>       InnerVar
%type  <IDs>        declaration
%type  <IDs>        declarations
%type  <Locals>     ldeclaration
%type  <Locals>     ldeclarations

%type  <strPointer> Fname
%type  <arg>        FargsId
%type  <args>       Farg
%type  <args>       Farg_list
%type  <localVars>  ldecl_statement
%type  <localVars>  ldecl_statement_list
%type  <field>      type_attribute_decl
%type  <field>      type_attributes_decl

%type  <fArgExpr>   FcallExpressions

%token <iValue>     START
%token <iValue>     NUMBER
%token <strPointer> VARIABLE
%token <iValue>     READ
%token <iValue>     WRITE
%token <iValue>     IF
%token <iValue>     AND
%token <iValue>     OR
%token <iValue>     NOT
%token <iValue>     TRUE
%token <iValue>     FALSE
%token <iValue>     THEN
%token <iValue>     ELSE
%token <iValue>     ENDIF
%token <iValue>     WHILE
%token <iValue>     DO
%token <iValue>     ENDWHILE
%token <iValue>     READMEM
%token <iValue>     WRITEMEM
%token <iValue>     END
%token <iValue>     DECL
%token <iValue>     ENDDECL
%token <iValue>     INT
%token <iValue>     MAIN
%token <iValue>     CHAR
%token <iValue>     BOOL
%token <iValue>     RETURN
%token <iValue>     TYPE
%token <iValue>     ENDTYPE
%token exitcode

%nonassoc '=' '<' '>'
%left     '+' '-'
%left     '*' '/' AND OR
%left     '%' NOT
         
%%

    start : 
        TYPE type_declaration_list ENDTYPE DECL decl_statement_list ENDDECL Fdef_list END     
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

        |START error END                {
                                            printf("ERROR\n");
                                            exit(0);
                                        }
        ;
    
    statement_list:
        statement_list statement        {
                                            $$ = makeOperationNode('S', 2, $1, $2);
                                        }
        |statement                      {
                                            $$ = $1;
                                        }
        ;



//User Type Declaration
    type_declaration_list:
        type_declaration_list type_declaration  {

                                                }
        |                                       {

                                                }

    type_declaration:                      
        VARIABLE '{' type_attributes_decl '}'   {
                                                    struct typeTable * t;
                                                    t = installType($1,$3);
                                                    //check if any variable refer the this type
                                                    struct Fieldlist * f;
                                                    f = $3;
                                                    while(f){
                                                        if(f->type->size == INVALID){
                                                            if(strcmp($1,f->type->name) == 0){
                                                                f->type = t;
                                                            }
                                                            else{
                                                                printf("Invalid data type %s",f->type->name);
                                                            }
                                                        }
                                                        f = f->next;
                                                    }
                                                }

    type_attributes_decl:
        type_attributes_decl type_attribute_decl 
                                                {
                                                    $2->next = $1;
                                                    $$ = $2;
                                                }
        |type_attribute_decl                    {
                                                    $$ = $1;
                                                }

    type_attribute_decl:
        VARIABLE VARIABLE ';'                   {
                                                    struct typeTable * t;
                                                    t = getTypeTuple($1);
                                                    //Either invalid or referring the enclosed type
                                                    if(t == NULL){
                                                        t = newTypeTuple();
                                                        t->name = $1;
                                                        t->size = INVALID;
                                                    }
                                                    $$ = installFieldList($2,t);
                                                }

        |INT VARIABLE ';'                        {
                                                    struct typeTable * t;
                                                    t = getTypeTuple("integer");
                                                    $$ = installFieldList($2,t);
                                                }

        |BOOL VARIABLE ';'                       {
                                                    struct typeTable * t;
                                                    t = getTypeTuple("boolean");
                                                    $$ = installFieldList($2,t);
                                                }


//Global Declarations




    decl_statement_list:
        decl_statement_list decl_statement
                                        {
                                            
                                        }
        |decl_statement                 {
                                            
                                        }
        ;

    decl_statement:
        INT declarations ';'            
                                        {
                                            struct typeTable * typeTableTuple;
                                            char *dataType;
                                            dataType = copyString("integer");
                                            typeTableTuple = getTypeTuple(dataType);
                                            installAllVariables($2,typeTableTuple);
                                        }
 
        |BOOL declarations ';'            
                                        {
                                            struct typeTable * typeTableTuple;
                                            char *dataType;
                                            dataType = copyString("boolean");
                                            typeTableTuple = getTypeTuple(dataType);
                                            installAllVariables($2,typeTableTuple);
                                        }
        |VARIABLE declarations ';'          {
                                            struct typeTable * typeTableTuple;
                                            typeTableTuple = getTypeTuple($1);
                                            if(typeTableTuple){ 
                                                installAllVariables($2,typeTableTuple);
                                            }
                                            else{
                                                printf("Invalid type %s on %d",$1,lineNumber);
                                            }
                                        }
 
        ;
 

    declarations:
        declarations ',' declaration    
                                        {
                                            struct Gsymbol * head;
                                            head = $1;
                                            while(head->next){
                                                head = head->next;
                                            }
                                            head->next = $3;
                                            $3->next = NULL;
                                            $$ = $1;
                                        }
        | declaration                  
                                        {
                                            $$ = $1;
                                        }
        ;

    declaration:
        VARIABLE '[' NUMBER ']'         
                                        {
                                            $$ = installVariable($1,NULL,$3);
                                        }
        |VARIABLE                       
                                        {
                                            int size = 1;
                                            $$ = installVariable($1,NULL,size);
                                        }
        | Fname '(' Farg_list ')'       {
                                            $$ = installFunction($1,$3,NULL,NULL);
                                            $$->isDefined = 0;
                                        }
        ;



//Functions




    Fdef_list:
        Fdef_list Fdef                  
                                        {

                                        }
        |Fdef                        
                                        {

                                        }


    Fdef:
        INT Fname '(' Farg_list ')' '{' DECL ldecl_statement_list ENDDECL START statement_list END '}'
                                        {
                                            struct typeTable * typeTableTuple;
                                            char * dataType;
                                            dataType = copyString("integer");
                                            typeTableTuple = getTypeTuple(dataType);
                                            if(strcmp($2,"MAIN") == 0){
                                                installFunction($2,NULL,typeTableTuple,NULL);
                                            }
                                            struct Gsymbol * symbolTableEntry;
                                            symbolTableEntry = getSymbolTableTuple($2);
                                            if(symbolTableEntry != NULL){
                                                symbolTableEntry->lsymbols = $8;//To link local symbols
                                                writeBindingsAndArgs(symbolTableEntry->lsymbols,$4);
                                            }
                                            else{
                                                printf("Undeclared Function %s",$2);
                                                return 0;
                                            }
                                            if(checkMultipleLocalDeclaration(symbolTableEntry->lsymbols) == 1){
                                                printf("Error in Function %s",$2);
                                                return 0;
                                            }
                                            if(!isCorrectDeclaration($4,symbolTableEntry->args)){
                                                printf("Invalid Arguments for Function %s\n",$2);
                                                return 0;
                                            }
                                            if(!hasReturnState($11)){
                                                printf("No return statement for Function %s\n",$2);
                                                return 0;
                                            }
                                            symbolTableEntry->isDefined = 1;
                                            //printAllVariables();
                                            //installFunction($2,$4,typeTableTuple,$8);
                                            currLocalTable = symbolTableEntry->lsymbols;
                                            currFunction   = symbolTableEntry;
                                            if(strcmp($2,"MAIN") == 0){
                                                printAllVariables();
                                            }
                                            if(analyse($11)){
                                                initializeRegister();
                                                fprintf(fp,"MOV R0, R0//\tFunction %s Begins here\n",$2);
                                                fprintf(fp,"%s:\n",$2);
                                                fprintf(fp,"PUSH BP\n");
                                                fprintf(fp,"MOV BP,SP\n");
                                                pushForLocalVariables(currLocalTable);
                                                evaluate($11);
                                                fprintf(fp,"MOV R0, R0//\tFunction %s ends here\n",$2);
                                            }
                                            else{
                                                printf("ERROR in Function %s\n",$2);
                                                return 0;
                                            }
                                        }
        |BOOL Fname '(' Farg_list ')' '{' DECL ldecl_statement_list ENDDECL START statement_list END'}'
                                        {
                                            struct typeTable * typeTableTuple;
                                            char * dataType;
                                            dataType            = copyString("boolean");
                                            typeTableTuple      = getTypeTuple(dataType);
                                            if(strcmp($2,"MAIN") == 0){
                                                installFunction($2,NULL,typeTableTuple,NULL);
                                            }
                                            struct Gsymbol * symbolTableEntry;
                                            symbolTableEntry    = getSymbolTableTuple($2);
                                            if(symbolTableEntry != NULL){
                                                symbolTableEntry->lsymbols = $8;//To link local symbols
                                                writeBindingsAndArgs(symbolTableEntry->lsymbols,$4);
                                            }
                                            else{
                                                printf("Undeclared Function %s",$2);
                                                return 0;
                                            }
                                            if(!isCorrectDeclaration($4,symbolTableEntry->args)){
                                                printf("Invalid Arguments for Function %s\n",$2);
                                                return 0;
                                            }
                                            if(!hasReturnState($11)){
                                                printf("No return statement for Function %s\n",$2);
                                                return 0;
                                            }
                                            symbolTableEntry->isDefined = 1;
                                            //printAllVariables();
                                            //installFunction($2,$4,typeTableTuple,$8);
                                            currLocalTable      = symbolTableEntry->lsymbols;
                                            currFunction        = symbolTableEntry;
                                            
                                            if(analyse($11)){
                                                fprintf(fp,"MOV R0, R0//\tFunction %s Begins here\n",$2);
                                                fprintf(fp,"%s:\n",$2);
                                                fprintf(fp,"PUSH BP\n");
                                                fprintf(fp,"MOV BP,SP\n");
                                                pushForLocalVariables(currLocalTable);
                                                evaluate($11);
                                                fprintf(fp,"MOV R0, R0//\tFunction %s ends here\n",$2);
                                            }
                                            else{
                                                printf("ERROR in Function %s\n",$2);
                                                return 0;
                                            }
                                        }

        |VARIABLE Fname '(' Farg_list ')' '{' DECL ldecl_statement_list ENDDECL START statement_list END'}'
                                        {
                                            struct typeTable * typeTableTuple;
                                            typeTableTuple      = getTypeTuple($1);
                                            if(strcmp($2,"MAIN") == 0){
                                                installFunction($2,NULL,typeTableTuple,NULL);
                                            }
                                            struct Gsymbol * symbolTableEntry;
                                            symbolTableEntry    = getSymbolTableTuple($2);
                                            if(symbolTableEntry != NULL){
                                                symbolTableEntry->lsymbols = $8;//To link local symbols
                                                writeBindingsAndArgs(symbolTableEntry->lsymbols,$4);
                                            }
                                            else{
                                                printf("Undeclared Function %s",$2);
                                                return 0;
                                            }
                                            if(!isCorrectDeclaration($4,symbolTableEntry->args)){
                                                printf("Invalid Arguments for Function %s\n",$2);
                                                return 0;
                                            }
                                            if(!hasReturnState($11)){
                                                printf("No return statement for Function %s\n",$2);
                                                return 0;
                                            }
                                            symbolTableEntry->isDefined = 1;
                                            //printAllVariables();
                                            //installFunction($2,$4,typeTableTuple,$8);
                                            currLocalTable      = symbolTableEntry->lsymbols;
                                            currFunction        = symbolTableEntry;
                                            
                                            if(analyse($11)){
                                                fprintf(fp,"MOV R0, R0//\tFunction %s Begins here\n",$2);
                                                fprintf(fp,"%s:\n",$2);
                                                fprintf(fp,"PUSH BP\n");
                                                fprintf(fp,"MOV BP,SP\n");
                                                pushForLocalVariables(currLocalTable);
                                                evaluate($11);
                                                fprintf(fp,"MOV R0, R0//\tFunction %s ends here\n",$2);
                                            }
                                            else{
                                                printf("ERROR in Function %s\n",$2);
                                                return 0;
                                            }
                                        }

    Fname:                              
        VARIABLE                        {
                                            $$ = $1;
                                        }
        |MAIN                           {
                                            char *fnName;
                                            fnName = copyString("MAIN");
                                            $$ = fnName;
                                        }

    Farg_list:
        Farg_list Farg              
                                        {
                                            struct argList * arg;
                                            arg = $1;
                                            if(arg == NULL){
                                                $$ = $2;
                                            }
                                            else{
                                                while(arg->next){
                                                    arg = arg->next;
                                                }
                                                arg->next = $2;
                                                $$ = $1;
                                            }
                                        }
        |                               {
                                            $$ = NULL;
                                        }

    Farg:
        INT FargsId ';'
                                        {
                                            struct typeTable * typeTableTuple;
                                            char *dataType;
                                            dataType = copyString("integer");
                                            typeTableTuple = getTypeTuple(dataType);
                                            struct argList * argument;
                                            argument = NULL;
                                            while($2){
                                                if(argument){
                                                    argument->next = saveFarg($2->name,typeTableTuple);
                                                    if($2->isRef == 1){
                                                        argument->next->isRef = 1;
                                                    }
                                                    argument       = argument->next;
                                                }
                                                else{
                                                    argument = saveFarg($2->name,typeTableTuple);
                                                    if($2->isRef == 1){
                                                        argument->isRef = 1;
                                                    }
                                                    $$       = argument;
                                                }
                                                $2=$2->next;
                                            }
                                        }
        |BOOL FargsId ';'
                                        {
                                            struct typeTable * typeTableTuple;
                                            char *dataType;
                                            dataType = copyString("boolean");
                                            typeTableTuple = getTypeTuple(dataType);
                                            struct argList * argument;
                                            argument = NULL;
                                            while($2){
                                                if(argument){
                                                    argument->next = saveFarg($2->name,typeTableTuple);
                                                    if($2->isRef == 1){
                                                        argument->next->isRef = 1;
                                                    }
                                                    argument       = argument->next;
                                                }
                                                else{
                                                    argument = saveFarg($2->name,typeTableTuple);
                                                    if($2->isRef == 1){
                                                        argument->isRef = 1;
                                                    }
                                                    $$       = argument;
                                                }
                                                $2=$2->next;
                                            }
                                        }        

        |VARIABLE FargsId ';'
                                        {
                                            struct typeTable * typeTableTuple;
                                            typeTableTuple = getTypeTuple($1);
                                            if(!typeTableTuple){
                                                printf("Invalid Data Type %s\n",$1);
                                            }
                                            struct argList * argument;
                                            argument = NULL;
                                            while($2){
                                                if(argument){
                                                    argument->next = saveFarg($2->name,typeTableTuple);
                                                    if($2->isRef == 1){
                                                        argument->next->isRef = 1;
                                                    }
                                                    argument       = argument->next;
                                                }
                                                else{
                                                    argument = saveFarg($2->name,typeTableTuple);
                                                    if($2->isRef == 1){
                                                        argument->isRef = 1;
                                                    }
                                                    $$       = argument;
                                                }
                                                $2=$2->next;
                                            }
                                        }        

    FargsId:
        VARIABLE                        {
                                            $$ = makeArgumentNode($1);//for saving arguments whose type is unknown(For temporary use)
                                        }
        |'&' VARIABLE                        
                                        {
                                            $$ = makeArgumentNode($2);//for saving arguments whose type is unknown(For temporary use)
                                            $$->isRef = 1;
                                        }
        |FargsId ',' VARIABLE           {
                                            struct argumentDecl * poi;
                                            poi = $1;
                                            while(poi->next){
                                                poi = poi->next;
                                            }
                                            poi->next = makeArgumentNode($3);
                                        }
        |FargsId ',' '&' VARIABLE       {
                                            struct argumentDecl * poi;
                                            struct argumentDecl * poi2;
                                            poi = $1;
                                            while(poi->next){
                                                poi = poi->next;
                                            }
                                            poi2 = makeArgumentNode($4);
                                            poi2->isRef = 1;
                                            poi->next = poi2;
                                        }

    ldecl_statement_list:
        ldecl_statement_list ldecl_statement
                                        {
                                            struct Lsymbol * lsymbolHead;
                                            lsymbolHead = $1;
                                            while(lsymbolHead->next){
                                                lsymbolHead = lsymbolHead->next;
                                            }
                                            lsymbolHead->next = $2;
                                            $$ = $1;
                                        }
        |ldecl_statement                
                                        {
                                            $$ =$1;
                                        }
        ;

    ldecl_statement:
        INT ldeclarations ';'            
                                        {
                                            struct typeTable * typeTableTuple;
                                            char *dataType;
                                            dataType = copyString("integer");
                                            typeTableTuple = getTypeTuple(dataType);
                                            $$ = installAllLocalVariables($2,typeTableTuple);
                                            //freeVarList($2);
                                        }
 
        |BOOL ldeclarations ';'            
                                        {
                                            struct typeTable * typeTableTuple;
                                            char *dataType;
                                            dataType = copyString("boolean");
                                            typeTableTuple = getTypeTuple(dataType);
                                            $$ = installAllLocalVariables($2,typeTableTuple);
                                            //freeVarList($2);
                                        }
 
        |VARIABLE ldeclarations ';'            
                                        {
                                            struct typeTable * typeTableTuple;
                                            typeTableTuple = getTypeTuple($1);
                                            if(!typeTableTuple){
                                                printf("Invalid data type %s\n",$1);
                                            }
                                            $$ = installAllLocalVariables($2,typeTableTuple);
                                            //freeVarList($2);
                                        }
 
        ;


        
    ldeclarations:
        ldeclarations ',' ldeclaration    
                                        {
                                            $3->next = $1;
                                            $$ = $3;
                                        }
        |ldeclaration                    
                                        {
                                            $$ = $1;
                                        }
        ;

    ldeclaration:
        VARIABLE                       
                                        {
                                            int size = 1;
                                            $$ = installLocalVariable($1,NULL,size);
                                        }
        ;


    statement :
        IF '(' expr ')' THEN statement_list ELSE statement_list ENDIF ';'
                                        {
                                            $$ = makeOperationNode('I', 3, $3, $6, $8);
                                        }

        |  IF '(' expr ')' THEN statement_list ENDIF ';'
                                        {
                                            $$ = makeOperationNode('I', 2, $3, $6);
                                        }

        |  InnerVar '=' expr ';'            
                                        {
                                            $$ = makeOperationNode('=', 2, $1, $3);
                                        }


        |  VARIABLE '[' expr ']' '=' expr ';'            
                                        {
                                            $$ = makeOperationNode('=', 2, makeIdNode($1,$3), $6);
                                        }

        |  READ '(' VARIABLE ')' ';'    
                                        {
                                            $$ = makeOperationNode('R', 1, makeIdNode($3,makeConstantNode(0,1)));
                                        }

        |  READ '(' VARIABLE '[' expr']' ')' ';'    
                                        {
                                            $$ = makeOperationNode('R', 1, makeIdNode($3,$5));
                                        }

        |  WRITE '(' expr ')' ';'       
                                        {
                                            $$ = makeOperationNode('W', 1, $3);
                                        }

        | WHILE '(' expr ')' DO statement_list ENDWHILE ';'
                                        {
                                            $$ = makeOperationNode('L', 2, $3, $6);
                                        }   
        | RETURN expr ';'               {
                                            $$ = makeOperationNode('^',1,$2);
                                        }

        ;

    expr:  expr '+' expr                
                                        {
                                            $$ = makeOperationNode('+', 2, $1, $3);
                                        }
        |  expr '-' expr                
                                        {
                                            $$ = makeOperationNode('-', 2, $1, $3);
                                        }
        |  expr '*' expr                
                                        {
                                            $$ = makeOperationNode('*', 2, $1, $3);
                                        }
        |  expr '=''=' expr             
                                        {
                                            $$ = makeOperationNode('~', 2, $1, $4);
                                        }
        |  expr '<' expr                
                                        {
                                            $$ = makeOperationNode('<', 2, $1, $3);
                                        }
        |  expr '>' expr                
                                        {
                                            $$ = makeOperationNode('>', 2, $1, $3);
                                        }
        |  expr '/' expr                
                                        {
                                            $$ = makeOperationNode('/', 2, $1, $3);
                                        }
        |  expr '%' expr                
                                        {
                                            $$ = makeOperationNode('%', 2, $1, $3);
                                        }
        |  '(' expr ')'                 
                                        {
                                            $$ = $2;
                                        }
        |  NOT expr                
                                        {
                                            $$ = makeOperationNode('!', 1, $2);
                                        }
        | READMEM '(' expr ')'          {
                                            $$ = makeOperationNode('@',2,$3,$3);
                                        }
        | WRITEMEM '(' expr ',' expr ')'        
                                        {
                                            $$ = makeOperationNode('#',2,$3,$5);
                                        }

        |  InnerVar                     
                                        {
                                            $$ = $1;
                                        } 

        |  '&' VARIABLE                     
                                        {
                                            $$ = makeIdNode($2,makeConstantNode(0,1));
                                            $$->id.isRef = 1;
                                        } 
        |  VARIABLE '[' expr ']'        
                                        {
                                            $$ = makeIdNode($1,$3);
                                        } 
        |  '&' VARIABLE '[' expr ']'        
                                        {
                                            $$ = makeIdNode($2,$4);
                                            $$->id.isRef = 1;
                                        } 
        |  NUMBER                       
                                        {
                                            $$ = makeConstantNode($1,1);
                                        }
        | expr AND expr                 {
                                            $$ = makeOperationNode('&',2,$1,$3);
                                        }
        | expr OR expr                  {
                                            $$ = makeOperationNode('|',2,$1,$3);
                                        }
        | TRUE                          {
                                            $$ = makeConstantNode(1,3);
                                        }
        | FALSE                         {
                                            $$ = makeConstantNode(0,3);
                                        }
        | Fname '(' FcallExpressions ')' 
                                        {
                                            $$ = makeFunctionNode($1,$3);
                                            //printf("%s\n",$1);
                                        }
        ;
    InnerVar:
        InnerVar '.' VARIABLE           {
                                            $$ = makeInnerVar($1,$3);
                                        }
        |VARIABLE                       {
                                            $$ = makeIdNode($1,makeConstantNode(0,1));
                                        }

    FcallExpressions:
        FcallExpressions ',' expr                   
                                        {
                                            if($1){
                                                struct fArgExpression *head;
                                                head = $1;
                                                while(head->next){
                                                    head = head->next;
                                                }
                                                head->next = makeFargNode($3);
                                                $$ = $1;
                                            }
                                            else{
                                                error("");
                                                return 0;
                                            }
                                        }
        |expr                           {
                                            $$ = makeFargNode($1);
                                        }
        |                               {
                                            $$ = NULL;                                          
                                        }


%%


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
    
