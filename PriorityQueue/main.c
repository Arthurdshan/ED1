#include<stdio.h>
#include<stdlib.h>
#include "priorityQueue.h"

int main(){

  priorityQueue* f = createQueue();                     
  insertInQueue(f, 10);                        
  insertInQueue(f, 1);                         
  insertInQueue(f, 9);                         
  insertInQueue(f, 8);                  
  insertInQueue(f, 7);       
  insertInQueue(f, 6);                         
  insertInQueue(f, 5);                         
  insertInQueue(f, 4);
  insertInQueue(f, 3);                         
  insertInQueue(f, 2);                         
  print(f);
  printf("fila clonada:\n");  
  priorityQueue* fc = cloneQueue(f);
  print(fc);       
  printf("fila 2:\n");    
  DataType v[6] = {3,6,5,1,7};        
  priorityQueue* f2 = createQueue();
  insertInQueue(f2, 10);                        
  insertInQueue(f2, 9);                         
  insertInQueue(f2, 4);
  insertInQueue(f2, 7);       
  insertInQueue(f2, 8); 
  insertAllElements(f2, v, 6);
  print(f2);   

  printf("%d elementos na fila 1\n", getSize(f));

}