/*
https://judge.beecrowd.com/pt/problems/view/1020

beecrowd | 1020
Idade em Dias
Adaptado por Neilor Tonin, URI  Brasil

Timelimit: 1
Leia um valor inteiro correspondente à idade de uma pessoa em dias e informe-a em anos, meses e dias

Obs.: apenas para facilitar o cálculo, considere todo ano com 365 dias e todo mês com 30 dias. Nos casos de teste nunca haverá uma situação que permite 12 meses e alguns dias, como 360, 363 ou 364. Este é apenas um exercício com objetivo de testar raciocínio matemático simples.

Entrada
O arquivo de entrada contém um valor inteiro.

Saída
Imprima a saída conforme exemplo fornecido.

Exemplo de Entrada	
400

1 ano(s)
1 mes(es)
5 dia(s)

Exemplo de Entrada
800

Exemplo de Saída
2 ano(s)
2 mes(es)
10 dia(s)

Exemplo de Entrada
30

Exemplo de Saída
0 ano(s)
1 mes(es)
0 dia(s)
*/
#include <stdio.h>
int main()
{
	int idadeDias;
	scanf("%d", &idadeDias);
	int anos, meses, dias;
	anos = idadeDias / 365;
	meses = (idadeDias - anos * 365 ) / 30;
	dias = (idadeDias - anos * 365 - meses * 30);
	printf("%d ano(s)\n", anos);
	printf("%d mes(es)\n", meses);
	printf("%d dia(s)\n", dias);
	return 0;
}
