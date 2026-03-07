/*

2026-03-07

array = {1, 0, 0, 1, 1, 1}
marteloSize = 3;
max score = ?

tsg

*/


#include <stdio.h>
#include <stdlib.h>

#define N 6

int getQuantidadeSubArrays(int, int);
int getMaxValuInArray(int *, size_t);

int main()
{
    int array[N] = {1, 0, 0, 1, 1, 1};
    size_t i, j;
    int sizeMartelo = 3;
    int quantidadeSubArrays = getQuantidadeSubArrays(N, sizeMartelo);
    int *scoresInSubArrays = (int *) malloc( quantidadeSubArrays * sizeof(int) );
    int sum;
    for(i=0; i<quantidadeSubArrays; ++i) {
        sum = 0;
        for(j=i; j<(i+sizeMartelo); ++j) {
            sum += array[j];
            *(scoresInSubArrays + i) = sum;
        }
    }

    #ifdef DEBUG
    for(i=0;i<quantidadeSubArrays; ++i) {
        printf("%d\n", scoresInSubArrays[i]);
    }
    #endif

    printf("Maior pontuacao possivel: %d\n", getMaxValuInArray(scoresInSubArrays, quantidadeSubArrays));

    free(scoresInSubArrays);
    return 0;
}

int getQuantidadeSubArrays(int sizeArray, int sizeMartelo)
{
    int diff = sizeArray - sizeMartelo;
    return diff < 0 ? 1 : diff + 1;
}

int getMaxValuInArray(int *array, size_t size)
{
    size_t i;
    int max = *array;
    for(i=0; i<size; ++i) {
        if(max < *(array + i)) max = *(array + i);
    }
    return max;
}
