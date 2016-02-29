#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//For Type Table
  struct typeTable{
      char *name;                 //type name
      int size;
      struct Fieldlist *fields;   //pointer to the head of fields list
      struct typeTable *next;     // pointer to the next type table entry
  };
//For Field List in Type Table
  struct Fieldlist{
    char *name;              //name of the field
    struct typeTable *type;  //pointer to type table entry of the field's type
    struct Fieldlist *next;  //pointer to the next field
  };

//Type Table Global Variables//

    struct typeTable * typeTableHead;
    struct typeTable * typeTableTail;

//Type Table Functions//

    void createTypeTableHead(char * type,int size);
    void addNewTypeTableEntry(char * type,int size);
    void makeBasicTypeTable();
    struct typeTable * newTypeTuple();
    int getDataTypeSize(char *dataType);
    //struct typeTable * getTypeTuple(char * name);
    struct typeTable * getTypeTuple(char * dataType);

