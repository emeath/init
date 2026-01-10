/*
https://judge.beecrowd.com/pt/problems/view/1010

beecrowd | 1010
Cálculo Simples
Adaptado por Neilor Tonin, URI  Brasil

Timelimit: 1

Neste problema, deve-se ler o código de uma peça 1, o número de peças 1, o valor unitário de cada peça 1, o código de uma peça 2, o número de peças 2 e o valor unitário de cada peça 2. Após, calcule e mostre o valor a ser pago.

Entrada

O arquivo de entrada contém duas linhas de dados. Em cada linha haverá 3 valores, respectivamente dois inteiros e um valor com 2 casas decimais.

Saída

A saída deverá ser uma mensagem conforme o exemplo fornecido abaixo, lembrando de deixar um espaço após os dois pontos e um espaço após o "R$". O valor deverá ser apresentado com 2 casas após o ponto.

Exemplos de Entrada	Exemplos de Saída

12 1 5.30		VALOR A PAGAR: R$ 15.50
16 2 5.10



13 2 15.30		VALOR A PAGAR: R$ 51.40
161 4 5.20



1 1 15.10		VALOR A PAGAR: R$ 30.20
2 1 15.10
*/

#include <stdio.h>
int main(){
    int codigoPeca_1, numeroPecas_1, codigoPeca_2, numeroPecas_2;
    float valorUnitarioPeca_1, valorUnitarioPeca_2;
    scanf("%d %d %f", &codigoPeca_1, &numeroPecas_1, &valorUnitarioPeca_1);
    scanf("%d %d %f", &codigoPeca_2, &numeroPecas_2, &valorUnitarioPeca_2);
    printf("VALOR A PAGAR: R$ %.2f\n", (numeroPecas_1 * valorUnitarioPeca_1) + (numeroPecas_2 * valorUnitarioPeca_2));
    return 0;
}
