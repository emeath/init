#include <stdio.h>

void readMatrix(int [][5], size_t, size_t);
int calculateElementsAboveMainDiag(int [][5], size_t, size_t);

int main()
{
    printf("Enter matrix 5x5\n");
    // read matrix
    int m[5][5];
    readMatrix(m, 5, 5);
    // calculate elements above main diagonal
    printf("sum elements above main diagonal = %d\n",
            calculateElementsAboveMainDiag(m, 5, 5));
    return 0;
}

void readMatrix(int m[][5], size_t lines, size_t cols)
{
    size_t i,j;
    for(i=0;i<lines;++i){
        for(j=0;j<cols;++j){
            scanf("%d", &m[i][j]);
        }
    }
}

int calculateElementsAboveMainDiag(int m[][5],
                                   size_t lines,
                                   size_t cols)
{
    size_t i,j;
    int sum=0;   
    for(i=0;i<lines;++i){
        for(j=0;j < cols - 1 - i; ++j){
            sum += m[i][j+i+1];
        }    
    }
    return sum;
}
