/*
https://judge.beecrowd.com/pt/problems/view/1015

beecrowd | 1015
Distância Entre Dois Pontos
Adaptado por Neilor Tonin, URI  Brasil

Timelimit: 1
Leia os quatro valores correspondentes aos eixos x e y de dois pontos quaisquer no plano, p1(x1,y1) e p2(x2,y2) e calcule a distância entre eles, mostrando 4 casas decimais, segundo a fórmula:

Distancia = ( (x2-x1)^2 + (y2-y1)^2 )^(1/2)

Entrada
O arquivo de entrada contém duas linhas de dados. A primeira linha contém dois valores de ponto flutuante: x1 y1 e a segunda linha contém dois valores de ponto flutuante x2 y2.

Saída
Calcule e imprima o valor da distância segundo a fórmula fornecida, considerando 4 casas decimais.

           Exemplo de Entrada                     Exemplo de Saída
--------------------------------------------------------------------------------
1.0 7.0                               |    4.4721
5.0 9.0                               |
--------------------------------------------------------------------------------

--------------------------------------------------------------------------------
-2.5 0.4                              |   16.1484
12.1 7.3          		      |
--------------------------------------------------------------------------------

--------------------------------------------------------------------------------
2.5 -0.4                              |   16.4575
-12.2 7.0                             |
--------------------------------------------------------------------------------
*/
#include <stdio.h>
#include <math.h>

int main(){
    float x1,y1,x2,y2;
    scanf("%f %f", &x1, &y1);
    scanf("%f %f", &x2, &y2);
    printf( "%.4f\n", sqrt(pow(x2-x1, 2) + pow(y2-y1, 2)) );
    return 0;
}
