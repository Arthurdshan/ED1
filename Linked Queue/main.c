#include "linked_queue.h"

int main(){

  int removed;

  Queue *q = create_queue();     
  print(q);          
  insert_element(q, 1);                       
  insert_element(q, 2);                       
  insert_element(q, 3);                        
  insert_element(q, 4); 
  print(q);
  remove_element(q, &removed);              
  print(q);

}