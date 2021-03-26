#ifndef PRIORITY_H
#define PRIORITY_H

#include <stdio.h>
#include <stdlib.h>
#define T 10
typedef enum boolean{FALSE, TRUE} Boolean;
typedef int DataType;

typedef struct {
	DataType* array;
	int length; 
	int size;
}priorityQueue;

priorityQueue* createQueue();
void destroyQueue(priorityQueue* q);
Boolean insertInQueue(priorityQueue* q, DataType value);
Boolean removeFromQueue(priorityQueue* q, DataType* saida); 
Boolean isEmpty(priorityQueue* q);
int getSize(priorityQueue* q);
void print(priorityQueue* q);
priorityQueue* cloneQueue(priorityQueue* q);
Boolean insertAllElements(priorityQueue* q, DataType* array, int size);
void promoveElement(priorityQueue* q, int leaf);
void downElement(priorityQueue* q, int root);
void switchElements(DataType* a, DataType* b);
int root(int j);
int rightLeaf(int i);
int leftLeaf(int i);

#endif