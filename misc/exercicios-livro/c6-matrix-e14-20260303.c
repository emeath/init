#include <stdio.h>
#include "c6-matrix-lib.h"

int main(int argc, char **argv) {
    
    int matrix[5][5];
    int sumMainOrSecondary = 0;
    int sumOutside = 0;

    readMatrix(matrix, 5, 5);

    calculateElementsInMainOrSecondaryDiag(matrix, 5, 5, &sumMainOrSecondary);
    calculateElementsOutsideDiags(matrix, 5, 5, &sumOutside);

    printf("The difference is: %d\n", sumMainOrSecondary - sumOutside);
    
    return 0;
}