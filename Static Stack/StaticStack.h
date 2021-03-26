#pragma once 

#include <stdio.h>
#include <stdlib.h>
#define N 5

typedef enum boolean{false, true} Boolean;
typedef int DataType;

typedef struct {
	DataType* vector;
	int length;
	int size;
}Stack;

Stack* createStack();
void destroyStack(Stack* s);
Boolean pushElement(Stack* s, DataType data);
Boolean popElement(Stack* s, DataType* saida);
Boolean topElement(Stack* s, DataType* saida);
void print(Stack* s);
int getSize(Stack* s);
Stack* cloneStack(Stack* s);
void revertStack(Stack* s);
Boolean pushAllElements(Stack* s, DataType* vector, int lengthvector);
