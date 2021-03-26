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

/**************************************
* PROTOTYPES
**************************************/

priorityQueue* createQueue();
void destroyQueue(priorityQueue* q);
Boolean insertInQueue(priorityQueue* q, DataType elemento);
Boolean removeFromQueue(priorityQueue* q, DataType* saida); 
Boolean isEmpty(priorityQueue* q);
int getSize(priorityQueue* q);
void print(priorityQueue* q);
priorityQueue* cloneQueue(priorityQueue* q);
Boolean insertAllElements(priorityQueue* q, DataType* array, int size);
void promoveElement(priorityQueue* q, int filho);
void downElement(priorityQueue* q, int pai);
void switchElements(DataType* a, DataType* b);
int root(int j);
int rightLeaf(int i);
int leftLeaf(int i);
/**************************************
* IMPLEMENTATION
**************************************/

priorityQueue* createQueue(){
  priorityQueue* q = (priorityQueue*) malloc(sizeof(priorityQueue));
  q->array = (DataType*) calloc(T, sizeof(DataType));
  q->size = 0;
  q->length = T;
  return q;
}

Boolean insertInQueue(priorityQueue* q, DataType elemento){
  if(q == NULL) return FALSE;
  if(q->size == q->length) return FALSE;

  q->array[q->size] = elemento;
  promoveElement(q,q->size);
  q->size++;
  return TRUE;
}

void promoveElement(priorityQueue* q, int pos){
  if(q->array[pos] <= q->array[root(pos)]) return;
  switchElements(&q->array[pos],&q->array[root(pos)]);
  promoveElement(q, root(pos));
}

void switchElements(DataType* a, DataType* b){
  int aux = *a;
  *a = *b;
  *b = aux;
}

int root(int j){
  return ((j-1)/2);
}

int leftLeaf(int i){
  return i*2+1;
}

int rightLeaf(int i){
  return i*2+2;
}

void destroyQueue(priorityQueue* q){
  if(isEmpty(q)) return;
  free(q->array);
  free(q);
}

Boolean isEmpty(priorityQueue* q){
  if(q == NULL) return TRUE;
  return FALSE;
}

void print(priorityQueue* q){
  if(isEmpty(q)) return;

  printf("[%d",q->array[0]);
  for(int i = 1; i < q->size; i++){
    printf(", %d", q->array[i]);
  }
  printf("]\n");
}

Boolean removeFromQueue(priorityQueue* q, DataType* saida){
  if(isEmpty(q)) return FALSE;
  
  *saida = q->array[q->size - 1];
  switchElements(&q->array[0], &q->array[q->size - 1]);
  q->size--;
  downElement(q, 0);
  return TRUE;
}

void downElement(priorityQueue* q, int pos){
  if(leftLeaf(pos) < q->size){
    int biggerElement = leftLeaf(pos);
    int filhoaDireita = (rightLeaf(pos) < q->size ? 1 : 0);
    if(filhoaDireita && q->array[rightLeaf(pos)] > q->array[leftLeaf(pos)])
      biggerElement = rightLeaf(pos);
    
    if(q->array[pos] < q->array[biggerElement]){
      switchElements(&q->array[pos],&q->array[biggerElement]);
      downElement(q, biggerElement);
    }
  }
}

int getSize(priorityQueue* q){
  return (q->size);
}

priorityQueue* cloneQueue(priorityQueue* q){
  priorityQueue *fc = createQueue();
  for(int i = 0; i < q->size; i++){
    fc->array[i] = q->array[i];
  }
  fc->size = q->size;
  fc->length = q->length;
  return fc;
}

Boolean insertAllElements(priorityQueue* q, DataType* array, int size){
  if(q == NULL) return FALSE;

  for(int i = 0; i < size; i++){
    int aux = array[i];
    insertInQueue(q, aux);
  }
  return TRUE;
}