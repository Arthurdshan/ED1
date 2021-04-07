#include "sparseMatrix.h"

int main(){
    Matrix* matrix = create_matrix(4,4);
    add_value_to_matrix(matrix, 0,2,3);
    add_value_to_matrix(matrix, 0, 1, 1);
    add_value_to_matrix(matrix, 1, 3, 23);
    add_value_to_matrix(matrix, 1, 2, 2);
    add_value_to_matrix(matrix, 1, 1, 2);
    add_value_to_matrix(matrix, 0, 3, 63);
    add_value_to_matrix(matrix, 3, 2, 3);
    add_value_to_matrix(matrix, 3, 3, 13);
    
    print(matrix);

    int before = acess_matrix_position(matrix, 3,2);
    printf("position [3,2]: %d\n", before);

    destroy_matrix(&matrix);
    print(matrix);

    int after = acess_matrix_position(matrix, 3,2);
    printf("position [3,2]: %d\n", after);

    return 0;
}