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
void destroyQueue(priorityQueue* f);
Boolean insertInQueue(priorityQueue* f, DataType elemento);
Boolean removeFromQueue(priorityQueue* f, DataType* saida); // estratégia do scanf
Boolean isEmpty(priorityQueue* f);
int getSize(priorityQueue* f);
void print(priorityQueue* f);
priorityQueue* cloneQueue(priorityQueue* f);
Boolean insertAllElements(priorityQueue* f, DataType* array, int size);
void promoveElement(priorityQueue* f, int filho);
void downElement(priorityQueue* f, int pai);
void switchElements(DataType* a, DataType* b);
int root(int j);
int rightLeaf(int i);
int leftLeaf(int i);
/**************************************
* IMPLEMENTATION
**************************************/

priorityQueue* createQueue(){
  priorityQueue* f = (priorityQueue*) malloc(sizeof(priorityQueue));
  f->array = (DataType*) calloc(T, sizeof(DataType));
  f->size = 0;
  f->length = T;
  return f;
}

Boolean insertInQueue(priorityQueue* f, DataType elemento){
  if(f == NULL) return FALSE;
  if(f->size == f->length) return FALSE;

  f->array[f->size] = elemento;
  promoveElement(f,f->size);
  f->size++;
  return TRUE;
}

void promoveElement(priorityQueue* f, int pos){
  if(f->array[pos] <= f->array[root(pos)]) return;
  switchElements(&f->array[pos],&f->array[root(pos)]);
  promoveElement(f, root(pos));
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

void destroyQueue(priorityQueue* f){
  if(isEmpty(f)) return;
  free(f->array);
  free(f);
}

Boolean isEmpty(priorityQueue* f){
  if(f == NULL) return TRUE;
  return FALSE;
}

void print(priorityQueue* f){
  if(isEmpty(f)) return;

  printf("[%d",f->array[0]);
  for(int i = 1; i < f->size; i++){
    printf(", %d", f->array[i]);
  }
  printf("]\n");
}

Boolean removeFromQueue(priorityQueue* f, DataType* saida){
  if(isEmpty(f)) return FALSE;
  
  *saida = f->array[f->size - 1];
  switchElements(&f->array[0], &f->array[f->size - 1]);
  f->size--;
  downElement(f, 0);
  return TRUE;
}

void downElement(priorityQueue* f, int pos){
  if(leftLeaf(pos) < f->size){
    int biggerElement = leftLeaf(pos);
    int filhoaDireita = (rightLeaf(pos) < f->size ? 1 : 0);
    if(filhoaDireita && f->array[rightLeaf(pos)] > f->array[leftLeaf(pos)])
      biggerElement = rightLeaf(pos);
    
    if(f->array[pos] < f->array[biggerElement]){
      switchElements(&f->array[pos],&f->array[biggerElement]);
      downElement(f, biggerElement);
    }
  }
}

int getSize(priorityQueue* f){
  return (f->size);
}

priorityQueue* cloneQueue(priorityQueue* f){
  priorityQueue *fc = createQueue();
  for(int i = 0; i < f->size; i++){
    fc->array[i] = f->array[i];
  }
  fc->size = f->size;
  fc->length = f->length;
  return fc;
}

Boolean insertAllElements(priorityQueue* f, DataType* array, int size){
  if(f == NULL) return FALSE;

  for(int i = 0; i < size; i++){
    int aux = array[i];
    insertInQueue(f, aux);
  }
  return TRUE;
}