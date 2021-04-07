#include "circular_queue.h"

int main(){

  int removed;

  Queue *q = create_queue();     
  print_queue(q);          
  insert_element(q, 1);                       
  insert_element(q, 2);                       
  insert_element(q, 3);                        
  insert_element(q, 4); 
  print_queue(q);
  remove_element(q, &removed);              
  print_queue(q);

}