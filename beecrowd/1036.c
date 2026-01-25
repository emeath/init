/*
https://judge.beecrowd.com/pt/problems/view/1036

beecrowd | 1036
Fórmula de Bhaskara
Adaptado por Neilor Tonin, URI  Brasil

Timelimit: 1
Leia 3 valores de ponto flutuante e efetue o cálculo das raízes da equação de Bhaskara. Se não for possível calcular as raízes, mostre a mensagem correspondente “Impossivel calcular”, caso haja uma divisão por 0 ou raiz de numero negativo.

Entrada
Leia três valores de ponto flutuante (double) A, B e C.

Saída
Se não houver possibilidade de calcular as raízes, apresente a mensagem "Impossivel calcular". Caso contrário, imprima o resultado das raízes com 5 dígitos após o ponto, com uma mensagem correspondente conforme exemplo abaixo. Imprima sempre o final de linha após cada mensagem.

Exemplos de Entrada	Exemplos de Saída
10.0 20.1 5.1		R1 = -0.29788
			R2 = -1.71212


0.0 20.0 5.0		Impossivel calcular


10.3 203.0 5.0		R1 = -0.02466
			R2 = -19.68408


10.0 3.0 5.0		Impossivel calcular
*/
#include <stdio.h>
#include <math.h>
int main(){
	double A,B,C;
	scanf("%lf %lf %lf", &A, &B, &C);

	if(0 == A) {
		printf("Impossivel calcular\n");
		return 0;
	}

	double delta = B * B - 4 * A * C;

	if(delta < 0) {
		printf("Impossivel calcular\n");
		return 0;
	}
	
	double r1,r2;
	r1 = - B + sqrt(delta);
	r1 = r1 / (2.0 * A);
	
	r2 = - B - sqrt(delta);
	r2 = r2 / (2.0 * A);
	
	printf("R1 = %.5lf\nR2 = %.5lf\n", r1,r2);
	

return 0;
}
