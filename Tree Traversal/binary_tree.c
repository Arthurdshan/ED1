#include <stdio.h>
#include "binary_tree.h"

void preorder_traversal(BT *root) {
    if(root == NULL) return;
 
    printf("%d\n", root->key);
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

void inorder_traversal(BT *root) {
    if(root == NULL) return;

    inorder_traversal(root->left);
    printf("%d\n", root->key);
    inorder_traversal(root->right);
    printf("%d\n", root->key);
}

void postorder_traversal(BT *root) {
    if(root == NULL) return;
    
    inorder_traversal(root->left);
    inorder_traversal(root->right);
    printf("%d\n", root->key);
}