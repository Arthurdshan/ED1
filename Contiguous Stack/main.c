#include "contiguous_stack.h"

int main(){
  
  Stack* s = create_stack();
  
  push_element(s, 1);
  push_element(s, 2);
  push_element(s, 3);
  push_element(s, 4);
  push_element(s, 5);
  
  print(s);

  destroy_stack(s);
}
