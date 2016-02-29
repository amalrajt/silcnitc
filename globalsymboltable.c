#include "globalsymboltable.h"
//Functions For Global Symbol Table

    int currentBinding 		 = 0;
/*
	Add A new Variable to symbol Table 
*/
struct Gsymbol * installVariable(char * name,struct typeTable * typeTableTuple, int arraySize){
	struct Gsymbol *variable;
	variable = malloc(sizeof(struct Gsymbol));
	if(variable == NULL){
		outOfMemory();
	}
	variable->name = malloc(strlen(name) + 1);
	strcpy(variable->name,name);
	variable->size 			= arraySize;
	variable->next 			= NULL;
	variable->type 			= typeTableTuple;
	variable->binding 		= currentBinding;
	currentBinding     		+= arraySize;
	if(!GsymbolHead){
		GsymbolHead 		= variable;
		GsymbolTail 		= variable;
	}
	else{
		GsymbolTail->next 	= variable;
		GsymbolTail 		= variable;
	}
	return variable;
}

/*
	Add A new symbol if its type table entry is unknowns
	Currently not used
*/
struct Gsymbol * installVariableRaw(char * name,char * type, int arraySize){
	struct typeTable * typeTableTuple = getTypeTuple(type);
	installVariable(name,typeTableTuple,arraySize);
}

/*
	Install multiple symbols at a time 
	eg 
	int a,b,c;
	varListContains list of variable names a,b,c
	typeTableTupe contains the type table entry for 'int'
*/
void installAllVariables(struct Gsymbol * idList,struct typeTable * typeTableTuple){
			struct Gsymbol * head;
			head = idList;
			while(head){
				//printf("HELLO\n");
				head->type  		= typeTableTuple;
				head 				= head->next;
			}
		}

/*
	To print all declared symbols (For Debugging)
*/
void printAllVariables(){
	struct Gsymbol * head;
	head = GsymbolHead;
	while(head){
		printf("\nName : %s \nSize : %d \nType : %s\nBinding : %d\n",head->name,head->size,head->type->name,head->binding);
		if(head->binding == -11){
			struct Lsymbol *start;
			start = head->lsymbols;
			printf("\n\tLocal Symbols\n");
			while(start){
				printf("\n\tName : %s \n\tSize : %d \n\tType : %s\n\tBinding : %d\n",start->name,start->size,start->type->name,start->binding);
				start = start->next;
			}
			printf("\n\tArguments\n");
			struct argList *begin;
			begin = head->args;
			while(begin){
				printf("\n\tName : %s \n\tType : %s\n",begin->name,begin->type->name);
				begin = begin->next;
			}
		}
		head = head->next;
	}
}

/*
	Search Variable Binding From Symbol Table if only variable name is known
	Shift = Index (for Array) or 0 (for other variables)
*/
int findVariableBinding(char * variableName, int shift){
	struct Gsymbol * variable =  getVariable(variableName);
	if(variable && (shift < variable->size)){
		return variable->binding + (shift*variable->type->size);
	}
	else{
		yyerror("Index Out of Range");
		return -1;
	}
}
		
/*
	Get Variable Binding If Symbol Table Entry is already Known
	Shift = Index (for Array) or 0 (for other variables)
*/
int getVariableBinding(struct Gsymbol * variable, int shift){
	if(variable && (shift < variable->size)){
		return variable->binding + (shift*variable->type->size);
	}
	else{
		return -1;
	}
}

int getLocalVariableBinding(char * name,struct Lsymbol * variable){
	while(variable){
		if(strcmp(variable->name,name) == 0){
			return variable->binding;
		}
		variable = variable->next;
	}
	return 0;
}

struct Lsymbol * getLocalTableEntry(char * name,struct Lsymbol * variable){
	while(variable){
		if(strcmp(variable->name,name) == 0){
			return variable;
		}
		variable = variable->next;
	}
	return NULL;
}
/*
	Get Variable's entry From Symbol Table
*/
struct Gsymbol * getVariable(char * variableName){
	struct Gsymbol * variable;
	variable = GsymbolHead;
	while(variable){
		if(strcmp(variable->name,variableName) == 0){
			return variable;
		}
		variable = variable->next;
	}
	return NULL;
}


