/**
 * https://judge.beecrowd.com/pt/problems/view/1042
 * 
 * beecrowd | 1042
Sort Simples
Adaptado por Neilor Tonin, URI  Brasil

Timelimit: 1

Leia 3 valores inteiros e ordene-os em ordem crescente. No final, mostre os valores em ordem crescente, uma linha em branco e em seguida, os valores na sequência como foram lidos.

Entrada
A entrada contem três números inteiros.

Saída
Imprima a saída conforme foi especificado.

Exemplo de Entrada                          Exemplo de Saída
7 21 -14                                    -14
                                            7
                                            21

                                            7
                                            21
                                            -14
                                            

-14 21 7                                    -14
                                            7
                                            21

                                            -14
                                            21
                                            7                                   
 */

#include <stdio.h>
#define N 3

void troca(int *array, size_t sizeArray, size_t atual, size_t proximo) {
    int aux;
    aux = array[proximo];
    array[proximo] = array[atual];
    array[atual] = aux;
}

void print(int *arr, size_t size) {
    for(int i = 0; i < size; ++i) {
        printf("%d\n", arr[i]);
    }
}

void copyArray(int *dest, int *src, size_t size) {
    for(int i = 0; i < size; ++i) {
        dest[i] = src[i];
    }
}

int main()
{
    int i,j;
    int array[N], aux[N];
    scanf("%d %d %d", &array[0], &array[1], &array[2]);

    copyArray(aux, array, N);

    for(i = 0; i < N; i++) {
        for(j = 0; j < N - i - 1; ++j) {
            if(array[j] > array[j + 1]) troca(array, N, j, j+1);
        }
    }

    // ordenados crescente
    print(array, N);
    printf("\n");
    print(aux, N);



    return 0;
}
