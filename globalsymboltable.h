#include "typetable.h"
//Argument List for Functions
  struct argList{
    char *name;
    struct typeTable *type;
    struct argList *next;
    int isRef;
  };
//For Symbol Table
  struct Gsymbol{
    char *name;               //name of the variable or function
    struct typeTable *type;   //pointer to the Typetable entry of variable type/return type of the function
    int size;                 //size of an array. (The size of all other types of variables is 1) 
    int binding;              //stores static memory address allocated to the variable
    struct argList *args;
    int numArgs;
    struct Lsymbol *lsymbols;
    struct Gsymbol *next;
    int isDefined;
  };
//For Symbol Table
  struct Lsymbol{
    char *name;               //name of the variable or function
    struct typeTable *type;   //pointer to the Typetable entry of variable type/return type of the function
    int size;                 //size of an array. (The size of all other types of variables is 1) 
    int binding;              //stores static memory address allocated to the variable;
    struct Lsymbol *next;
  };
//Single Structure for pointing any data type
  struct variablePointer{
    char * type;
    union {
      int * intPointer;
      char * charPointer;
      char * booleanPointer;
    };
  };
//For storing size and name of variables
  struct variableDecl{
    char * name;
    int size;//No of indexes eg. a[10] has index =10
    struct variableDecl * next;
  };
//For storing size and name of arguments
  struct argumentDecl{
    char * name;
    struct argumentDecl * next;
    int isRef;
  };
//Symbol Table Global Variables//
    struct Gsymbol *GsymbolHead;
    struct Gsymbol *GsymbolTail;

//Functions and Data structures for variables

    struct Gsymbol * installVariable(char * name,struct typeTable * typeTableTuple, int arraySize);
    struct Gsymbol * installVariableRaw(char * name,char * type, int arraySize);
    int findVariableBinding(char * variableName, int shift);
    int getVariableBinding(struct Gsymbol * variable, int shift);
    struct Gsymbol * getVariable(char * name);
    void printAllVariables();
    void installAllVariables(struct Gsymbol * idList,struct typeTable * typeTableTuple);

//Functions for 'Functions'
  struct argList * saveFarg(char * name,struct typeTable * typeTableTuple);
  struct Gsymbol * installFunction(char * name,struct argList * args, struct typeTable * typeTableTuple, struct Lsymbol * lsymbols);
  struct Lsymbol * installLocalVariable(char * name,struct typeTable * typeTableTuple, int arraySize);
  struct Lsymbol * installAllLocalVariables(struct Lsymbol * idList,struct typeTable * typeTableTuple);
  struct Gsymbol * getSymbolTableTuple(char * name);
  void writeBindingsAndArgs(struct Lsymbol * localVar,struct argList *argument);
  int isCorrectDeclaration(struct argList * argument,struct argList * actualArgument);
  int getLocalVariableBinding(char * name,struct Lsymbol * variable);
  struct Lsymbol * getLocalTableEntry(char * name,struct Lsymbol * variable);
//

  int checkMultipleLocalDeclaration(struct Lsymbol * head1);
  int checkMultipleDeclaration();
  void initializeRegister();