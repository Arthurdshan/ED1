#include "circularQueue.h"
// #include "queueEncadeada.h"

int main(){

  int removed, first;
  int t = 3;
  DataType v[3] = {1,2,3};
  Queue* f = createQueue();     
  print(f);          
  insertElement(f, 1);                       
  insertElement(f, 2);                       
  insertElement(f, 3);                        
  insertElement(f, 4); 
  print(f);
  removeElement(f, &removed);              
  print(f);

  firstElement(f, &first);
  Queue* fc = cloneQueue(f);
  print(fc);
  revertQueue(fc);
  print(fc);
  insertAllElements(f, v, t);
  print(f);
  destroyQueue(f);
  destroyQueue(fc);
}