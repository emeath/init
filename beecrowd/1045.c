/*
https://judge.beecrowd.com/pt/problems/view/1045

beecrowd | 1045
Tipos de Triângulos
Adaptado por Neilor Tonin, URI  Brasil

Timelimit: 1
Leia 3 valores de ponto flutuante A, B e C e ordene-os em ordem decrescente, de modo que o lado A representa o maior dos 3 lados. A seguir, determine o tipo de triângulo que estes três lados formam, com base nos seguintes casos, sempre escrevendo uma mensagem adequada:

se A ≥ B+C, apresente a mensagem: NAO FORMA TRIANGULO
se A2 = B2 + C2, apresente a mensagem: TRIANGULO RETANGULO
se A2 > B2 + C2, apresente a mensagem: TRIANGULO OBTUSANGULO
se A2 < B2 + C2, apresente a mensagem: TRIANGULO ACUTANGULO
se os três lados forem iguais, apresente a mensagem: TRIANGULO EQUILATERO
se apenas dois dos lados forem iguais, apresente a mensagem: TRIANGULO ISOSCELES
Entrada
A entrada contem três valores de ponto flutuante de dupla precisão A (0 < A) , B (0 < B) e C (0 < C).

Saída
Imprima todas as classificações do triângulo especificado na entrada.


Exemplos de Entrada	        Exemplos de Saída
        
7.0 5.0 7.0		            TRIANGULO ACUTANGULO
			                TRIANGULO ISOSCELES
        
6.0 6.0 10.0		        TRIANGULO OBTUSANGULO
			                TRIANGULO ISOSCELES
        
6.0 6.0 6.0		            TRIANGULO ACUTANGULO
			                TRIANGULO EQUILATERO
        
5.0 7.0 2.0		            NAO FORMA TRIANGULO
        
6.0 8.0 10.0		        TRIANGULO RETANGULO
*/
#include <stdio.h>
#include <string.h>
#include <math.h>

void ordernarDecrescente(float *array, size_t lengthArray);
void analisarTipoTriangulo(float *array, char *resposta);

int main(){
    float a,b,c;
    float nArray[3];
    char resposta[256];
    resposta[0] = '\0';
    scanf("%f %f %f", &a, &b, &c);
    nArray[0]=a;
    nArray[1]=b;
    nArray[2]=c;
    ordernarDecrescente(nArray, 3);
    analisarTipoTriangulo(nArray, resposta);
    printf("%s", resposta);

    return 0;
}

void ordernarDecrescente(float *array, size_t lengthArray) {
    int i,j;
    float aux;
    for(i=0;i<lengthArray;++i) {
        for(j=0;j<lengthArray - i - 1; ++j) {
            if(array[j] < array[j+1]) {
                aux = array[j+1];
                array[j+1] = array[j];
                array[j] = aux;
            }
        }
    }
}

void analisarTipoTriangulo(float *array, char *resposta) {
    if(array[0] >= (array[1] + array[2])) {
        strcpy(resposta, "NAO FORMA TRIANGULO\n");   
        return;
    }
    float a2,b2,c2;
    a2 = pow(array[0],2);
    b2 = pow(array[1],2);
    c2 = pow(array[2],2);
    if(a2 == (b2+c2)) strcat(resposta, "TRIANGULO RETANGULO\n");
    if(a2 > (b2+c2))  strcat(resposta, "TRIANGULO OBTUSANGULO\n");
    if(a2 < (b2+c2))  strcat(resposta, "TRIANGULO ACUTANGULO\n");
    if(a2 == b2 && b2 == c2) strcat(resposta, "TRIANGULO EQUILATERO\n");
    if(a2 == b2 && b2 != c2 || a2 == c2 && c2 != b2 || b2 == c2 && c2 != a2)
        strcat(resposta, "TRIANGULO ISOSCELES\n");
}