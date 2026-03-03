#include <stdio.h>
#include "c6-matrix-lib.h"

extern int configDebug;

int isInMainDiag(size_t i, size_t j)
{
    if(i==j) return 1;
    else return 0;
}

int isInSecondaryDiag(size_t i, size_t j, size_t lenSquareMatrix)
{
    if( i + j + 1 == lenSquareMatrix) return 1;
    else return 0;
}

void calculateElementsInMainOrSecondaryDiag(int m[][sizeMatrix],
                                            size_t lines,
                                            size_t cols,
                                            int *destAns)
{
    size_t i, j;
    int sum=0;
    for (i=0;i<lines;++i){
        for (j=0;j<cols;++j) {
            if( isInMainDiag(i,j)
                || isInSecondaryDiag(i,j,lines) ) {
                sum += m[i][j];
            }
        }
    }
    *destAns = sum;
}

void calculateElementsOutsideDiags(int m[][sizeMatrix],
                                    size_t lines,
                                    size_t cols,
                                    int *destAns)
{
    size_t i, j;
    int sum = 0;
    for(i=0;i<lines;++i) {
        for(j=0;j<cols;++j) {
            if( !isInMainDiag(i,j) 
                && !isInSecondaryDiag(i,j,lines) ) {
                    sum += m[i][j];
            }
        }
    }
    *destAns = sum;
}

void readMatrix(int destM[][sizeMatrix],
                size_t lines,
                size_t cols)
{
    size_t i, j;
    for(i=0;i<lines;++i){
        for(j=0;j<cols;++j){
            scanf("%d", &destM[i][j]);
        }
    }
}

void multiplyMatrix(int a[][sizeMatrix], int b[][sizeMatrix], int ans[][sizeMatrix])
{
    size_t i,j;

    /*
    
    A m x n   X    B n x p    =   C m x p  => C = A x B
    
            n-1
          _____
          \    
    C_ij = >     A_ik * B_kj
          /____
           k=0
    */

    size_t n = sizeMatrix;
    size_t k;
    int sum = 0;

    for(i=0;i<n;++i){
        for(j=0;j<n;++j) {
            sum = 0;
            if(configDebug == 1) {
                    printf("C[%d][%d] = ", i, j);
            }
            for(k=0;k<=n-1;++k) {
                sum += a[i][k] * b[k][j];
                if(configDebug == 1) {
                    printf("%d * %d", a[i][k], b[k][j]);
                    if(k==n-1) printf("= %d\n", sum);
                    else printf(" + ");
                }

            }
            if(configDebug == 1) {
                printf("\n");
            }
            ans[i][j] = sum;
        }
    }
}

void printMatrix(int m[][sizeMatrix])
{
    size_t i,j;
    for(i=0;i<sizeMatrix;++i) {
        printf("|");
        for(j=0;j<sizeMatrix;++j) {
            printf(" %8d ", m[i][j]);
        }
        printf("|\n");
    }
}