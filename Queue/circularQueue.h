#include<stdio.h>
#include<stdlib.h>
#define MAX 8

typedef enum boolean{FALSE, TRUE} Boolean;
typedef int DataType;

/**************************************
* DATA
**************************************/

typedef struct {
	DataType* vetor;
	int length;
	int start;
	int end;
	int size;
}Queue;

/**************************************
* PROTOTYPES
**************************************/

Queue* createQueue();
void destroyQueue(Queue* f);
Boolean insertElement(Queue* f, DataType elemento);
Boolean removeElement(Queue* f, DataType* saida); 
Boolean firstElement(Queue* f, DataType* saida); 
Boolean isEmpty(Queue* f);
int getSize(Queue* f);
void print(Queue* f);
Queue* cloneQueue(Queue* f);
void revertQueue(Queue* f);
Boolean insertAllElements(Queue* f, DataType* vetor, int lengthVector);

/**************************************
* IMPLEMENTATIONS
**************************************/

Queue* createQueue(){

  Queue* queue = (Queue*) malloc(sizeof(Queue));
  queue->vetor = (DataType*) calloc(MAX, sizeof(DataType));
  
  if(queue != NULL){
  queue->length = MAX;
	queue->start = 0;
	queue->end = 0;
	queue->size = 0;
  }
  return queue;
}
void print(Queue* f){
  printf("[");
  for(int i = f->start; i < f->end; i++){
    if(i == f->start)
      printf("%d",f->vetor[i%f->length]);
    else
      printf(", %d",f->vetor[i%f->length]);
    }
    printf("]\n");
}
void destroyQueue(Queue* f){
  free(f->vetor);
  free(f);
}

Boolean insertElement(Queue* f, DataType elemento){
  if(f == NULL || f->size == MAX) return FALSE;
  
  else{
  f->vetor[f->end] = elemento;
  f->end = (f->end+1) % MAX;
  f->size++;
  return TRUE;
  }
}

Boolean removeElement(Queue* f, DataType* saida){
  if(f == NULL || isEmpty(f)) return FALSE;
  
  *saida = f->vetor[f->start%f->length]; 
  f->start = (f->start+1) % MAX;
  f->size--;
  return TRUE;
}

Boolean firstElement(Queue* f, DataType* saida){
  if(isEmpty(f)) return FALSE;
  else{
    *saida = f->vetor[f->start];
    return TRUE;
  }
}

Boolean isEmpty(Queue* f){
  if(f->size == 0) return TRUE;
  else return FALSE;
}

int getSize(Queue* f){
  return (f->end - f->start);
}

Queue* cloneQueue(Queue* f){
  Queue* fc = createQueue();
  for(int i = f->start; i < f->end; i++){
    insertElement(fc, f->vetor[i]);
  }
  fc->size = f->size;
  fc->length = f->length;
  return fc;
}

void revertQueue(Queue* f){
  DataType* revert = (DataType*) calloc(f->length, sizeof(DataType));
  for(int i = f->size - 1, j = 0; i >= 0; i--, j++){
    revert[j] = f->vetor[i];
  }
  free(f->vetor);
  f->vetor = revert;
}

Boolean insertAllElements(Queue* f, DataType* vetor, int lengthVector){
  for(int i = 0; i < lengthVector; i++){
    insertElement(f, vetor[i]);
  }
  return TRUE;
}