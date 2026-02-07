/*
beecrowd | 1043
Triângulo
Adaptado por Neilor Tonin, URI  Brasil

Timelimit: 1
Leia 3 valores reais (A, B e C) e verifique se eles formam ou não um triângulo. Em caso positivo, calcule o perímetro do triângulo e apresente a mensagem:


Perimetro = XX.X


Em caso negativo, calcule a área do trapézio que tem A e B como base e C como altura, mostrando a mensagem


Area = XX.X

Entrada
A entrada contém três valores reais.

Saída
O resultado deve ser apresentado com uma casa decimal.

entrada
6.0 4.0 2.0
saida
Area = 10.0

e
6.0 4.0 2.1
s
Perimetro = 12.1

*/

#include <stdio.h>

int main() {

    float a,b,c;
    scanf("%f %f %f", &a, &b, &c);
    if(a+b>c && a+c>b && b+c>a) printf("Perimetro = %.1f\n", a+b+c);
    else printf("Area = %.1f\n", (a+b)*c/2.0);
    return 0;
}
