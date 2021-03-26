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
void destroyQueue(Queue* q);
Boolean insertElement(Queue* q, DataType elemento);
Boolean removeElement(Queue* q, DataType* saida); 
Boolean firstElement(Queue* q, DataType* saida); 
Boolean isEmpty(Queue* q);
int getSize(Queue* q);
void print(Queue* q);
Queue* cloneQueue(Queue* q);
void revertQueue(Queue* q);
Boolean insertAllElements(Queue* q, DataType* vetor, int lengthVector);

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
void print(Queue* q){
  printf("[");
  for(int i = q->start; i < q->end; i++){
    if(i == q->start)
      printf("%d",q->vetor[i%q->length]);
    else
      printf(", %d",q->vetor[i%q->length]);
    }
    printf("]\n");
}
void destroyQueue(Queue* q){
  free(q->vetor);
  free(q);
}

Boolean insertElement(Queue* q, DataType elemento){
  if(q == NULL || q->size == MAX) return FALSE;
  
  else{
  q->vetor[q->end] = elemento;
  q->end = (q->end+1) % MAX;
  q->size++;
  return TRUE;
  }
}

Boolean removeElement(Queue* q, DataType* saida){
  if(q == NULL || isEmpty(q)) return FALSE;
  
  *saida = q->vetor[q->start%q->length]; 
  q->start = (q->start+1) % MAX;
  q->size--;
  return TRUE;
}

Boolean firstElement(Queue* q, DataType* saida){
  if(isEmpty(q)) return FALSE;
  else{
    *saida = q->vetor[q->start];
    return TRUE;
  }
}

Boolean isEmpty(Queue* q){
  if(q->size == 0) return TRUE;
  else return FALSE;
}

int getSize(Queue* q){
  return (q->end - q->start);
}

Queue* cloneQueue(Queue* q){
  Queue* fc = createQueue();
  for(int i = q->start; i < q->end; i++){
    insertElement(fc, q->vetor[i]);
  }
  fc->size = q->size;
  fc->length = q->length;
  return fc;
}

void revertQueue(Queue* q){
  DataType* revert = (DataType*) calloc(q->length, sizeof(DataType));
  for(int i = q->size - 1, j = 0; i >= 0; i--, j++){
    revert[j] = q->vetor[i];
  }
  free(q->vetor);
  q->vetor = revert;
}

Boolean insertAllElements(Queue* q, DataType* vetor, int lengthVector){
  for(int i = 0; i < lengthVector; i++){
    insertElement(q, vetor[i]);
  }
  return TRUE;
}