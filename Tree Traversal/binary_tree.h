#pragma once 

typedef struct BT {
    int key;
    struct BT *left;
    struct BT *right;
} BT;

void preorder_traversal(BT *root);
void inorder_traversal(BT *root);
void postorder_traversal(BT *root);