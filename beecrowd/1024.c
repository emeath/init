/*
https://judge.beecrowd.com/pt/problems/view/1024

beecrowd | 1024

# Criptografia

Por Neilor Tonin, URI  Brasil

Timelimit: 1

Solicitaram para que você construisse um programa simples de criptografia. Este programa deve possibilitar enviar mensagens codificadas sem que alguém consiga lê-las. O processo é muito simples. São feitas três passadas em todo o texto.

Na primeira passada, somente caracteres que sejam letras minúsculas e maiúsculas devem ser deslocadas 3 posições para a direita, segundo a tabela ASCII: letra 'a' deve virar letra 'd', letra 'y' deve virar caractere '|' e assim sucessivamente. Na segunda passada, a linha deverá ser invertida. Na terceira e última passada, todo e qualquer caractere a partir da metade em diante (truncada) devem ser deslocados uma posição para a esquerda na tabela ASCII. Neste caso, 'b' vira 'a' e 'a' vira '`'.

Por exemplo, se a entrada for “Texto #3”, o primeiro processamento sobre esta entrada deverá produzir “Wh{wr #3”. O resultado do segundo processamento inverte os caracteres e produz “3# rw{hW”. Por último, com o deslocamento dos caracteres da metade em diante, o resultado final deve ser “3# rvzgV”.

## Entrada

A entrada contém vários casos de teste. A primeira linha de cada caso de teste contém um inteiro N (1 ≤ N ≤ 1*104), indicando a quantidade de linhas que o problema deve tratar. As N linhas contém cada uma delas M (1 ≤ M ≤ 1*103) caracteres.

## Saída

Para cada entrada, deve-se apresentar a mensagem criptografada.

Exemplo entrada    |     Exemplo Saida 
---------------------------------------------
4                        3# rvzgV
Texto #3                 1FECedc
abcABC1                  ks. \n{frzx
vxpdylY .ph              gi.r{hyz-xx
vv.xwfxo.fd

*/

#include <stdio.h>

void primeiraEtapa(char *);
void segundaEtapa(char *);
void terceiraEtapa(char *);
int isLowerCaseChar(char);
int isUpperCaseChar(char);
size_t calcularTamanhoString(char *texto);

int main()
{
    // bee 1024
    char a = 'b';
    printf("%c %c %d %d\n", a, a+1, a, a+1);
//    char txt[42] = {'a', 'b', 'c', '\0'};
    char txt[64] = "Linkin Park";
    printf("%s\n", txt);
    primeiraEtapa(txt);
    printf("%s\n", txt);
    segundaEtapa(txt);
    printf("%s\n", txt);

    return 0;
}


void primeiraEtapa(char *texto)
{
    char auxChar;
    while(*texto != '\0') {
        auxChar = *texto;
        if (isLowerCaseChar(auxChar) || isUpperCaseChar(auxChar)) {
            // deslocar 3 a dir
            *texto = *texto + 3;
        }
        texto = texto + 1;
    }
}

int isLowerCaseChar(char ch) {
    // ascii -> a = 97 z = 122
    if (ch >= 97 && ch <= 122) return 1;
    else return 0;
}

int isUpperCaseChar(char ch) {
    // ascii -> A = 65 Z = 90
    if (ch >= 65 && ch <= 90) return 1;
    else return 0;
}


void segundaEtapa(char *texto)
{
    // inverter string
    char aux;
    // calcular tamanho da string
    size_t tamanhoString = calcularTamanhoString(texto);
    printf(">>>%ld\n", tamanhoString);
    size_t i;
    for(i=0; i < tamanhoString / 2; ++i) {
        aux = *(texto + tamanhoString - 1 - i);
        *(texto + tamanhoString - 1 - i) = *(texto + i);
        *(texto + i) = aux;
    }
    *(texto + tamanhoString) = '\0';    
}

void terceiraEtapa(char *) 
{
    // todo
}

size_t calcularTamanhoString(char *texto)
{
    size_t tamanho = 0;
    if ( '\0' == *texto) return 1;
    while(*texto != '\0') {
        ++tamanho;
        ++texto;
    }
    return tamanho;
}