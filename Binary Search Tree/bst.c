#include <stdlib.h>
#include <stdio.h>

#include "bst.h"

BST *BST_Search(BST *root, int key) {
    if(root == NULL) return NULL;

    if(root->key == key) 
        return root;
    if(key < root->key) 
        return BST_Search(root->left, key);
    return BST_Search(root->right, key);
}

BST *BST_Create(int key, BST *left, BST *right) {
    BST *new = (BST *)malloc(sizeof(BST));
    
    new->key = key;
    new->left = left;
    new->right = right;
    
    return new;
}

void BST_Insert(BST **root, int key) {
    if((*root) == NULL) {
        *root = BST_Create(key, NULL, NULL);
        return;
    }
    else if(key < (*root)->key) 
        BST_Insert(&(*root)->left, key);
    else 
        BST_Insert(&(*root)->right, key);
}

int BST_Size(BST *root) {
    if(root == NULL) return 0;
    
    return (1 + BST_Size(root->left) + BST_Size(root->right));
}

int BST_Height(BST *root) {
    if(root == NULL) return -1;

    int lh = BST_Height(root->left);
    int rh = BST_Height(root->right);
    
    if(lh < rh) 
        return rh + 1;
    else 
        return lh + 1;
}

int BST_BST(BST *root) {
    if(root == NULL) return 1;

    if(root->left != NULL && root->left->key > root->key) 
        return 0;

    if(root->right != NULL && root->right->key < root->key) 
        return 0;

    if(!BST_BST(root->left) || !BST_BST(root->right))
        return 0;

    return 1;
}

#ifndef STEP
    #define STEP 10
#endif
void BST_Print(BST *root, int space, T_NODE n) {
    if(root == NULL) return;    

    // r: root
    // e: left
    // d: right
    char c = n == ROOT ? 'r' : (n == L_LEAF ? 'e' : 'd');

    space += STEP;

    BST_Print(root->right, space, R_LEAF);

    printf("\n");
    for(int i = STEP; i < space; i++)
        printf(" ");
    printf("(%c) %d\n", c, root->key);

    BST_Print(root->left, space, L_LEAF);
}

static void BST_AUX_remove_leaf(BST *A, BST *B) {
    if(B->key < A->key)
        A->left = NULL;
    else 
        A->right = NULL;
    free(B);    
}

static void BST_AUX_remove_single_child(BST **A, BST *B, BST *node) {
    if(node->key < B->key) {
        if(node->left != NULL) 
            B->left = node->left;
        else 
            B->left = node->right;
    }
    else {
        if(node->left != NULL)
            if(B == node) (*A) = node->left;
            else B->right = node->left;
        else 
            if(B == node) (*A) = node->right;
            else B->right = node->right;
    }
    free(node);
}

static void BST_AUX_remove_double_child(BST **A, BST *node) {
    BST *sucessor = node->right;
    BST *root_sucessor = node;

    while(sucessor->left != NULL) {
        root_sucessor = sucessor;
        sucessor = sucessor->left;
    }

    node->key = sucessor->key;

    if(sucessor->right == NULL && sucessor->left == NULL)
        BST_AUX_remove_leaf(root_sucessor, sucessor);
    else 
        BST_AUX_remove_single_child(A, root_sucessor, sucessor);
}

void BST_Remove(BST **root, int key) {
    if((*root) == NULL) return;

    BST *node = (*root);
    BST *traversal = (*root);

    while (node->key != key) {
        traversal = node;
        if(key < node->key) 
            node = node->left;
        else 
            node = node->right;
    } 

    if(node->right == NULL && node->left == NULL) 
        BST_AUX_remove_leaf(traversal, node);
    else if(node->right == NULL || node->left == NULL) 
        BST_AUX_remove_single_child(root, traversal, node);
    else    
        BST_AUX_remove_double_child(root, node);
}