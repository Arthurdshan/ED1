#include<stdio.h>
#include<stdlib.h>
#include "linked_queue.h"

Queue* create_queue(){
  Queue *q = (Queue*) malloc(sizeof(Queue));
  if(q != NULL) {
    q->start = NULL;
    q->end = NULL;
    q->size = 0;
  }
  return q;
}

void destroy_queue(Queue *q){
  if(q != NULL){
    Node *aux;
    while(q->start != NULL){
      aux = q->start;
      q->start = q->start->prox;
      free(aux);
    }
    free(q);
  }
}

Boolean insert_element(Queue *q, DataType data){
  if(q == NULL) return false;
  Node *node = (Node*) malloc (sizeof(Node));
  if(node == NULL) return false;
  node->data = data;
  node->prox = NULL;

  if(is_empty(q)) q->start = node;
  else q->end->prox = node;
  q->end = node;
  q->size++;
  return true;
}

Boolean remove_element(Queue *q, DataType *mem_adress){
  if(is_empty(q)) return false;
  Node *node = q->start;
  *mem_adress = node->data;
  q->start = q->start->prox;
  if(q->start == NULL) q->end = NULL;
  free(node);
  q->size--;
  return true;
}

Boolean first_element(Queue *q, DataType *mem_adress){
  if(is_empty(q)) return false;
  *mem_adress = q->start->data;
  return true;
}

int get_size(Queue *q){
  if(q == NULL) return 0;
return q->size;
}

Boolean is_empty(Queue *q){
  if(q == NULL) return true;
  if(q->start == NULL) return true;
  return false;
}

void print(Queue *q){
  Node *aux = q->start;
  for(int i = 0; i < q->size; i++){
    printf("%d -> ",aux->data);
    aux = aux->prox;
  }
  printf("NULL\n");
}


void revert_queue(Queue *q){
  Node *aux = NULL; 
  Node *aux1 = q->start; 
  Node *aux2 = NULL; 
  while (aux1 != NULL) { 
    aux2 = aux1->prox; 
    aux1->prox = aux; 
    aux = aux1; 
    aux1 = aux2; 
  } 
  q->start = aux; 
}

Boolean insert_all_elements(Queue *q, DataType *vector, int size){
  if (q == NULL) return false;

  for(int i = 0; i < size; i++){
    int aux = vector[i];
    insert_element(q, aux);
  }
  return true;
}
