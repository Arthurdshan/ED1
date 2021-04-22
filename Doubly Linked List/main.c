#include "doubly_linked_list.h"

int main() { 
    
    List *L = create_list(); 

    insert_into_list(L, 1);
    insert_into_list(L, 2);
    insert_into_list(L, 3);
    
    print_list(L);

}