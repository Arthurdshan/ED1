#include<stdio.h>
#include<stdlib.h>

typedef enum boolean{false, true} Boolean;

typedef struct node{
    int row;
    int column;
    int data;
    struct node* right;
    struct node* up;        
    struct node* left;
    struct node* down;
    
}Node;

typedef struct{
    Node** rows;    //pointer to the vector whose cells are node pointers
    Node** columns;    //pointer to the vector whose cells are node pointers
    int sizeOfRows;    //number of matrix rows
    int sizeOfColumns;    //number of matrix columns
}Matrix;

Matrix* create_matrix(int number_of_rows, int number_of_columns);
Boolean add_value_to_matrix(Matrix* m, int row, int column, int data);
int acess_matrix_position(Matrix* m, int row, int column);
void print(Matrix* m);
Matrix* destroy_matrix(Matrix** matrixAdress);
void insert_column(int row, int column, Node* node, Matrix* m);
void insert_row(int row,int column , Node* node, Matrix* m);
Node* find_node_column(Node* aux,int row, Node* sentinel);
Node* find_node_row(Node* aux,int column, Node* sentinel);

Matrix* destroy_matrix(Matrix** matrixAdress){
    Matrix* m = *matrixAdress;
    if(m == NULL){
        printf("Matrix Inexistente!\n");
        return NULL;
    }
    int i = 0;
    Node* sentinel = m->rows[i];

    while(i < m->sizeOfRows){
        if(sentinel != sentinel->right){
            Node* aux = sentinel->right;
            while(aux != sentinel){
                sentinel->right = aux->right;
                free(aux);
                aux = sentinel->right;
            }
        }
        sentinel = m->rows[++i];
    }


    for(int i = 0; i < m->sizeOfRows; i++){
        Node* aux = m->rows[i];
        free(aux);
    }

    for(int i = 0; i < m->sizeOfColumns; i++){
        Node* aux = m->columns[i];
        free(aux);
    }

    free(m->columns);
    free(m->rows);
    free(m);
    *matrixAdress = NULL;
}

Matrix* create_matrix(int number_of_rows, int number_of_columns){

    Matrix* matrix = (Matrix*) malloc(sizeof(Matrix));
    matrix->sizeOfColumns = number_of_columns;
    matrix->sizeOfRows = number_of_rows;

    Node** columns = (Node**) calloc(number_of_columns, sizeof(int*));
    matrix->columns = columns;

    Node** rows = (Node**) calloc(number_of_rows, sizeof(int*));
    matrix->rows = rows;

    for(int i = 0; i < number_of_columns; i++){
        Node* sentinel = (Node*) malloc(sizeof(Node));
        sentinel->up = sentinel;
        sentinel->down = sentinel;
        columns[i] = sentinel;
    }

    for(int i = 0; i < number_of_rows; i++){
        Node* sentinel = (Node*) malloc(sizeof(Node));
        sentinel->left = sentinel;
        sentinel->right = sentinel;
        rows[i] = sentinel;
    }

    return matrix;
}

int acess_matrix_position(Matrix* m, int row, int column){
    if(m == NULL) return 0;
    if(row >= m->sizeOfRows || row < 0) return 0;
    if(column >= m->sizeOfColumns || column < 0) return 0;

    Node* aux1 = find_node_row(m->rows[row]->right, column,m->rows[row]);
    return aux1->data;
}

Node* find_node_column(Node* aux,int row, Node* sentinel){
    
    while(aux != sentinel && row > aux->row){
        aux = aux->down;
    }
    return aux;
}

Node* find_node_row(Node* aux,int column, Node* sentinel){
    
    while(aux != sentinel && column > aux->column){
        aux = aux->right;
    }
    return aux;
}

void insert_column(int row, int column, Node* node, Matrix* m){
    Node* sentinel = m->columns[column];   
    Node* aux = find_node_column(sentinel->down, row, sentinel);
    
    if(aux != sentinel && row == aux->row){
        aux->data = node->data;
        free(node);
    }else{
        node->down = aux;
        node->up = aux->up;
        aux->up->down = node;
        aux->up = node;
    }

}

void insert_row(int row,int column, Node* node, Matrix* m){
    Node* sentinel = m->rows[row];
    Node* aux = find_node_row(sentinel->right,column, sentinel);

    if(aux != sentinel && aux->column == column){
        aux->data = node->data;
        free(node);
    }else{
        node->right = aux;
        node->left = aux->left;            
        aux->left->right = node;
        aux->left = node;
    }
}

Boolean add_value_to_matrix(Matrix* m, int row, int column, int data){
    if(m == NULL) return false;
    
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->column = column;
    node->row = row;
    insert_column(row,column, node, m);
    insert_row(row,column, node, m);

    return true;
}

void print(Matrix* m){
    if(m == NULL){
        printf("Inexistent matrix.\n");
        return;
    }

    for(int i = 0; i < m->sizeOfRows; i++){
        Node* aux = m->rows[i]->right;
        for(int j = 0; j < m->sizeOfColumns; j++){
            if(j != aux->column || aux == m->rows[i]) printf("0\t\t");  
            else{
                printf("%d\t\t",aux->data);
                aux = aux->right;
            }  
        }
        printf("\n\n");
    }
    printf("\n");
}