/*
	Create a new variable pointer for the given type
*/
struct variablePointer * newVariablePointer(char * type){
	struct variablePointer *varPointer;
	varPointer = malloc(sizeof(struct variablePointer));
	varPointer->type = malloc(strlen(type)+1);
	strcpy(varPointer->type,type);
	if(strcmp(type,"int") == 0){
		varPointer->intPointer = NULL;
	}
	else if(strcmp(type,"char") == 0){
		varPointer->charPointer = NULL;
	}
	else if(strcmp(type,"bool") == 0){
		varPointer->booleanPointer = NULL;
	}
	return varPointer;
}

/*
	To store value the variable
	Inputs : pointer to variable binding , pointer to the value to be copied to the variable{ both of type variablePointer }
*/
void writeToVariable(struct variablePointer *varPointer,struct variablePointer *writeBufferPointer){
	if(strcmp(varPointer->type,"int") == 0){
		*varPointer->intPointer 	= *writeBufferPointer->intPointer;
	}
	else if(strcmp(varPointer->type,"char") == 0){
		*varPointer->charPointer 	= *writeBufferPointer->charPointer;
	}
	else if(strcmp(varPointer->type,"boolean") == 0){
		*varPointer->booleanPointer = *writeBufferPointer->booleanPointer;
	}
}




struct argList * saveFarg(char * name,struct typeTable * typeTableTuple){
	struct argList *arg;
	arg = malloc(sizeof(struct argList));
	if(arg == NULL){
		outOfMemory();
	}
	arg->name = malloc(strlen(name) + 1);
	strcpy(arg->name,name);
	arg->next = NULL;
	arg->type = typeTableTuple;
	arg->isRef= 0;
	return arg;
}


struct Gsymbol * installFunction(char * name,struct argList * args,struct typeTable * typeTableTuple, struct Lsymbol * lsymbols){
	struct Gsymbol *function;
	function = malloc(sizeof(struct Gsymbol));
	if(function == NULL){
		outOfMemory();
	}
	function->name = malloc(strlen(name) + 1);
	strcpy(function->name,name);
	function->size 				= 0;
	function->next 				= NULL;
	function->binding 			= -11;
	function->lsymbols	    	= lsymbols;
	function->args 				= args;
    function->type 		    	= typeTableTuple;     
	if(!GsymbolHead){
		GsymbolHead 		  	= function;
		GsymbolTail 		  	= function;
	}
	else{
		GsymbolTail->next 	  	= function;
		GsymbolTail           	= function;
	}
	return function;
}


struct Lsymbol * installLocalVariable(char * name,struct typeTable * typeTableTuple, int arraySize){
	struct Lsymbol *variable;
	variable = malloc(sizeof(struct Lsymbol));
	if(variable == NULL){
		outOfMemory();
	}
	variable->name = malloc(strlen(name) + 1);
	strcpy(variable->name,name);
	variable->size 				= arraySize;
	variable->next 				= NULL;
	variable->type 				= typeTableTuple;
	return variable;
}

struct Lsymbol * installAllLocalVariables(struct Lsymbol * idList,struct typeTable * typeTableTuple){
	struct Lsymbol * head;
	head = idList;
	while(head){
		head->type 				= typeTableTuple;
		head 					= head->next;
	}
	return idList;
}


struct Gsymbol * getSymbolTableTuple(char * name){
	struct Gsymbol *head;
	head = GsymbolHead;
	while(head){
		if(strcmp(head->name,name) == 0){
			return head;
		}
		head 					= head->next;
	}
	return NULL;
}


void writeBindingsAndArgs(struct Lsymbol * localVar,struct argList *argument){
	struct Lsymbol * head;
	head = localVar;
	int curBinding = 1;
	while(head->next){
		head->binding 			= curBinding++;
		head = head->next;
	}
	head->binding 				= curBinding;
	curBinding 					= -2;
	struct argList * argHead;
	struct Lsymbol * argLocalSymbol;
	argHead = argument;
	while(argHead){
		argLocalSymbol 			= installLocalVariable(argHead->name,argHead->type,1);
		argLocalSymbol->binding = --curBinding;
		head->next     			= argLocalSymbol;
		head 		   			= head->next;
		argHead = argHead->next;
	}
}

int isCorrectDeclaration(struct argList * argument,struct argList * actualArgument){
	struct argList *head;
	struct argList *actualHead;
	head 			= argument;
	actualHead 		= actualArgument;
	while(head && actualHead){
		if((strcmp(head->name,actualHead->name)!=0)||(head->type != actualHead->type)){
			break;
		}
		head 		= head->next;
		actualHead 	= actualHead->next;
	}
	if(head || actualHead)
		return 0;
	return 1;
}
