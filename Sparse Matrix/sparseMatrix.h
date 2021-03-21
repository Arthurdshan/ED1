#include<stdio.h>
#include<stdlib.h>

typedef enum boolean{FALSE, TRUE} Boolean;
typedef int DataType;

typedef struct node{
    int row;
    int column;
    int value;
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


Matrix* createMatrix(int numberOfRows, int numberOfColumns);
Boolean addValueToMatrix(Matrix* m, int row, int column, int value);
int acessMatrixPosition(Matrix* m, int row, int column);
void print(Matrix* m);
Matrix* destroyMatrix(Matrix** m);
void insertColumn(int row, int column, Node* no, Matrix* m);
void insertRow(int row,int column , Node* no, Matrix* m);
Node* findNodeColumn(Node* aux,int row, Node* sentinel);
Node* findNodeRow(Node* aux,int column, Node* sentinel);

Matrix* destroyMatrix(Matrix** matrixAdress){
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

Matrix* createMatrix(int numberOfRows, int numberOfColumns){

    Matrix* matrix = (Matrix*) malloc(sizeof(Matrix));
    matrix->sizeOfColumns = numberOfColumns;
    matrix->sizeOfRows = numberOfRows;

    Node** columns = (Node**) calloc(numberOfColumns, sizeof(DataType*));
    matrix->columns = columns;

    Node** rows = (Node**) calloc(numberOfRows, sizeof(DataType*));
    matrix->rows = rows;

    for(int i = 0; i < numberOfColumns; i++){
        Node* sentinel = (Node*) malloc(sizeof(Node));
        sentinel->up = sentinel;
        sentinel->down = sentinel;
        columns[i] = sentinel;
    }

    for(int i = 0; i < numberOfRows; i++){
        Node* sentinel = (Node*) malloc(sizeof(Node));
        sentinel->left = sentinel;
        sentinel->right = sentinel;
        rows[i] = sentinel;
    }

    return matrix;
}

int acessMatrixPosition(Matrix* m, int row, int column){
    if(m == NULL) return 0;
    if(row >= m->sizeOfRows || row < 0) return 0;
    if(column >= m->sizeOfColumns || column < 0) return 0;

    Node* aux1 = findNodeRow(m->rows[row]->right, column,m->rows[row]);
    return aux1->value;
}

Node* findNodeColumn(Node* aux,int row, Node* sentinel){
    
    while(aux != sentinel && row > aux->row){
        aux = aux->down;
    }
    return aux;
}

Node* findNodeRow(Node* aux,int column, Node* sentinel){
    
    while(aux != sentinel && column > aux->column){
        aux = aux->right;
    }
    return aux;
}

void insertColumn(int row, int column, Node* no, Matrix* m){
    Node* sentinel = m->columns[column];   
    Node* aux = findNodeColumn(sentinel->down, row, sentinel);
    
    if(aux != sentinel && row == aux->row){
        aux->value = no->value;
        free(no);
    }else{
        no->down = aux;
        no->up = aux->up;
        aux->up->down = no;
        aux->up = no;
    }

}

void insertRow(int row,int column, Node* no, Matrix* m){
    Node* sentinel = m->rows[row];
    Node* aux = findNodeRow(sentinel->right,column, sentinel);

    if(aux != sentinel && aux->column == column){
        aux->value = no->value;
        free(no);
    }else{
        no->right = aux;
        no->left = aux->left;            
        aux->left->right = no;
        aux->left = no;
    }
}

Boolean addValueToMatrix(Matrix* m, int row, int column, int value){
    if(m == NULL) return FALSE;
    
    Node* no = (Node*) malloc(sizeof(Node));
    no->value = value;
    no->column = column;
    no->row = row;
    insertColumn(row,column, no, m);
    insertRow(row,column, no, m);

    return TRUE;
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
                printf("%d\t\t",aux->value);
                aux = aux->right;
            }  
        }
        printf("\n\n");
    }
    printf("\n");
}