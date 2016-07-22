#include "nodetype.h"
int currentRegister = 0;
int currPushLevel[] = {-1,-1,-1,-1,-1,-1,-1,-1};
int currentLabel    = 0;
//Expression Tree Related Functions
struct nodeTypeTag * makeConstantNode(int value,int type) {
    struct nodeTypeTag *p;
    /* allocate node */
    p               = malloc(sizeof(struct nodeTypeTag));
    if (p == NULL)
        outOfMemory();
    /* copy information */
    p->lineNumber   = lineNumber;
    p->nodeClass    = CONSTANT;
    p->con.type     = type;
    p->con.value    = value;
    return p;
}
struct nodeTypeTag * makeIdNode(char * varName, struct nodeTypeTag * expressionNode) { 
    struct nodeTypeTag *p; 
    /* allocate node */ 
    p                       = malloc(sizeof(struct nodeTypeTag));
    if (p == NULL) 
        outOfMemory();
    /* copy information */ 
    p->nodeClass            = ID; 
    p->lineNumber           = lineNumber; 
    p->id.name              = varName; 
    p->id.innerId              = NULL;
    //Expression Node for Finding Shift amount
    struct Gsymbol * GsymbolPointer;
    p->id.expressionNode    = expressionNode;
    GsymbolPointer          = getVariable(varName);
    //Saving Global Table entry of current Variable
    p->id.GsymbolPointer    = GsymbolPointer;
    p->id.isRef             = 0;
    return p; 
}
struct nodeTypeTag * makeOperationNode(int oper, int nops, ...) {
    va_list ap;
    struct nodeTypeTag *p;
    int i;
    /* allocate node */
    p               = malloc(sizeof(struct nodeTypeTag));
    if (p == NULL){
        outOfMemory();
    }
    p->opr.op = malloc(nops * sizeof(struct nodeTypeTag));
    if (p->opr.op == NULL){
        outOfMemory();
    }
    /* copy information */
    p->nodeClass    = OPERATION;
    p->lineNumber   = lineNumber;
    p->opr.oper     = oper;
    p->opr.nops     = nops;
    va_start(ap, nops);
    for (i = 0; i < nops; i++)
        p->opr.op[i]= *va_arg(ap, struct nodeTypeTag *);
    va_end(ap);
    return p;
}
struct nodeTypeTag * makeInnerVar(struct nodeTypeTag * Id,char * name){
    struct innerVariable * head;
    head = Id->id.innerId;
    struct innerVariable * newInnerId;
    newInnerId = malloc(sizeof(struct innerVariable));
    newInnerId->name = name;
    newInnerId->next = NULL;
    if(!head){
        Id->id.innerId = newInnerId;
        return Id;
    }
    while(head->next){
        head = head->next;
    }
    head->next = newInnerId;
    return Id;
}
//For function Arguments
struct fArgExpression * makeFargNode(struct nodeTypeTag * exprNode){
    struct fArgExpression * fArg;
    fArg            = malloc(sizeof(struct fArgExpression));
    fArg->exprNode  = exprNode;
    fArg->next      = NULL;
    return fArg;
}

//For the node for functions
struct nodeTypeTag * makeFunctionNode(char * funcName, struct fArgExpression * fArgExps){
    struct nodeTypeTag *p; 
    /* allocate node */ 
    p                   = malloc(sizeof(struct nodeTypeTag));
    if (p == NULL) 
        outOfMemory();
    /* copy information */ 
    p->nodeClass        = FUNC; 
    p->lineNumber       = lineNumber; 
    p->func.funcName    = funcName;
    p->func.fArgExps    = fArgExps;
    return p;
}

//To reverse the srgument expressions for functions
struct fArgExpression * reverseArgList(struct fArgExpression * fArgExps){
    struct fArgExpression * fArgExpsArr[20];
    int i=0,j;
    while(fArgExps){
        fArgExpsArr[i]          = fArgExps;
        fArgExps                = fArgExps->next;
        i                       = i+1;
    }
    fArgExpsArr[0]->next        = NULL;
    for(j=i-1;j>0;j--){
        fArgExpsArr[j]->next    = fArgExpsArr[j-1];
    }
    return fArgExpsArr[i-1];
}

int getRegister(){
    currentRegister                     = (currentRegister+1)%8;
    if(currentRegister == 0){
        currPushLevel[currentRegister] += 1;
    }
    else{
        currPushLevel[currentRegister] = currPushLevel[currentRegister-1]; 
    }
    if(currPushLevel[currentRegister] > 0){
        fprintf(fp, "PUSH R%d\n", currentRegister);
    }
    return currentRegister;
}

struct typeTable * getFieldType(char * name,struct typeTable * type){
    struct Fieldlist * fields;
    fields = type->fields;
    while(fields){
        if(strcmp(fields->name,name)==0){
            return fields->type;
        }
        fields = fields->next;
    }
    return NULL;
}

int releaseRegister(){
    if((currentRegister == 0)&&(currPushLevel[currentRegister] <= 0)){
        currentRegister         = 0;
        return 0;
    }
    if(currPushLevel[currentRegister] > 0)
        fprintf(fp, "POP R%d\n", currentRegister);
    currPushLevel[currentRegister]--;
    currentRegister             = (currentRegister + 7)%8;
    return 0;
}
int getPrevRegister(){
    //printf("%d\n",(currentRegister + 7)%8);
    return (currentRegister - 1)%8;
}
int freePushLevel(){
    int i;
    for(i=0;i<8;i++){
        currPushLevel[i]        = -1;
    }
    currentRegister             = 0;
    return 0;
}

