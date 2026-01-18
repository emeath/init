/*
https://judge.beecrowd.com/pt/problems/view/1019

beecrowd | 1019
Conversão de Tempo
Adaptado por Neilor Tonin, URI  Brasil

Timelimit: 1
Leia um valor inteiro, que é o tempo de duração em segundos de um determinado evento em uma fábrica, e informe-o expresso no formato horas:minutos:segundos.

Entrada
O arquivo de entrada contém um valor inteiro N.

Saída
Imprima o tempo lido no arquivo de entrada (segundos), convertido para horas:minutos:segundos, conforme exemplo fornecido.

Exemplo de Entrada	
556

Exemplo de Saída
0:9:16

Exemplo de Entrada
1

Exemplo de Saída
0:0:1

Exemplo de Entrada
140153

Exemplo de Saída
38:55:53

*/
#include <stdio.h>
int main() {
	int N;
	scanf("%d",&N);
	int horas, minutos, segundos;
	horas = N / 3600;
	minutos = (N - horas * 3600) / 60;
	segundos = (N - horas * 3600 - minutos * 60);
	printf("%d:%d:%d\n", horas,minutos,segundos);
	return 0;
}
