#include <stdio.h>
#include <stdlib.h>

typedef enum boolean{false, true} Boolean;
typedef int DataType;

typedef struct node{
	DataType data;
	struct node *next;
}Node;

typedef struct {
	Node *top;
	int size;
}Stack;

Stack* createStack();
void destroyStack(Stack* s);
Boolean pushElement(Stack* s, DataType data);
Boolean popElement(Stack* s, DataType* exit);
Boolean topElement(Stack* s, DataType* exit);
void print(Stack* s);
int getSize(Stack* s);
Stack* cloneStack(Stack* s);
void revertStack(Stack* s);
Boolean pushAllElements(Stack* s, DataType* vector, int size);