void pushUptoCurrRegister(){
    int i                       =0;
    while(i<=currentRegister){
        fprintf(fp, "PUSH R%d\n", i);
        i++;
    }
}

void popUptoCurrRegister(){
    int i=currentRegister;
    while(i>=0){
        fprintf(fp, "POP R%d\n", i);
        i-=1;
    }
}

void initializeRegister(){
    int i=0;
    for(i=0;i<8;i++){
        currPushLevel[i]=-1;
    }
    int currentRegister = 0;
}

int evaluate(struct nodeTypeTag *p){
    struct fArgExpression * argExpRev;
    struct fArgExpression * argExpRevHead;
    struct Gsymbol * funcGsymbolPoi;
    struct argList * arguments;
    struct nodeTypeTag * idNode;

    struct typeTable * type;
    struct innerVariable * head;

    int localCurrentLabel1;
    int localCurrentLabel2;
    int binding;
    if(p == NULL){
        return 0;
    }
    switch(p->nodeClass){
        case CONSTANT : 
                        getRegister();
                        fprintf(fp,"MOV R%d, %d\n",currentRegister,p->con.value);
                        return 0;
        case ID       : 
                        //Check if variable is in Local Table
                        if(getLocalVariableBinding(p->id.name,currLocalTable) != 0){
                            //For user defined data types
                            if(p->id.innerId){
                                //Accessing the main Pointer
                                fprintf(fp,"MOV R0, R0//\tAttribute Problem\n");
                                fprintf(fp,"MOV R0, R0//\tAccessing local variable %s binding %d\n",p->id.name,getLocalVariableBinding(p->id.name,currLocalTable));
                                getRegister();
                                fprintf(fp, "MOV R%d, %d\n", currentRegister,(getLocalVariableBinding(p->id.name,currLocalTable)));
                                getRegister();
                                fprintf(fp, "MOV R%d, BP\n", currentRegister);
                                fprintf(fp, "ADD R%d, R%d\n",getPrevRegister(),currentRegister);
                                releaseRegister();
                                fprintf(fp, "MOV R%d, [R%d]\n",currentRegister,currentRegister);
                                type = p->id.LsymbolPointer->type;
                                head = p->id.innerId;
                                //For accessing the heap
                                while(head){
                                    fprintf(fp,"MOV R0, R0//\tAccessing attribute %s binding %d\n",head->name,getAttributeBinding(head->name,type));
                                    getRegister();
                                    fprintf(fp, "MOV R%d, %d\n", currentRegister,(getAttributeBinding(head->name,type)));
                                    fprintf(fp, "ADD R%d, R%d\n",getPrevRegister(), currentRegister);
                                    releaseRegister();
                                    fprintf(fp, "MOV R%d, [R%d]\n",currentRegister,currentRegister);
                                    type = getFieldType(head->name,type);
                                    head = head->next;
                                }
                                return 0;
                            }
                            fprintf(fp,"MOV R0, R0//\tAccessing local variable %s binding %d\n",p->id.name,getLocalVariableBinding(p->id.name,currLocalTable));
                            getRegister();
                            fprintf(fp, "MOV R%d, %d\n", currentRegister,(getLocalVariableBinding(p->id.name,currLocalTable)));
                            getRegister();
                            fprintf(fp, "MOV R%d, BP\n", currentRegister);
                            fprintf(fp, "ADD R%d, R%d\n",getPrevRegister(),currentRegister);
                            releaseRegister();
                            fprintf(fp, "MOV R%d, [R%d]\n",currentRegister,currentRegister);
                        }
                        //If variable is not in Local Table
                        else{
                            //For user defined data types
                            if(p->id.innerId){
                                //Accessing the main Pointer
                                fprintf(fp,"MOV R0, R0//\tAttribute Problem\n");
                                fprintf(fp,"MOV R0, R0//\tAccessing global variable %s binding %d\n",p->id.name,getVariableBinding(p->id.GsymbolPointer,0));
                                getRegister();
                                fprintf(fp, "MOV R%d, %d\n", currentRegister,(getVariableBinding(p->id.GsymbolPointer,0)));
                                getRegister();
                                fprintf(fp, "MOV R%d, 1000\n", currentRegister);
                                fprintf(fp, "ADD R%d, R%d\n",getPrevRegister(),currentRegister);
                                releaseRegister();
                                fprintf(fp, "MOV R%d, [R%d]\n",currentRegister,currentRegister);
                                type = p->id.GsymbolPointer->type;
                                head = p->id.innerId;
                                //For accessing the heap
                                while(head){
                                    fprintf(fp,"MOV R0, R0//\tAccessing attribute %s binding %d\n",head->name,getAttributeBinding(head->name,type));
                                    getRegister();
                                    fprintf(fp, "MOV R%d, %d\n", currentRegister,(getAttributeBinding(head->name,type)));
                                    fprintf(fp, "ADD R%d, R%d\n",getPrevRegister(), currentRegister);
                                    releaseRegister();
                                    fprintf(fp, "MOV R%d, [R%d]\n",currentRegister,currentRegister);
                                    type = getFieldType(head->name,type);
                                    head = head->next;
                                }
                                return 0;
                            }
                            fprintf(fp,"MOV R0, R0//\tAccessing global variable %s binding %d\n",p->id.name,getVariableBinding(p->id.GsymbolPointer,0));
                            getRegister();
                            fprintf(fp, "MOV R%d, %d\n", currentRegister,(getVariableBinding(p->id.GsymbolPointer,0)));
                            getRegister();
                            fprintf(fp, "MOV R%d, 1000\n", currentRegister);
                            fprintf(fp, "ADD R%d, R%d\n",getPrevRegister(),currentRegister);
                            releaseRegister();
                            evaluate(p->id.expressionNode);
                            fprintf(fp, "ADD R%d, R%d\n", getPrevRegister(), currentRegister);
                            releaseRegister();
                            fprintf(fp, "MOV R%d, [R%d]\n", currentRegister,currentRegister);
                        }
                        return 0;
        
        case FUNC:
                    //freePushLevel();
                    fprintf(fp,"MOV R0, R0//\tPushing All Used Registers(%d)\n",currentRegister);
                    pushUptoCurrRegister();
                    fprintf(fp,"MOV R0, R0//\tCalling Function %s\n",p->func.funcName);
                    //Pushing Arguments
                    if(p->func.fArgExps){
                        argExpRevHead       = reverseArgList(p->func.fArgExps);
                        argExpRev           = argExpRevHead;
                        
                        while(argExpRev){
                            evaluate(argExpRev->exprNode);
                            fprintf(fp, "PUSH R%d\n",currentRegister);
                            releaseRegister();
                            argExpRev = argExpRev->next;
                        }                        
                    }
                    //For return Value
                    fprintf(fp,"MOV R0, R0//\tFor return Address\n");
                    fprintf(fp, "PUSH R%d\n",currentRegister);
                    fprintf(fp, "CALL %s\n",p->func.funcName);
                    //Setting SP
                    //fprintf(fp, "MOV SP, BP\n");
                    getRegister();
                    fprintf(fp,"MOV R0, R0//\tTo Get The Return Value\n");
                    //Get The Return Value
                    fprintf(fp,"POP R%d\n",currentRegister);
                    //POPs arguments
                    fprintf(fp,"MOV R0, R0//\tRemoving Arguments\n");
                    if(p->func.fArgExps){
                        //Revesed List of Argument Expressions for Function Call
                        argExpRev           = reverseArgList(argExpRevHead);
                        funcGsymbolPoi      = getSymbolTableTuple(p->func.funcName);
                        arguments           = funcGsymbolPoi->args;
                        while(argExpRev){
                            if(arguments->isRef==1){
                                fprintf(fp, "MOV R0, R0//\tCall By Reference Problem\n");
                                //Get The Binding of Variable
                                idNode      = argExpRev->exprNode;
                                binding     = getLocalVariableBinding(idNode->id.name,currLocalTable);
                                if( binding != 0){
                                    if(idNode->id.innerId){
                                        fprintf(fp, "MOV R0, R0//\tAttribute Problem\n");
                                        getRegister();
                                        fprintf(fp, "POP R%d\n",currentRegister);
                                        fprintf(fp, "MOV R0, R0//\tAccessing local variable %s binding %d\n",idNode->id.name,binding);
                                        getRegister();
                                        fprintf(fp, "MOV R%d, %d\n", currentRegister,binding);
                                        getRegister();
                                        fprintf(fp, "MOV R%d, BP\n",currentRegister);
                                        fprintf(fp, "ADD R%d, R%d\n",getPrevRegister(),currentRegister);
                                        releaseRegister();
                                        fprintf(fp, "MOV R%d, [R%d]\n",currentRegister,currentRegister);
                                        head = idNode->id.innerId;
                                        idNode->id.LsymbolPointer = getLocalTableEntry(idNode->id.name,currLocalTable);
                                        type = idNode->id.LsymbolPointer->type;
                                        while(head){
                                            fprintf(fp,"MOV R0, R0//\tAccessing attribute %s binding %d\n",head->name,getAttributeBinding(head->name,type));
                                            getRegister();
                                            fprintf(fp, "MOV R%d, %d\n", currentRegister,(getAttributeBinding(head->name,type)));
                                            fprintf(fp, "ADD R%d, R%d\n",getPrevRegister(), currentRegister);
                                            releaseRegister();
                                            if(head->next)
                                            fprintf(fp, "MOV R%d, [R%d]\n",currentRegister,currentRegister);
                                            type = getFieldType(head->name,type);
                                        
                                            head = head->next;
                                        }

                                        fprintf(fp, "MOV [R%d], R%d\n",currentRegister,getPrevRegister());
                                        releaseRegister();
                                        releaseRegister();

                                    }
                                    else{
                                        getRegister();
                                        getRegister();
                                        fprintf(fp, "POP R%d\n",getPrevRegister());
                                        fprintf(fp, "MOV R0, R0//\tAccessing local variable %s binding %d\n",idNode->id.name,binding);
                                        fprintf(fp, "MOV R%d, %d\n",currentRegister,binding);
                                        getRegister();
                                        fprintf(fp, "MOV R%d, BP\n",currentRegister);
                                        fprintf(fp, "ADD R%d, R%d\n",getPrevRegister(),currentRegister);
                                        releaseRegister();
                                        fprintf(fp, "MOV [R%d], R%d\n",currentRegister,getPrevRegister());
                                        releaseRegister();
                                        releaseRegister();
                                    }
                                }
                                //If variable is not in Local Table
                                else{
                                    if(idNode->id.innerId){
                                        fprintf(fp, "MOV R0, R0//\tAttribute Problem\n");
                                        getRegister();
                                        fprintf(fp, "POP R%d\n",currentRegister);
                                        fprintf(fp, "MOV R0, R0//\tAccessing global variable %s binding %d\n",idNode->id.name,getVariableBinding(idNode->id.GsymbolPointer,0));
                                        getRegister();
                                        fprintf(fp, "MOV R%d, %d\n", currentRegister,(getVariableBinding(idNode->id.GsymbolPointer,0)));
                                        getRegister();
                                        fprintf(fp, "MOV R%d, 1000\n",currentRegister);
                                        fprintf(fp, "ADD R%d, R%d\n",getPrevRegister(),currentRegister);
                                        releaseRegister();
                                        
                                        head = p->id.innerId;
                                        type = p->id.GsymbolPointer->type;
                                        while(head){
                                            fprintf(fp,"MOV R0, R0//\tAccessing attribute %s binding %d\n",head->name,getAttributeBinding(head->name,type));
                                            getRegister();
                                            fprintf(fp, "MOV R%d, %d\n", currentRegister,(getAttributeBinding(head->name,type)));
                                            fprintf(fp, "ADD R%d, R%d\n",getPrevRegister(), currentRegister);
                                            releaseRegister();
                                            fprintf(fp, "MOV R%d, [R%d]\n",currentRegister,currentRegister);
                                            type = getFieldType(head->name,type);
                                            head = head->next;
                                        }

                                        fprintf(fp, "MOV [R%d], R%d\n",currentRegister,getPrevRegister());

                                    }
                                    else{
                                        getRegister();
                                        fprintf(fp, "POP R%d\n",currentRegister);
                                        fprintf(fp, "MOV R0, R0//\tAccessing global variable %s binding %d\n",idNode->id.name,getVariableBinding(idNode->id.GsymbolPointer,0));
                                        getRegister();
                                        fprintf(fp, "MOV R%d, %d\n", currentRegister,(getVariableBinding(idNode->id.GsymbolPointer,0)));
                                        getRegister();
                                        fprintf(fp, "MOV R%d, 1000\n",currentRegister);
                                        fprintf(fp, "ADD R%d, R%d\n",getPrevRegister(),currentRegister);
                                        releaseRegister();
                                        evaluate(idNode->id.expressionNode);
                                        fprintf(fp, "ADD R%d, R%d\n", getPrevRegister(), currentRegister);
                                        releaseRegister();
                                        fprintf(fp, "MOV [R%d], R%d\n", currentRegister,getPrevRegister());
                                        releaseRegister();
                                        releaseRegister();
                                    }
                                }
                            
                            }
                            else{
                                fprintf(fp, "POP R0\n");
                            }
                            argExpRev = argExpRev->next;
                            arguments = arguments->next;
                        }
                    }
                    fprintf(fp,"MOV R0, R0//\tRestoring Registers\n");
                    releaseRegister();
                    popUptoCurrRegister();
                    getRegister();
                    return 0;

        case OPERATION:
                switch(p->opr.oper){
                    case '+' : 
                                evaluate(&(p->opr.op[0]));
                                evaluate(&p->opr.op[1]);
                                fprintf(fp,"ADD R%d, R%d\n",getPrevRegister(),currentRegister);
                                releaseRegister();
                                return 1;
                    case '@' :
                                fprintf(fp,"MOV R0, R0 // Reading Memory\n");
                                evaluate(&p->opr.op[0]);
                                fprintf(fp,"MOV R%d, [R%d]\n",currentRegister ,currentRegister);
                                return 1;

                    case '#' :
                                fprintf(fp,"MOV R0, R0 // Writing to Memory\n");
                                evaluate(&p->opr.op[0]);
                                evaluate(&p->opr.op[1]);
                                fprintf(fp,"MOV [R%d], R%d\n",getPrevRegister() ,currentRegister);
                                releaseRegister();
                                return 1;


                    case '-' :  
                                evaluate(&p->opr.op[0]);
                                evaluate(&p->opr.op[1]);
                                fprintf(fp,"SUB R%d, R%d\n",getPrevRegister(),currentRegister);
                                releaseRegister();
                                return 1;
                    case '*' :      
                                evaluate(&p->opr.op[0]);
                                evaluate(&p->opr.op[1]);
                                fprintf(fp,"MUL R%d, R%d\n",getPrevRegister(),currentRegister);
                                releaseRegister();
                                return 1;
                                break;
                    case '/' :      
                                evaluate(&p->opr.op[0]);
                                evaluate(&p->opr.op[1]);
                                fprintf(fp,"DIV R%d, R%d\n",getPrevRegister(),currentRegister);
                                releaseRegister();
                                return 1;
                    case '%' :      
                                evaluate(&p->opr.op[0]);
                                evaluate(&p->opr.op[1]);
                                fprintf(fp,"MOD R%d, R%d\n",getPrevRegister(),currentRegister);
                                releaseRegister();
                                return 1;
                    case '~' : 
                                evaluate(&p->opr.op[0]);
                                evaluate(&p->opr.op[1]);
                                fprintf(fp,"EQ R%d, R%d\n",getPrevRegister(),currentRegister);
                                releaseRegister();
                                return 1;
                    case '<' : 
                                evaluate(&p->opr.op[0]);
                                evaluate(&p->opr.op[1]);
                                fprintf(fp,"LT R%d, R%d\n",getPrevRegister(),currentRegister);
                                releaseRegister();
                                return 1;
                    case '>' : 
                                evaluate(&p->opr.op[0]);
                                evaluate(&p->opr.op[1]);
                                fprintf(fp,"GT R%d, R%d\n",getPrevRegister(),currentRegister);
                                releaseRegister();
                                return 1;
                    case '=' : 
                                /*To Get The Shift Amount*/
                                //getRegister();
                                if(getLocalVariableBinding(p->opr.op[0].id.name,currLocalTable) != 0){
                                    if(p->opr.op[0].id.innerId){
                                        //Accessing the main Pointer
                                        fprintf(fp,"MOV R0, R0//\tAttribute Problem\n");
                                        fprintf(fp,"MOV R0, R0//\tAccessing local variable %s binding %d\n",p->opr.op[0].id.name,getLocalVariableBinding(p->opr.op[0].id.name,currLocalTable));
                                        fprintf(fp, "MOV R%d, %d\n", currentRegister,(getLocalVariableBinding(p->opr.op[0].id.name,currLocalTable)));
                                        getRegister();
                                        fprintf(fp, "MOV R%d, BP\n", currentRegister);
                                        fprintf(fp, "ADD R%d, R%d\n",getPrevRegister(),currentRegister);
                                        releaseRegister();
                                        type = p->opr.op[0].id.LsymbolPointer->type;
                                        head = p->opr.op[0].id.innerId;
                                        //For accessing the heap
                                        while(head){
                                            fprintf(fp, "MOV R%d, [R%d]\n",currentRegister,currentRegister);
                                            fprintf(fp,"MOV R0, R0//\tAccessing attribute %s binding %d\n",head->name,getAttributeBinding(head->name,type));
                                            getRegister();
                                            fprintf(fp, "MOV R%d, %d\n", currentRegister,(getAttributeBinding(head->name,type)));
                                            fprintf(fp, "ADD R%d, R%d\n",getPrevRegister(), currentRegister);
                                            releaseRegister();
                                            type = getFieldType(head->name,type);
                                            head = head->next;
                                        }
                                    }
                                    else{
                                        fprintf(fp,"MOV R0, R0//\tAccessing local variable %s binding %d for =\n",p->opr.op[0].id.name,getLocalVariableBinding(p->opr.op[0].id.name,currLocalTable));
                                        fprintf(fp, "MOV R%d, %d\n", currentRegister,(getLocalVariableBinding(p->opr.op[0].id.name,currLocalTable)));
                                        getRegister();
                                        fprintf(fp, "MOV R%d, BP\n", currentRegister);
                                        fprintf(fp, "ADD R%d, R%d\n",getPrevRegister(),currentRegister);
                                        releaseRegister();
                                    }
                                }
                                else{
                                    //For user defined data types
                                    if(p->opr.op[0].id.innerId){
                                        //Accessing the main Pointer
                                        fprintf(fp,"MOV R0, R0//\tAttribute Problem\n");
                                        fprintf(fp,"MOV R0, R0//\tAccessing global variable %s binding %d\n",p->opr.op[0].id.name,getVariableBinding(p->opr.op[0].id.GsymbolPointer,0));
                                        fprintf(fp, "MOV R%d, %d\n", currentRegister,(getVariableBinding(p->opr.op[0].id.GsymbolPointer,0)));
                                        getRegister();
                                        fprintf(fp, "MOV R%d, 1000\n", currentRegister);
                                        fprintf(fp, "ADD R%d, R%d\n",getPrevRegister(),currentRegister);
                                        releaseRegister();
                                
                                        type = p->opr.op[0].id.GsymbolPointer->type;
                                        head = p->opr.op[0].id.innerId;
                                        //For accessing the heap
                                        while(head){
                                            fprintf(fp, "MOV R%d, [R%d]\n",currentRegister,currentRegister);
                                            fprintf(fp,"MOV R0, R0//\tAccessing attribute %s binding %d\n",head->name,getAttributeBinding(head->name,type));
                                            getRegister();
                                            fprintf(fp, "MOV R%d, %d\n", currentRegister,(getAttributeBinding(head->name,type)));
                                            fprintf(fp, "ADD R%d, R%d\n",getPrevRegister(), currentRegister);
                                            releaseRegister();
                                            type = getFieldType(head->name,type);
                                            head = head->next;
                                        }
                                    }
                                    else{
                                        //getRegister();
                                        fprintf(fp,"MOV R0, R0//\tAccessing Global variable %s binding %d for =\n",p->opr.op[0].id.name,getVariableBinding(p->opr.op[0].id.GsymbolPointer,0));
                                        fprintf(fp, "MOV R%d, %d\n", currentRegister,(getVariableBinding(p->opr.op[0].id.GsymbolPointer,0))); 
                                        getRegister();
                                        fprintf(fp, "MOV R%d, 1000\n", currentRegister);
                                        fprintf(fp, "ADD R%d, R%d\n",getPrevRegister(),currentRegister);
                                        releaseRegister();  
                                        evaluate(p->opr.op[0].id.expressionNode);
                                        fprintf(fp, "ADD R%d, R%d\n", getPrevRegister(), currentRegister);
                                        releaseRegister();
                                    }
                                }
                                //getRegister();
                                evaluate(&p->opr.op[1]);
                                fprintf(fp, "MOV [R%d], R%d\n", getPrevRegister(),currentRegister);
                                releaseRegister();
                                releaseRegister();
                                return 0;
                    case 'R' : 
                                if(getLocalVariableBinding(p->opr.op[0].id.name,currLocalTable) != 0){
                                    fprintf(fp, "MOV R%d, %d\n", currentRegister,(getLocalVariableBinding(p->opr.op[0].id.name,currLocalTable)));
                                    getRegister();
                                    fprintf(fp, "MOV R%d, BP\n",currentRegister);
                                    fprintf(fp, "ADD R%d, R%d\n",getPrevRegister(),currentRegister);
                                    fprintf(fp, "IN R%d\n",currentRegister);
                                    fprintf(fp, "MOV [R%d], R%d\n",getPrevRegister() ,currentRegister);
                                    releaseRegister();

                                }
                                else{
                                    currentRegister = -1;
                                    evaluate(p->opr.op[0].id.expressionNode);
                                    getRegister();
                                    fprintf(fp, "MOV R%d, %d\n", currentRegister,(getVariableBinding(p->opr.op[0].id.GsymbolPointer,0)));
                                    getRegister();
                                    fprintf(fp, "MOV R%d, 1000\n", currentRegister);
                                    fprintf(fp, "ADD R%d, R%d\n",getPrevRegister(), currentRegister);
                                    releaseRegister();
                                    fprintf(fp, "ADD R%d, R%d\n", getPrevRegister(), currentRegister);
                                    releaseRegister();
                                    getRegister();
                                    fprintf(fp, "IN R%d\n", currentRegister);
                                    fprintf(fp, "MOV [R%d], R%d\n",getPrevRegister(),currentRegister);
                                    releaseRegister();
                                }
                                //releaseRegister();
                                return 0;
                    case 'W' : 
                                evaluate(&p->opr.op[0]);
                                fprintf(fp, "OUT R%d\n",currentRegister);
                                releaseRegister();
                                return 0;
                    case 'I' :  
                                evaluate(&(p->opr.op[0]));
                                localCurrentLabel1 = ++currentLabel;
                                localCurrentLabel2 = ++currentLabel;
                                fprintf(fp,"JZ R%d, LABEL%d\n",currentRegister,localCurrentLabel1);
                                releaseRegister();
                                currentLabel++;
                                evaluate(&(p->opr.op[1]));
                                releaseRegister();
                                fprintf(fp,"JMP LABEL%d\n",localCurrentLabel2);
                                fprintf(fp,"LABEL%d:\n",localCurrentLabel1);
                                if(p->opr.nops > 2){
                                    evaluate(&(p->opr.op[2]));
                                    releaseRegister();
                                }
                                fprintf(fp,"LABEL%d:\n",localCurrentLabel2);
                                
                                return 0;
                    case 'S' : 
                                freePushLevel();
                                evaluate(&(p->opr.op[0]));
                                fprintf(fp,"MOV R0, R0//\tEnd of Statement\n");
                                freePushLevel();
                                evaluate(&(p->opr.op[1]));
                                freePushLevel();
                                return 0;
                    case 'L' : 
                                localCurrentLabel1 = ++currentLabel;
                                localCurrentLabel2 = ++currentLabel;
                                fprintf(fp,"LABEL%d:\n",localCurrentLabel1);
                                evaluate(&(p->opr.op[0]));
                                fprintf(fp,"JZ R%d, LABEL%d\n",currentRegister,localCurrentLabel2);
                                releaseRegister();
                                evaluate(&(p->opr.op[1]));
                                fprintf(fp,"JMP LABEL%d\n",localCurrentLabel1);
                                fprintf(fp,"LABEL%d:\n",localCurrentLabel2);
                                return 0;
                    case '&'    :
                                getRegister();
                                evaluate(&p->opr.op[0]);
                                getRegister();
                                evaluate(&p->opr.op[1]);
                                fprintf(fp,"MUL R%d, R%d\n",getPrevRegister(),currentRegister);
                                releaseRegister();
                                return 0;
                    case '|'    :
                                getRegister();
                                evaluate(&p->opr.op[0]);
                                getRegister();
                                evaluate(&p->opr.op[1]);
                                fprintf(fp,"ADD R%d, R%d\n",getPrevRegister(),currentRegister);
                                fprintf(fp,"MOV R%d, 0\n",currentRegister);
                                fprintf(fp,"GT R%d, R%d\n",getPrevRegister(),currentRegister);
                                releaseRegister();
                                return 0;
                    case '!'    :
                                getRegister();
                                evaluate(&p->opr.op[0]);
                                getRegister();
                                fprintf(fp,"MOV R%d, -1\n",currentRegister);
                                fprintf(fp,"ADD R%d, R%d\n",getPrevRegister(),currentRegister);
                                fprintf(fp,"MUL R%d, R%d\n",getPrevRegister(),currentRegister);
                                releaseRegister();
                                return 0;

                    case '^'    :
                                fprintf(fp,"MOV R0, R0//\tReturn Statement Begins Here\n");
                                currentRegister = -1;
                                evaluate(&p->opr.op[0]);
                                getRegister();
                                fprintf(fp,"MOV R%d, BP\n",currentRegister);
                                getRegister();
                                fprintf(fp,"MOV R%d, -2\n",currentRegister);
                                fprintf(fp,"ADD R%d, R%d\n",getPrevRegister(),currentRegister);
                                releaseRegister();
                                fprintf(fp,"MOV [R%d], R%d\n",currentRegister,getPrevRegister());
                                releaseRegister();
                                freePushLevel();
                                fprintf(fp,"MOV SP, BP\n");
                                fprintf(fp,"POP BP\n");
                                fprintf(fp,"RET\n");

                }
    }
    return 0;
}
/*
    0 -> Error
    1 -> Integer
    2 -> Character
    3 -> Boolean
*/
    struct Gsymbol * funcGsymbolPoi;
    struct Gsymbol * tempFuncGsymbolPointer;
    struct argList * arguments;
    struct fArgExpression * fArgExps;
    int hasError    = 0;
    int result      = 0;

    struct typeTable * type;
    struct innerVariable * head;   
                                                
