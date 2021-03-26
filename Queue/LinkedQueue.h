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
void destroyQueue(Queue* q);
Boolean insertElement(Queue* q, DataType value);
Boolean removeElement(Queue* q, DataType* saida);
Boolean firstElement(Queue* q, DataType* saida); 
int getSize(Queue* q);
void print(Queue* q);
void revertQueue(Queue* q);
Boolean insertAllElements(Queue* q, DataType* vetor, int lengthVector);
Boolean isEmpty(Queue* q);
/**************************************
* IMPLEMENTATION
**************************************/
// Desenvolva as funções

Queue* createQueue(){
  Queue *q = (Queue*) malloc(sizeof(Queue));
  if(q != NULL) {
    q->start = NULL;
    q->end = NULL;
    q->size = 0;
  }
  return q;
}

void destroyQueue(Queue* q){
  if(q != NULL){
    Node* aux;
    while(q->start != NULL){
      aux = q->start;
      q->start = q->start->prox;
      free(aux);
    }
    free(q);
  }
}

Boolean insertElement(Queue* q, DataType value){
  if(q == NULL) return FALSE;
  Node* node = (Node*) malloc (sizeof(Node));
  if(node == NULL) return FALSE;
  node->value = value;
  node->prox = NULL;

  if(isEmpty(q)) q->start = node;
  else q->end->prox = node;
  q->end = node;
  q->size++;
  return TRUE;
}

Boolean removeElement(Queue* q, DataType* saida){
  if(isEmpty(q)) return FALSE;
  Node* node = q->start;
  *saida = node->value;
  q->start = q->start->prox;
  if(q->start == NULL) q->end = NULL;
  free(node);
  q->size--;
  return TRUE;
}

Boolean firstElement(Queue* q, DataType* saida){
  if(isEmpty(q)) return FALSE;
  *saida = q->start->value;
  return TRUE;
}

int getSize(Queue* q){
  if(q == NULL) return 0;
return q->size;
}

Boolean isEmpty(Queue* q){
  if(q == NULL) return TRUE;
  if(q->start == NULL) return TRUE;
  return FALSE;
}

void print(Queue *q){
  Node* aux = q->start;
  for(int i = 0; i < q->size; i++){
    printf("%d -> ",aux->value);
    aux = aux->prox;
  }
  printf("NULL\n");
}


void revertQueue(Queue* q){
  Node* aux = NULL; 
  Node* aux1 = q->start; 
  Node* aux2 = NULL; 
  while (aux1 != NULL) { 
    aux2 = aux1->prox; 
    aux1->prox = aux; 
    aux = aux1; 
    aux1 = aux2; 
  } 
  q->start = aux; 
}

Boolean insertAllElements(Queue* q, DataType* vetor, int size){
  if (q == NULL) return FALSE;

  for(int i = 0; i < size; i++){
    int aux = vetor[i];
    insertElement(q, aux);
  }
  return TRUE;
}
