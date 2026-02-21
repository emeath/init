/*
https://judge.beecrowd.com/pt/problems/view/1046

beecrowd | 1046
Tempo de Jogo
Adaptado por Neilor Tonin, URI  Brasil

Timelimit: 1
Leia a hora inicial e a hora final de um jogo. A seguir calcule a duração do jogo, sabendo que o mesmo pode começar em um dia e terminar em outro, tendo uma duração mínima de 1 hora e máxima de 24 horas.

Entrada
A entrada contém dois valores inteiros representando a hora de início e a hora de fim do jogo.

Saída
Apresente a duração do jogo conforme exemplo abaixo.

Exemplo de Entrada	Exemplo de Saída
16 2			O JOGO DUROU 10 HORA(S)

0 0			O JOGO DUROU 24 HORA(S)

2 16			O JOGO DUROU 14 HORA(S)
*/

#include <stdio.h>

enum formatacao {
    nova_linha='\n',
    tab='\t'
};

typedef enum formatacao frmt;

int calculaDuracao(int, int);

int main() {
    char resposta[64];
    resposta[0]='\0';
    int inicio, fim;
    scanf("%d %d", &inicio, &fim);
    frmt format = nova_linha;
    snprintf(resposta, sizeof(resposta), "O JOGO DUROU %d HORA(S)%c", calculaDuracao(inicio, fim), format);
    printf("%s", resposta);
    return 0;
}

int calculaDuracao(int inicio, int fim) {
    int duracao = 0;    
    if( fim <= inicio ) fim = fim + 24;
    duracao = fim - inicio;
    return duracao;
}
