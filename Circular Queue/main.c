#include "circularQueue.h"

int main(){

  int removed;

  Queue* q = createQueue();     
  print(q);          
  insertElement(q, 1);                       
  insertElement(q, 2);                       
  insertElement(q, 3);                        
  insertElement(q, 4); 
  print(q);
  removeElement(q, &removed);              
  print(q);

}