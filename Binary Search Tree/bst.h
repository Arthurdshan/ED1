#pragma once

typedef enum T_NODE {
    ROOT,
    L_LEAF,
    R_LEAF
} T_NODE;

typedef struct BST {
    struct BST *left;
    struct BST *right;
    int key;
} BST;

BST *BST_Search(BST *root, int key);
BST *BST_Create(int key, BST *left, BST *right);
void BST_Insert(BST **root, int key);
int BST_Size(BST *root);
int BST_Height(BST *root);
int BST_BST(BST *root);
void BST_Print(BST *root, int space, T_NODE n);
void BST_Save(BST *root, int space, T_NODE n);
void BST_Remove(BST **root, int key);