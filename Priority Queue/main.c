#include<stdio.h>
#include<stdlib.h>
#include "priorityHeader.h"

int main(){

  priorityQueue* q = createQueue();                     
  insertInQueue(q, 6);                        
  insertInQueue(q, 12);                         
  insertInQueue(q, 7);                         
  insertInQueue(q, 9);                  
  insertInQueue(q, 10);       
  insertInQueue(q, 20);                         
  insertInQueue(q, 5);                         
  insertInQueue(q, 14);                       
  
  print(q);
  printf("cloned queue:\n");  
  
  priorityQueue* qc = cloneQueue(q);
  
  print(qc);       
  printf("second queue:\n");    
  
  DataType v[6] = {3,6,5,1,7};        

  priorityQueue* q2 = createQueue();
  
  insertInQueue(q2, 10);                        
  insertInQueue(q2, 9);                         
  insertInQueue(q2, 4);
  insertInQueue(q2, 7);       
  insertInQueue(q2, 8); 
  insertAllElements(q2, v, 6);
  print(q2);   

  printf("%d elements on first queue\n", getSize(q));

  destroyQueue(q);
  destroyQueue(q2);
}