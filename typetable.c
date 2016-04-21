#include "typetable.h"
// FUNCTIONS FOR DATA TYPE TABLE

	// Search Type table entry by Name
	struct typeTable * getTypeTuple(char * dataType){
		struct typeTable *typeTuple;
		typeTuple = typeTableHead;
		while(typeTuple){
			if(strcmp(dataType,typeTuple->name) == 0){
				return typeTuple;
			}
			typeTuple = typeTuple->next;
		}
		return NULL;
	}
		// To create a new type table entry
	struct typeTable * newTypeTuple(){
		//printf("Reached Here");
		struct typeTable *t;
		t = malloc(sizeof(struct typeTable));
		if(t == NULL){
			outOfMemory();
		}
		return t;
	}
		//Function to initialize typeTableHead and typeTableTail
	void createTypeTableHead(char * type,int size){
		//printf("Reached Here\n");
		//Initializing Head
		typeTableHead = newTypeTuple();
		typeTableHead->name = malloc(strlen(type) + 1);
		strcpy(typeTableHead->name,type);
		typeTableHead->size = size;
		typeTableHead->fields = NULL;
		typeTableHead->next = NULL;
		typeTableTail = typeTableHead;
	}
		//Fuction to add new entry to type Table
	void addNewTypeTableEntry(char * type, int size){
		//printf("Reached Here\n");
		typeTableTail->next = newTypeTuple();
		//Newly Allocated one is the new tail
		typeTableTail = typeTableTail->next;
		typeTableTail->name = malloc(strlen(type) + 1);
		strcpy(typeTableTail->name,type);
		typeTableTail->size = size;
		typeTableTail->fields = NULL;
		typeTableTail->next = NULL;
	}
	
	//Fuction For Creating Basic Data Types {int,str,bool}
	void makeBasicTypeTable(){
		//printf("Reached Here");
		createTypeTableHead("integer",1);
		addNewTypeTableEntry("char",1);
		addNewTypeTableEntry("boolean",1);
	}
		//Function To Get Size of data type from Type Table
	int getDataTypeSize(char *dataType){
		struct typeTable *typeTuple;
			typeTuple = typeTableHead;
		while(typeTuple){
			if(strcmp(dataType,typeTuple->name) == 0){
				return typeTuple->size;
			}
			typeTuple = typeTuple->next;
		}
		return 0;
	}
	struct typeTable * installType(char * name,struct Fieldlist * fields){
		typeTableTail->next = newTypeTuple();
		typeTableTail = typeTableTail->next;
		typeTableTail->fields = fields;
		typeTableTail->name = name;
	}

	struct Fieldlist * installFieldList(char * name,struct typeTable * typeTuple){
		struct Fieldlist * field;
		field = malloc(sizeof(struct Fieldlist));
		field->name = name;
		field->type = typeTuple;
		field->next = NULL;
		return field;
	}
	int getAttributeBinding(char * name,struct typeTable * type){
		struct Fieldlist * fields;
		fields = type->fields;
		int ret = 0;
		while(fields){
			if(strcmp(fields->name,name) == 0){
				return ret;
			}
			ret += 1;
			fields = fields->next;
		}
		return -1;
	}
	//To Print Type Table Entries (For Debugging)
	void printTypeTable(){
		struct typeTable *t;
		t = typeTableHead;
		while(t){
			printf("%s\n",t->name);
			struct Fieldlist * field;
			field = t->fields;
			while(field){
				printf("\t%s\n",field->name);
				printf("\t\t type - %s , size - %d\n",field->type->name,field->type->size);
				field = field->next;
			}
			t=t->next;
		}
	}
