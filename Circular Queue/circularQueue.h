#include<stdio.h>
#include<stdlib.h>
#define MAX 8

typedef enum boolean{false, true} Boolean;
typedef int DataType;


typedef struct {
	DataType* vetor;
	int length;
	int start;
	int end;
	int size;
}Queue;

Queue* createQueue();
void destroyQueue(Queue* q);
Boolean insertElement(Queue* q, DataType data);
Boolean removeElement(Queue* q, DataType* saida); 
Boolean firstElement(Queue* q, DataType* saida); 
Boolean isEmpty(Queue* q);
int getSize(Queue* q);
void print(Queue* q);
Queue* cloneQueue(Queue* q);
void revertQueue(Queue* q);
Boolean insertAllElements(Queue* q, DataType* vetor, int lengthVector);
