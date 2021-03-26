#include<stdio.h>
#include<stdlib.h>

typedef enum boolean{false, true} Boolean;
typedef int DataType;

typedef struct node{
	DataType data;
	struct node* prox;
}Node;

typedef struct {
	Node* start;
	Node* end;
	int size;
}Queue;

Queue* createQueue();
void destroyQueue(Queue* q);
Boolean insertElement(Queue* q, DataType data);
Boolean removeElement(Queue* q, DataType* saida);
Boolean firstElement(Queue* q, DataType* saida); 
int getSize(Queue* q);
void print(Queue* q);
void revertQueue(Queue* q);
Boolean insertAllElements(Queue* q, DataType* vetor, int lengthVector);
Boolean isEmpty(Queue* q);

