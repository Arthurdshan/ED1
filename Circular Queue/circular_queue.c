#include<stdio.h>
#include<stdlib.h>
#define MAX 8

#include "circular_queue.h"

Queue* create_queue(){

  Queue* queue = (Queue*) malloc(sizeof(Queue));
  queue->vector = (DataType*) calloc(MAX, sizeof(DataType));
  
  if(queue != NULL){
  queue->length = MAX;
	queue->start = 0;
	queue->end = 0;
	queue->size = 0;
  }
  return queue;
}
void print_queue(Queue* q){
  printf("[");
  for(int i = q->start; i < q->end; i++){
    if(i == q->start)
      printf("%d",q->vector[i%q->length]);
    else
      printf(", %d",q->vector[i%q->length]);
    }
    printf("]\n");
}
void destroy_queue(Queue* q){
  free(q->vector);
  free(q);
}

Boolean insert_element(Queue* q, DataType data){
  if(q == NULL || q->size == MAX) return false;
  
  else{
  q->vector[q->end] = data;
  q->end = (q->end+1) % MAX;
  q->size++;
  return true;
  }
}

Boolean remove_element(Queue* q, DataType* mem_adress){
  if(q == NULL || is_empty(q)) return false;
  
  *mem_adress = q->vector[q->start%q->length]; 
  q->start = (q->start+1) % MAX;
  q->size--;
  return true;
}

Boolean first_element(Queue* q, DataType* mem_adress){
  if(is_empty(q)) return false;
  else{
    *mem_adress = q->vector[q->start];
    return true;
  }
}

Boolean is_empty(Queue* q){
  if(q->size == 0) return true;
  else return false;
}

int get_size(Queue* q){
  return (q->end - q->start);
}

Queue* clone_queue(Queue* q){
  Queue* cq = create_queue();
  for(int i = q->start; i < q->end; i++){
    insert_element(cq, q->vector[i]);
  }
  cq->size = q->size;
  cq->length = q->length;
  return cq;
}

void revert_queue(Queue* q){
  DataType* revert = (DataType*) calloc(q->length, sizeof(DataType));
  for(int i = q->size - 1, j = 0; i >= 0; i--, j++){
    revert[j] = q->vector[i];
  }
  free(q->vector);
  q->vector = revert;
}

Boolean insert_all_elements(Queue* q, DataType* vector, int length){
  for(int i = 0; i < length; i++){
    insert_element(q, vector[i]);
  }
  return true;
}