// #include "StaticStack.h"
#include "LinkedStack.h"

int main(){
  
  Stack* s = createStack();
  
  pushElement(s, 1);
  pushElement(s, 2);
  pushElement(s, 3);
  pushElement(s, 4);
  pushElement(s, 5);
  
  print(s);

  destroyStack(s);
}
