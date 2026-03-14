#include <stdio.h>

void readMatrix(int [][5], size_t, size_t);
void calculateElementsOutside(int [][5], size_t, size_t, int *);
int isInMainDiag(size_t, size_t);
int isInSecondaryDiag(size_t, size_t, size_t);
 
int main()
{
    const size_t size = 5;
    int m[size][size], sum;
    printf("Enter matrix 5x5\n");
    // read
    readMatrix(m, size, size);
    // calculate elements not in main or secondary diagonal
    calculateElementsOutside(m, size, size, &sum);
    printf("Sum elements outside is: %d\n", sum);    
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

void calculateElementsOutside(  int m[][5],
                                size_t lines,
                                size_t cols,
                                int *destAns  )
{
    size_t i,j;
    int sum=0;
    for(i=0;i<lines;++i){
        for(j=0;j<cols;++j){
            if( !isInMainDiag(i, j) 
                && !isInSecondaryDiag(i, j, cols) ) {
                    sum += m[i][j];
            }
        }
    }
    *destAns = sum;
}

int isInMainDiag(size_t i, size_t j)
{
    if(i == j) return 1;
    else return 0;
}

int isInSecondaryDiag(size_t i, size_t j, size_t lenMatrix)
{
    if ( i + j + 1 == lenMatrix) return 1;
    else return 0;
}
