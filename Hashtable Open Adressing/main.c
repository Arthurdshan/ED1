#include "hashtable_oa.h"

int main(int argv, char **argc){

    HTOA *new_table = HTOA_create(10);
    HTOA_insert(new_table, 10, 1);
    HTOA_insert(new_table, 10, 2);
    HTOA_destroy(new_table);
}