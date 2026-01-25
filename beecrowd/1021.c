/*
https://judge.beecrowd.com/pt/problems/view/1021

beecrowd | 1021
Notas e Moedas
Por Neilor Tonin, URI  Brasil

Timelimit: 1
Leia um valor de ponto flutuante com duas casas decimais. Este valor representa um valor monetário. A seguir, calcule o menor número de notas e moedas possíveis no qual o valor pode ser decomposto. As notas consideradas são de 100, 50, 20, 10, 5, 2. As moedas possíveis são de 1, 0.50, 0.25, 0.10, 0.05 e 0.01. A seguir mostre a relação de notas necessárias.

Entrada
O arquivo de entrada contém um valor de ponto flutuante N (0 ≤ N ≤ 1000000.00).

Saída
Imprima a quantidade mínima de notas e moedas necessárias para trocar o valor inicial, conforme exemplo fornecido.

Obs: Utilize ponto (.) para separar a parte decimal.

Exemplo de Entrada	
576.73

Exemplo de Saída
NOTAS:
5 nota(s) de R$ 100.00
1 nota(s) de R$ 50.00
1 nota(s) de R$ 20.00
0 nota(s) de R$ 10.00
1 nota(s) de R$ 5.00
0 nota(s) de R$ 2.00
MOEDAS:
1 moeda(s) de R$ 1.00
1 moeda(s) de R$ 0.50
0 moeda(s) de R$ 0.25
2 moeda(s) de R$ 0.10
0 moeda(s) de R$ 0.05
3 moeda(s) de R$ 0.01

Exemplo de Entrada
4.00

Exemplo de Saída
NOTAS:
0 nota(s) de R$ 100.00
0 nota(s) de R$ 50.00
0 nota(s) de R$ 20.00
0 nota(s) de R$ 10.00
0 nota(s) de R$ 5.00
2 nota(s) de R$ 2.00
MOEDAS:
0 moeda(s) de R$ 1.00
0 moeda(s) de R$ 0.50
0 moeda(s) de R$ 0.25
0 moeda(s) de R$ 0.10
0 moeda(s) de R$ 0.05
0 moeda(s) de R$ 0.01

Exemplo de Entrada
91.01

Exemplo de Saída
NOTAS:
0 nota(s) de R$ 100.00
1 nota(s) de R$ 50.00
2 nota(s) de R$ 20.00
0 nota(s) de R$ 10.00
0 nota(s) de R$ 5.00
0 nota(s) de R$ 2.00
MOEDAS:
1 moeda(s) de R$ 1.00
0 moeda(s) de R$ 0.50
0 moeda(s) de R$ 0.25
0 moeda(s) de R$ 0.10
0 moeda(s) de R$ 0.05
1 moeda(s) de R$ 0.01
*/
#include <stdio.h>
#include <string.h>
int main() {
	float valor;
	scanf("%f", &valor);
    /*
    int totalEmCentavos = valor * 100;

    int notas100 = totalEmCentavos / 10000;
    int restante = totalEmCentavos % 10000;
    
    int notas50 = restante / 5000;
    restante = restante % 5000;

    int notas20 = restante / 2000;
    restante = restante % 2000;

    int notas10 = restante / 1000;
    restante = restante % 1000;

    int notas5 = restante / 500;
    restante = restante % 500;

    int notas2 = restante / 200;
    restante = restante % 200;

    int moedas1 = restante / 100;
    restante = restante % 100;

    int moedas050 = restante / 50;
    restante = restante % 50;

    int moedas025 = restante / 25;
    restante = restante % 25;

    int moedas010 = restante / 10;
    restante = restante % 10;

    int moedas005 = restante / 5;
    restante = restante % 5;

    int moedas001 = restante;

    printf("NOTAS:\n");
    printf("%d nota(s) de R$ 100.00\n", notas100);
    printf("%d nota(s) de R$ 50.00\n",  notas50);
    printf("%d nota(s) de R$ 20.00\n",  notas20);
    printf("%d nota(s) de R$ 10.00\n",  notas10);
    printf("%d nota(s) de R$ 5.00\n",   notas5);
    printf("%d nota(s) de R$ 2.00\n",   notas2);
    printf("MOEDAS:\n");
    printf("%d moeda(s) de R$ 1.00\n", moedas1);
    printf("%d moeda(s) de R$ 0.50\n", moedas050);
    printf("%d moeda(s) de R$ 0.25\n", moedas025);
    printf("%d moeda(s) de R$ 0.10\n", moedas010);
    printf("%d moeda(s) de R$ 0.05\n", moedas005);
    printf("%d moeda(s) de R$ 0.01\n", moedas001);
    */
    
    int quantia[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
	int valores[12] = {10000, 5000, 2000 ,1000 ,500, 200, 100, 50, 25, 10, 5, 1};
    int restante=0, totalEmCentavos = valor * 100;
    char tipo[6];
	
    //1a iteracao
    restante = totalEmCentavos;
	for(int i = 0; i < 12; ++i )
	{
        quantia[i] = restante / valores[i];
        restante = restante % valores[i];
        if(0 == i)
            printf("NOTAS:\n");
        if(6 == i)
            printf("MOEDAS:\n");
        if(i < 6)
            strcpy(tipo, "nota");
        else
            strcpy(tipo, "moeda");
        printf("%d %s(s) de R$ %.2f\n", quantia[i], tipo, valores[i]/100.0);
    }
    
    return 0;
}
