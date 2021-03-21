// #include "circularQueue.h"
#include "LinkedQueue.h"

int main(){

  int removed;

  Queue* f = createQueue();     
  print(f);          
  insertElement(f, 1);                       
  insertElement(f, 2);                       
  insertElement(f, 3);                        
  insertElement(f, 4); 
  print(f);
  removeElement(f, &removed);              
  print(f);

}