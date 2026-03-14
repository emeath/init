#include <stdio.h>
#include <stdlib.h>
#include "c6-matrix-lib.h"

// gambiarra
int configDebug = 0;

int main(int argc, char **argv) {

    printf("%d---\n", argc);

    if (argc == 2) {
        configDebug = atoi(argv[1]);
    }

    int matrix[5][5];
    int matrixB[5][5];

    readMatrix(matrix, 5, 5);

    multiplyMatrix(matrix, matrix, matrixB);

    printMatrix(matrixB);

    return 0;
}