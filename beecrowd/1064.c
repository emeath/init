/*
https://judge.beecrowd.com/pt/problems/view/1064


beecrowd | 1064
Positivos e Média
Adaptado por Neilor Tonin, URI  Brasil

Timelimit: 1

Leia 6 valores. Em seguida, mostre quantos destes valores digitados foram positivos. Na próxima linha, deve-se mostrar a média de todos os valores positivos digitados, com um dígito após o ponto decimal.

Entrada
A entrada contém 6 números que podem ser valores inteiros ou de ponto flutuante. Pelo menos um destes números será positivo.

Saída
O primeiro valor de saída é a quantidade de valores positivos. A próxima linha deve mostrar a média dos valores positivos digitados.


Exemplo de Entrada
7
-5
6
-3.4
4.6
12


Exemplo de Saída
4 valores positivos
7.4

*/



#include <stdio.h>
#include <stdlib.h>

int main()
{
    float input[6];
    size_t i;
    float *positiveNumbers;
    float *tmp;
    size_t sizePositive = 0;
    float avgPositiveNumbers = 0;
    for(i = 0; i < 6; ++i)
    {
        scanf("%f", (input + i));
        if ( *(input + i) > 0 ) 
        {
            if ( sizePositive == 0 )
            {
                positiveNumbers = (float *) malloc ( 1 * sizeof(float) );
                if ( NULL == positiveNumbers )
                {
                    printf("Error on allocating memory\n");    
                    return 1;
                }
                positiveNumbers[0] = *(input + i);
            } 
            else
            {
                tmp = realloc(positiveNumbers, (sizePositive + 1) * sizeof(float));
                if ( NULL == tmp ) 
                {
                    printf("Error on reallocating memory\n");
                    return 1;
                }
                else
                {
                    positiveNumbers = tmp;
                    tmp = NULL; // avoid dangling pointer
                }
                positiveNumbers[sizePositive] = *(input + i);
            }
            ++sizePositive;
        }
    }

    for(i = 0 ; i < sizePositive; ++i)
    {
        avgPositiveNumbers += positiveNumbers[i];
    }
    avgPositiveNumbers /= (sizePositive * 1.0);
  
    // be caferul to not do double free
    // do not free tmp and positiveNumbers. Since they point to same place, free only one. 
    // free(tmp);
    free(positiveNumbers);
    // AVOID DANGLING POINTERS
    tmp = NULL;
    positiveNumbers = NULL;

 
    printf("%ld valores positivos\n", sizePositive);
    printf("%.1f\n", avgPositiveNumbers);
    
    return 0;
}
