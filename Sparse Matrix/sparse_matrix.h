typedef enum boolean {
    false,
    true
} Boolean;

typedef struct node {
    int row;
    int column;
    int data;
    struct node *right;
    struct node *up;
    struct node *left;
    struct node *down;
} Node;

typedef struct {
    Node **rows;         //pointer to the vector whose cells are node pointers
    Node **columns;      //pointer to the vector whose cells are node pointers
    int size_of_rows;    //number of matrix rows
    int size_of_columns; //number of matrix columns
} Matrix;

Matrix *create_matrix(int number_of_rows, int number_of_columns);
Boolean add_value_to_matrix(Matrix *m, int row, int column, int data);
int acess_matrix_position(Matrix *m, int row, int column);
void print(Matrix *m);
Matrix *destroy_matrix(Matrix **matrix_adress);
void insert_column(int row, int column, Node *node, Matrix *m);
void insert_row(int row, int column, Node *node, Matrix *m);
Node *find_node_column(Node *aux, int row, Node *sentinel);
Node *find_node_row(Node *aux, int column, Node *sentinel);
