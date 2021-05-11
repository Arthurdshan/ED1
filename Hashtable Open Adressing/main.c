#include "hashtable_oa.h"

int main(int argv, char **argc){

    HTOA *new_table = HTOA_create(3);
    
    HTOA_insert(new_table, 10, 10);
    HTOA_insert(new_table, 21, 21);
    HTOA_insert(new_table, 44, 44);
    HTOA_insert(new_table, 32, 32);
    HTOA_insert(new_table, 12, 12);
    HTOA_insert(new_table, 37, 37);
    HTOA_insert(new_table, 43, 43);
    HTOA_insert(new_table, 10, 10);

    HTOA_destroy(new_table);
}