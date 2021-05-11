#include <stdlib.h>

#include "bst.h"

BST *bst_1 = NULL;

void test_1() {
    BST_Insert(&bst_1, 70);
    BST_Insert(&bst_1, 39);
    BST_Insert(&bst_1, 88);
    
    BST_Remove(&bst_1, 70);
    
    BST_Print(bst_1, 0, ROOT);    
}

int main() { test_1(); return 0; }