#include "sentinelList.h"

int main(){

  List* l = createList();
  insertNewElement(l, 1, 1);
  print(l);
  insertOnLastPosition(l, 2);
  print(l);
  insertOnLastPosition(l, 3);
  print(l);
  insertOnLastPosition(l, 4);
  print(l);
  insertOnLastPosition(l, 5);
  print(l);
  insertOnLastPosition(l, 6);
  print(l);
  insertOnLastPosition(l, 7);
  print(l);
  insertNewElement(l, 8, 2);
  print(l);
  
  int removed;
  removeFromIndex(l, 3, &removed);
  print(l);

  int pos = getPosition(l, 1);
  
  int pos1 = getPosition(l, 7);
  
  int pos2 = getPosition(l, 10);
  
  removed = removeElement(l, 10);
  
  if(removed == -1) printf("error.\n\n");
  else {
    printf("position of removed element : %d\n", removed);
    print(l);
  }

  removed = removeElement(l, 8);
  if(removed == -1) printf("error.\n\n");
  else {
    printf("position of removed element : %d\t", removed);
    print(l);
  }
  
  int adress;
  searchList(l, 3, &adress);
  printf("the element %d is on position 3.\n\n", adress);

  hasElement(l, 1);
  hasElement(l, 505);
  
  char string[100];
  listToString(l, string);
  printf("%s\n", string);
}