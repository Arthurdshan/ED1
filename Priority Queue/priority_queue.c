#include <stdio.h>
#include <stdlib.h>
#define T 10

#include "priority_queue.h"

priority_queue* create_queue(){
  priority_queue* q = (priority_queue*) malloc(sizeof(priority_queue));
  q->array = (DataType*) calloc(T, sizeof(DataType));
  q->size = 0;
  q->length = T;
  return q;
}

Boolean insert_in_queue(priority_queue* q, DataType value){
  if(q == NULL) return false;
  if(q->size == q->length) return false;

  q->array[q->size] = value;
  promove_element(q,q->size);
  q->size++;
  return true;
}

void promove_element(priority_queue* q, int leaf){
  if(q->array[leaf] <= q->array[root(leaf)]) return;
  switch_elements(&q->array[leaf],&q->array[root(leaf)]);
  promove_element(q, root(leaf));
}

void switch_elements(DataType* a, DataType* b){
  int aux = *a;
  *a = *b;
  *b = aux;
}

int root(int j){
  return ((j - 1) / 2);
}

int left_leaf(int i){
  return i * 2 + 1;
}

int right_leaf(int i){
  return i * 2 + 2;
}

void destroy_queue(priority_queue* q){
  if(is_empty(q)) return;
  free(q->array);
  free(q);
}

Boolean is_empty(priority_queue* q){
  if(q == NULL) return true;
  return false;
}

void print(priority_queue* q){
  if(is_empty(q)) return;

  printf("[%d", q->array[0]);
  for(int i = 1; i < q->size; i++){
    printf(", %d", q->array[i]);
  }
  printf("]\n");
}

Boolean remove_from_queue(priority_queue* q, DataType* mem_adress){
  if(is_empty(q)) return false;
  
  *mem_adress = q->array[q->size - 1];
  switch_elements(&q->array[0], &q->array[q->size - 1]);
  q->size--;
  down_element(q, 0);
  return true;
}

void down_element(priority_queue* q, int root){
  if(left_leaf(root) < q->size){
    
    int largest_element = left_leaf(root);
    int right = (right_leaf(root) < q->size ? 1 : 0);
    
    if(right && q->array[right_leaf(root)] > q->array[left_leaf(root)])
      largest_element = right_leaf(root);

    if(q->array[root] < q->array[largest_element]){
      switch_elements(&q->array[root], &q->array[largest_element]);
      down_element(q, largest_element);
    }
  }
}

int get_size(priority_queue* q){
  return (q->size);
}

priority_queue* clone_queue(priority_queue* q){
  priority_queue *fc = create_queue();
  for(int i = 0; i < q->size; i++){
    fc->array[i] = q->array[i];
  }
  fc->size = q->size;
  fc->length = q->length;
  return fc;
}

Boolean insert_all_elements(priority_queue* q, DataType* array, int size){
  if(q == NULL) return false;

  for(int i = 0; i < size; i++){
    int aux = array[i];
    insert_in_queue(q, aux);
  }
  return true;
}