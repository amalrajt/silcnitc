#include "globalsymboltable.h"

extern struct Lsymbol * currLocalTable;
extern struct Gsymbol * currFunction;
typedef enum { CONSTANT, ID, OPERATION , FUNC} nodeEnum; 

/* constants */ 
typedef struct { 
    int value;                  /* value of constant */ 
    int type;
} conNodeType; 


struct innerVariable{
    char * name;
    struct innerVariable * next;
};
/* identifiers */ 
typedef struct { 
    union {
      int * intPointer;
      char * charPointer;
      char * booleanPointer;
    };
    struct Gsymbol * GsymbolPointer;
    struct Lsymbol * LsymbolPointer;
    struct typeTable * typeTableTuple;
    char * type;
    char * name;
    struct nodeTypeTag * expressionNode;
    struct innerVariable * innerId;
    int isRef;
} idNodeType; 

/* operators */ 
typedef struct { 
    int oper;                   /* operator */ 
    int nops;                   /* number of operands */ 
    struct nodeTypeTag *op;     /* operands */ 
} oprNodeType; 

typedef struct {
    char * funcName;
    struct fArgExpression * fArgExps;
}funcNodeType;

//For each function call Arguments
struct fArgExpression{
    struct nodeTypeTag * exprNode;
    struct fArgExpression * next;
} ;

struct nodeTypeTag { 
    nodeEnum nodeClass;         /* type of node */ 
    char * dataType;
    int lineNumber;
    union { 
        conNodeType con;        /* constants */ 
        idNodeType id;          /* identifiers */ 
        oprNodeType opr;        /* operators */ 
        funcNodeType func;      /* Functions */
    }; 
};

typedef struct nodeTypeTag NodeType;

//Expression Tree Related Functions//

    struct nodeTypeTag * makeOperationNode(int oper, int nops, ...); 
    struct nodeTypeTag * makeIdNode(char * varName, struct nodeTypeTag * expressionNode);
    struct nodeTypeTag * makeConstantNode(int value,int type);
    void freeNode(struct nodeTypeTag *p); 
    int evaluate(struct nodeTypeTag *p); 
    int hasReturnState(struct nodeTypeTag *p);
    void pushForLocalVariables(struct Lsymbol *lsymbols);
    int analyse(struct nodeTypeTag *p); 

//For function Call
    struct fArgExpression * makeFargNode(struct nodeTypeTag * exprNode);
    struct nodeTypeTag * makeFunctionNode(char * funcName, struct fArgExpression * fArgs);
//Basic Functions
    char * copyString(char * source);
    struct nodeTypeTag * makeInnerVar(struct nodeTypeTag * Id,char * name);
    struct typeTable * getFieldType(char * name,struct typeTable * type);

    extern int lineNumber;

    FILE *fp;
    