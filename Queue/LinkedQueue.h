//FilaEncadeada.h
#include<stdio.h>
#include<stdlib.h>

typedef enum boolean{FALSE, TRUE} Boolean;
typedef int DataType;

/**************************************
* DATA
**************************************/
typedef struct node{
	DataType value;
	struct node* prox;
}Node;

typedef struct {
	Node* start;
	Node* end;
	int size;
}Queue;

/**************************************
* PROTOTYPES
**************************************/

Queue* createQueue();
void destroyQueue(Queue* f);
Boolean insertElement(Queue* f, DataType value);
Boolean removeElement(Queue* f, DataType* saida);
Boolean firstElement(Queue* f, DataType* saida); 
int getSize(Queue* f);
void print(Queue* f);
void revertQueue(Queue* f);
Boolean insertAllElements(Queue* f, DataType* vetor, int lengthVector);
Boolean isEmpty(Queue* f);
/**************************************
* IMPLEMENTATION
**************************************/
// Desenvolva as funções

Queue* createQueue(){
  Queue *f = (Queue*) malloc(sizeof(Queue));
  if(f != NULL) {
    f->start = NULL;
    f->end = NULL;
    f->size = 0;
  }
  return f;
}

void destroyQueue(Queue* f){
  if(f != NULL){
    Node* aux;
    while(f->start != NULL){
      aux = f->start;
      f->start = f->start->prox;
      free(aux);
    }
    free(f);
  }
}

Boolean insertElement(Queue* f, DataType value){
  if(f == NULL) return FALSE;
  Node* node = (Node*) malloc (sizeof(Node*));
  if(node == NULL) return FALSE;
  node->value = value;
  node->prox = NULL;

  if(isEmpty(f)) f->start = node;
  else f->end->prox = node;
  f->end = node;
  f->size++;
  return TRUE;
}

Boolean removeElement(Queue* f, DataType* saida){
  if(isEmpty(f)) return FALSE;
  Node* node = f->start;
  *saida = node->value;
  f->start = f->start->prox;
  if(f->start == NULL) f->end = NULL;
  free(node);
  f->size--;
  return TRUE;
}

Boolean firstElement(Queue* f, DataType* saida){
  if(isEmpty(f)) return FALSE;
  *saida = f->start->value;
  return TRUE;
}

int getSize(Queue* f){
  if(f == NULL) return 0;
return f->size;
}

Boolean isEmpty(Queue* f){
  if(f == NULL) return TRUE;
  if(f->start == NULL) return TRUE;
  return FALSE;
}

void print(Queue *f){
  Node* aux = f->start;
  for(int i = 0; i < f->size; i++){
    printf("%d -> ",aux->value);
    aux = aux->prox;
  }
  printf("NULL\n");
}


void revertQueue(Queue* f){
  Node* aux = NULL; 
  Node* aux1 = f->start; 
  Node* aux2 = NULL; 
  while (aux1 != NULL) { 
    aux2 = aux1->prox; 
    aux1->prox = aux; 
    aux = aux1; 
    aux1 = aux2; 
  } 
  f->start = aux; 
}

Boolean insertAllElements(Queue* f, DataType* vetor, int size){
  if (f == NULL) return FALSE;

  for(int i = 0; i < size; i++){
    int aux = vetor[i];
    insertElement(f, aux);
  }
  return TRUE;
}
