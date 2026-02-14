#include <stdio.h>

#define N 10

int main()
{
    char listaDePalavras[N][64] = \
        {"banana", "uva", "abacaxi", "maca", \
         "banana", "uva",            "maca", \
         "banana",                   "maca", \
         "banana"};

    int i;
    for (i = 0; i < N; ++i) {
        printf("%s\n", listaDePalavras[i]);
    }

}