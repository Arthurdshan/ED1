#include "LinkedQueue.h"

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

Boolean insertElement(Queue* q, DataType data){
  if(q == NULL) return false;
  Node* node = (Node*) malloc (sizeof(Node));
  if(node == NULL) return false;
  node->data = data;
  node->prox = NULL;

  if(isEmpty(q)) q->start = node;
  else q->end->prox = node;
  q->end = node;
  q->size++;
  return true;
}

Boolean removeElement(Queue* q, DataType* saida){
  if(isEmpty(q)) return false;
  Node* node = q->start;
  *saida = node->data;
  q->start = q->start->prox;
  if(q->start == NULL) q->end = NULL;
  free(node);
  q->size--;
  return true;
}

Boolean firstElement(Queue* q, DataType* saida){
  if(isEmpty(q)) return false;
  *saida = q->start->data;
  return true;
}

int getSize(Queue* q){
  if(q == NULL) return 0;
return q->size;
}

Boolean isEmpty(Queue* q){
  if(q == NULL) return true;
  if(q->start == NULL) return true;
  return false;
}

void print(Queue *q){
  Node* aux = q->start;
  for(int i = 0; i < q->size; i++){
    printf("%d -> ",aux->data);
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
  if (q == NULL) return false;

  for(int i = 0; i < size; i++){
    int aux = vetor[i];
    insertElement(q, aux);
  }
  return true;
}
