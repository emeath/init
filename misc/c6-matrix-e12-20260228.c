#include <stdio.h>

void readMatrix(int [][5], size_t, size_t);
int calculateSumUnderMainDiag(int [][5], size_t, size_t);

int main()
{
    int m[5][5];
    int result = 0;
    // read
    readMatrix(m, 5, 5);
    // get sum
    result = calculateSumUnderMainDiag(m, 5, 5);
    printf("Sum of elements under main diag = %d\n", result);
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

int calculateSumUnderMainDiag(int m[][5],
                              size_t lines,
                              size_t cols)
{
    size_t i,j;
    int sum=0;
    for(i=0;i<lines;++i){
        for(j=0;j<i;++j){
            sum+=m[i][j];
        }
    }
    return sum;
}

/*

0    1    2    3    4  (j)
   +----+----+----+----+----+
0  | [1]|  2 |  3 |  4 |  5 |
   +----+----+----+----+----+
1  |  6 | [7]|  8 |  9 | 10 |
   +----+----+----+----+----+
2  | 11 | 12 |[13]| 14 | 15 |
   +----+----+----+----+----+
3  | 16 | 17 | 18 |[19]| 20 |
   +----+----+----+----+----+
4  | 21 | 22 | 23 | 24 |[25]|
   +----+----+----+----+----+
(i)

0     1     2     3     4  
    _______________________________
 0 | [ 1 ]   .     .     .     .  |
 1 |  ###  [ 7 ]   .     .     .  |
 2 |  ###   ###   [13    .     .  |
 3 |  ###   ###   ###   [19]   .  |
 4 |  ###   ###   ###   ###  [25] |
    ‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾
     [ N ] = Diagonal 
      ###  = Verde    
       .   = Branco   


*/
