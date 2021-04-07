#include<stdio.h>
#include "priority_queue.h"

int main(){

  priority_queue* q = create_queue();                     
  insert_in_queue(q, 6);                        
  insert_in_queue(q, 12);                         
  insert_in_queue(q, 7);                         
  insert_in_queue(q, 9);                  
  insert_in_queue(q, 10);       
  insert_in_queue(q, 20);                         
  insert_in_queue(q, 5);                         
  insert_in_queue(q, 14);                       
  
  print(q);
  printf("cloned queue:\n");  
  
  priority_queue* cq = clone_queue(q);
  
  print(cq);       
  printf("second queue:\n");    
  
  int v[6] = {3,6,5,1,7};        

  priority_queue* q2 = create_queue();
  
  insert_in_queue(q2, 10);                        
  insert_in_queue(q2, 9);                         
  insert_in_queue(q2, 4);
  insert_in_queue(q2, 7);       
  insert_in_queue(q2, 8); 
  insert_all_elements(q2, v, 6);
  print(q2);   

  printf("%d elements on first queue\n", get_size(q));

  destroy_queue(q);
  destroy_queue(q2);
}