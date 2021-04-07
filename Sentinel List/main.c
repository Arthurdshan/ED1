#include "sentinelList.h"

int main(){

  List* l = create_List();
  insert_new_element(l, 1, 1);
  print(l);
  insert_on_last_position(l, 2);
  print(l);
  insert_on_last_position(l, 3);
  print(l);
  insert_on_last_position(l, 4);
  print(l);
  insert_on_last_position(l, 5);
  print(l);
  insert_on_last_position(l, 6);
  print(l);
  insert_on_last_position(l, 7);
  print(l);
  insert_new_element(l, 8, 2);
  print(l);
  
  int removed;
  remove_from_index(l, 3, &removed);
  print(l);

  int pos = get_position(l, 1);
  
  int pos1 = get_position(l, 7);
  
  int pos2 = get_position(l, 10);
  
  removed = remove_element(l, 10);
  
  if(removed == -1) printf("error.\n\n");
  else {
    printf("position of removed element : %d\n", removed);
    print(l);
  }

  removed = remove_element(l, 8);
  if(removed == -1) printf("error.\n\n");
  else {
    printf("position of removed element : %d\t", removed);
    print(l);
  }
  
  int adress;
  search_list(l, 3, &adress);
  printf("the element %d is on position 3.\n\n", adress);

  has_element(l, 1);
  has_element(l, 505);
  
  char string[100];
  list_to_string(l, string);
  printf("%s\n", string);
}