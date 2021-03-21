#include "sparseMatrix.h"

int main(){
    Matrix* matrix = createMatrix(4,4);
    addValueToMatrix(matrix, 0,2,3);
    // addValueToMatrix(matrix, 1,0,662);
    addValueToMatrix(matrix, 0, 1, 1);
    addValueToMatrix(matrix, 1, 3, 23);
    addValueToMatrix(matrix, 1, 2, 2);
    addValueToMatrix(matrix, 1, 1, 2);
    addValueToMatrix(matrix, 0, 3, 63);
    addValueToMatrix(matrix, 3, 2, 3);
    addValueToMatrix(matrix, 3, 3, 13);
    
    print(matrix);

    int before = acessMatrixPosition(matrix, 3,2);
    printf("position [3,2]: %d\n", before);

    destroyMatrix(&matrix);
    print(matrix);

    int after = acessMatrixPosition(matrix, 3,2);
    printf("position [3,2]: %d\n", after);

    return 0;
}