int analyse(struct nodeTypeTag *p){
    if(p == NULL){
        return 0;
    }
    switch(p->nodeClass){
        case CONSTANT : 
                    return p->con.type;
        case FUNC :  
                    funcGsymbolPoi  = getSymbolTableTuple(p->func.funcName);
                    arguments       = funcGsymbolPoi->args;
                    fArgExps        = p->func.fArgExps;
                    while(arguments && fArgExps){
                        result = analyse(fArgExps->exprNode);
                        if((result==3)&&(strcmp(arguments->type->name,"boolean") == 0)){
                            result = result;
                        }
                        else if((result==1)&&(strcmp(arguments->type->name,"integer") == 0)){
                            result = result;
                        }
                        else if((result == 1)&&(arguments->type)){
                            result = result;
                        }
                        else{
                            printf("line %d : Invalid Argument Type\n",p->lineNumber);
                            hasError = 1;
                        }
                        if((arguments->isRef)&&(fArgExps->exprNode->nodeClass != ID)){
                            printf("line %d : Argument must be an ID for Call By Reference\n",p->lineNumber);
                            hasError = 1;
                        }
                        /*
                        if(fArgExps->exprNode->nodeClass == CONSTANT){
                            printf("It's a constant\n");
                            printf("TYPE IS %d\n",fArgExps->exprNode->con.type);
                        }
                        printf("TYPE IS %d i.e %s\n",result,arguments->type->name);
                        */
                        arguments   = arguments->next;
                        fArgExps    = fArgExps->next;
                    }
                    if((arguments || fArgExps)||hasError){
                        return 0;
                    }
                    else{
                        if(strcmp(funcGsymbolPoi->type->name,"boolean") == 0){
                            return 3;
                        }
                        else{
                            return 1;
                        }
                    }
                        

        case ID       : 
                        if(getLocalVariableBinding(p->id.name,currLocalTable) != 0){
                            //printf("Reached Here...\n");
                            p->id.LsymbolPointer = getLocalTableEntry(p->id.name,currLocalTable);
                            if(p->id.innerId){
                                type = p->id.LsymbolPointer->type;
                                head = p->id.innerId;
                                while(head){
                                    type = getFieldType(head->name,type);
                                    if(!type){
                                        printf("line %d : Invalid attribute %s \n",p->lineNumber,head->name);
                                        return 0;
                                    }
                                    head = head->next;
                                }
                                if(strcmp(type->name,"boolean")==0){
                                    return 3;
                                }
                                else{
                                    return 1;
                                }
                            }
                            p->id.LsymbolPointer = getLocalTableEntry(p->id.name,currLocalTable);
                            if(strcmp(p->id.LsymbolPointer->type->name, "integer") == 0)
                                return 1;
                            if(strcmp(p->id.LsymbolPointer->type->name, "boolean") == 0)
                                return 3;
                            if(p->id.LsymbolPointer->type){
                                return 1;
                            }
                            printf("line %d : Array index must be an Integer\n",p->lineNumber);
                            return 0;
                        }
                        else if(getVariableBinding(p->id.GsymbolPointer,0) != -1){
                            if(p->id.innerId){
                                type = p->id.GsymbolPointer->type;
                                head = p->id.innerId;
                                while(head){
                                    type = getFieldType(head->name,type);
                                    if(!type){
                                        printf("line %d : Invalid attribute %s \n",p->lineNumber,head->name);
                                        return 0;
                                    }
                                    head = head->next;
                                }
                                if(strcmp(type->name,"boolean")==0){
                                    return 3;
                                }
                                else{
                                    return 1;
                                }
                            }
                            if(analyse(p->id.expressionNode) == 1){
                                if(strcmp(p->id.GsymbolPointer->type->name, "integer") == 0)
                                    return 1;
                                if(strcmp(p->id.GsymbolPointer->type->name, "boolean") == 0)
                                    return 3;
                                if(p->id.GsymbolPointer->type){
                                    return 1;
                                }
                            }
                            printf("line %d : Array index must be an Integer\n",p->lineNumber);
                            return 0;
                        }
                        printf("line %d : Undefined Symbol %s\n",p->lineNumber,p->id.name);
                        return 0;
        case OPERATION:
                switch(p->opr.oper){
                    case '+' : 
                                if((analyse(&(p->opr.op[0])) == 1) && (analyse(&p->opr.op[1]) == 1)){
                                    return 1;
                                }
                                printf("line %d : Invalid Data Type for '+' Operator \n",p->lineNumber);
                                return 0;
                    case '-' : 
                                if((analyse(&(p->opr.op[0])) == 1) && (analyse(&p->opr.op[1]) == 1)){
                                    return 1;
                                }
                                printf("line %d : Invalid Data Type for '-' Operator \n",p->lineNumber);
                                return 0;
                    case '*' : 
                                if((analyse(&(p->opr.op[0])) == 1) && (analyse(&p->opr.op[1]) == 1)){
                                    return 1;
                                }
                                printf("line %d : Invalid Data Type for '*' Operator \n",p->lineNumber);
                                return 0;
                    case '/' : 
                                if((analyse(&(p->opr.op[0])) == 1) && (analyse(&p->opr.op[1]) == 1)){
                                    return 1;
                                }
                                printf("line %d : Invalid Data Type for '/' Operator \n",p->lineNumber);
                                return 0;
                    case '%' : 
                                if((analyse(&(p->opr.op[0])) == 1) && (analyse(&p->opr.op[1]) == 1)){
                                    return 1;
                                }
                                printf("line %d : Invalid Data Type for 'mod' Operator \n",p->lineNumber);
                                return 0;
                    case '~' : if((analyse(&p->opr.op[0])==1)&&(analyse(&p->opr.op[1]) == 1)){
                                    return 3;
                                }
                                else{
                                    printf("line %d : Different Data types for '==' Operator \n",p->lineNumber);
                                    return 0;
                                }
                    case '<' : if((analyse(&p->opr.op[0])==1)&&(analyse(&p->opr.op[1]) == 1)){
                                        return 3;
                                }
                                else{
                                    printf("line %d : Different Data types for '<' Operator \n",p->lineNumber);
                                    return 0;
                                }
                    case '>' : if((analyse(&p->opr.op[0])==1)&&(analyse(&p->opr.op[1]) == 1)){
                                    return 3;
                                }
                                else{
                                    printf("line %d : Different Data types for '>' Operator \n",p->lineNumber);
                                    return 0;
                                }
                    case '=' : 
                                if((analyse(&p->opr.op[0]) == analyse(&p->opr.op[1]))&&(analyse(&p->opr.op[0]) != 0))
                                    return 1;
                                else{
                                    printf("line %d : Different Data types for '=' Operator Types are %d and %d\n",p->lineNumber,analyse(&p->opr.op[0]),analyse(&p->opr.op[1]));
                                    return 0;
                                }
                    case 'R' : 
                                if(getLocalVariableBinding(p->opr.op[0].id.name,currLocalTable) != 0){
                                    p->opr.op[0].id.LsymbolPointer = getLocalTableEntry(p->opr.op[0].id.name,currLocalTable);
                                    if(strcmp(p->opr.op[0].id.LsymbolPointer->type->name, "integer") == 0)
                                        return 1;
                                    else
                                        printf("line %d : Invalid Read Operation \n",p->lineNumber);
                                }
                                else if(strcmp(p->opr.op[0].id.GsymbolPointer->type->name, "integer") == 0)
                                    return 1;
                                return 0;
                    case 'W' : 
                                if(analyse(&p->opr.op[0]) == 1)
                                    return 1;
                                return 0;
                    case 'I' :  
                                if(analyse(&(p->opr.op[0])) == 3){
                                    if(p->opr.nops > 2)
                                        return analyse(&(p->opr.op[1])) * analyse(&(p->opr.op[2]));
                                    return  analyse(&(p->opr.op[1]));
                                }
                                printf("line %d : Conditional Expression is not Boolean \n",p->lineNumber);
                                return 0;
                    case 'S' : return analyse(&(p->opr.op[0])) * analyse(&(p->opr.op[1]));
                    case 'L' : if(analyse(&(p->opr.op[0])) != 0){
                                    return analyse(&(p->opr.op[1]));
                                }
                                return 0;
                    case '&' :  if((analyse(&(p->opr.op[0])) == 3) && (analyse(&p->opr.op[1]) == 3)){
                                    return 3;
                                }
                                printf("line %d : AND operator is for boolean expressions\n",p->lineNumber);
                                return 0;
                    case '|' :  if((analyse(&(p->opr.op[0])) == 3) && (analyse(&p->opr.op[1]) == 3)){
                                    return 3;
                                }
                                printf("line %d : OR operator is for boolean expressions\n",p->lineNumber);
                                return 0;
                    case '!' :  if(analyse(&(p->opr.op[0])) == 3){
                                    return 3;
                                }
                                printf("line %d : OR operator is for boolean expressions\n",p->lineNumber);
                                return 0;
                    case '^' :
                                if((analyse(&(p->opr.op[0])) == 3) && (strcmp(currFunction->type->name,"boolean") == 0)){
                                    return 3;
                                }
                                else if((analyse(&(p->opr.op[0])) == 1) && (strcmp(currFunction->type->name,"integer") == 0)){
                                    return 1;
                                }
                                else if((analyse(&(p->opr.op[0])) == 1) && (currFunction->type)){
                                    return 1;
                                }
                                else{
                                    printf("line %d : Invalid Return Type\n",p->lineNumber);
                                    return 0;
                                }
                    case '@' :
                                if(analyse(&(p->opr.op[0])) == 1)
                                    return 1;
                                else{
                                    printf("line %d : invalid argument for readmem\n",p->lineNumber);
                                    return 0;
                                }
                    case '#' :
                                if((analyse(&(p->opr.op[0])) == 1)&&(analyse(&(p->opr.op[1])) == 1))
                                    return 1;
                                else{
                                    printf("line %d : invalid argument for writemem\n",p->lineNumber);
                                    return 0;
                                }
                }
    }
    return 0;
}
int hasReturnState(struct nodeTypeTag *p){
    if(p == NULL){
        return 0;
    }
    switch(p->opr.oper){
        case 'S' : 
                    return hasReturnState(&(p->opr.op[0])) + hasReturnState(&(p->opr.op[1]));
        case '^' :  return 1;
    /*
        case 'I' : 
                    if(&(p->opr.op[2])){
                        return hasReturnState(&(p->opr.op[1])) + hasReturnState(&(p->opr.op[2])); 
                    }
                    else{
                        return hasReturnState(&(p->opr.op[1]));
                    }
        case 'L' : return hasReturnState(&(p->opr.op[1]));
    */
    }
        return 0;
}

void freeNode(struct nodeTypeTag *p) {
    int i;
    if (!p) return;
    if (p->nodeClass == OPERATION) {
        for (i = 0; i < p->opr.nops; i++)
            freeNode(&p->opr.op[i]);
        free(p->opr.op);
    }
    free (p);
}


void pushForLocalVariables(struct Lsymbol *lsymbols){
    getRegister();
    fprintf(fp,"MOV R0, R0//\t Pushing for Local variables\n");
    fprintf(fp,"MOV R%d, 0\n",currentRegister);
    while(lsymbols){
        fprintf(fp,"PUSH R%d\n",currentRegister);
        lsymbols = lsymbols->next;
    }
    releaseRegister();
}