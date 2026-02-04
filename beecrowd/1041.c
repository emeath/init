/*
https://judge.beecrowd.com/pt/problems/view/1041

beecrowd | 1041
Coordenadas de um Ponto
Adaptado por Neilor Tonin, URI  Brasil

Timelimit: 1

Leia 2 valores com uma casa decimal (x e y), que devem representar as coordenadas de um ponto em um plano. A seguir, determine qual o quadrante ao qual pertence o ponto, ou se está sobre um dos eixos cartesianos ou na origem (x = y = 0).

              | Y        
              |         
  .Q2         |    .Q1    
              |         
              |               X
--------------+------------------
              |         
              |         
  .Q3         |     .Q4 
              |         
              |         

Se o ponto estiver na origem, escreva a mensagem “Origem”.

Se o ponto estiver sobre um dos eixos escreva “Eixo X” ou “Eixo Y”, conforme for a situação.

Entrada
A entrada contem as coordenadas de um ponto.

Saída
A saída deve apresentar o quadrante em que o ponto se encontra.


Exemplo de Entrada	                                Exemplo de Saída

4.5 -2.2                                            Q4

0.1 0.1                                             Q1

0.0 0.0                                             Origem

*/

#include <stdio.h>
#include <string.h>

int main() {
    float x,y;
    char ans[16];
    scanf("%f %f", &x, &y);
    if (0==x && 0==y) strcpy(ans, "Origem");
    else if (0==x) strcpy(ans, "Eixo Y");
    else if (0==y) strcpy(ans, "Eixo X");
    else if(x>0) {
        if (y>0) strcpy(ans, "Q1");
        else strcpy(ans, "Q4"); 
    } else {
        if (y>0) strcpy(ans, "Q2");
        else strcpy(ans, "Q3");
    }
    printf("%s\n", ans);

    return 0;
}