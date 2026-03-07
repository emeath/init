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

A entrada contém vários casos de teste. A primeira linha de cada caso de teste contém um inteiro N (1 ≤ N ≤ 1*10^4), indicando a quantidade de linhas que o problema deve tratar. As N linhas contém cada uma delas M (1 ≤ M ≤ 1*10^3) caracteres.

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
#include <stdlib.h>
#include <math.h> 

void primeiraEtapa(char *);
void segundaEtapa(char *);
void terceiraEtapa(char *);
int isLowerCaseChar(char);
int isUpperCaseChar(char);
size_t calcularTamanhoString(char *texto);
void copiaString(char *, char *);
void clearBuffer(void);
void replaceNewLine(char *);

int main()
{
    setbuf(stdout, NULL);
    // char x = ' ';
    // x++;
    // printf(".%d.\n", x);
    // return 0;

    // bee 1024
    // char a = 'b';
    // printf("%c %c %d %d\n", a, a+1, a, a+1);
//    char txt[42] = {'a', 'b', 'c', '\0'};
    // char txt[64] = "Linkin Park";
    // copiaString(txt, "Texto #3");
    size_t N,i;
    char word[103 + 1];
    scanf("%ld", &N);
    clearBuffer();
    
    
    char **lista = (char **) malloc(N * sizeof(char *));
    if (lista == NULL) {
        printf("Not enought memory available on heap!1\n");
        exit(1);
    }

    #ifdef DEBUG
    printf("**lista\n");
    printf("&lista:  %p\n", &lista);
    printf("lista:   %p\n", lista);
    // printf("*lista:  %p\n", *lista);
    // printf("**lista: %c\n\n", **lista);
    printf("\n\n");
    #endif

    for(i=0;i<N;++i) {
        char *palavra = (char *) malloc( (pow(10,3) + 1) * sizeof(char) );
        *(lista + i) = palavra;
        #ifdef DEBUG
        printf("*palavra\n");
        printf("&palavra: %p\n", &palavra);
        printf("palavra:  %p\n", palavra);
        printf("*palavra: %c\n", *palavra);
        for(size_t x=0;x<104;++x) {
            printf("%c ", palavra[x]);
        }
        printf("\n");
        #endif
    }
    
    #ifdef DEBUG
    printf("*array lista:\n");
    for(i=0;i<N;++i) {
        printf("%p    %p\n", (lista + i), *(lista + i) );
    }
    printf("\n");
    #endif

    // get all inputs
    char *getsReturn;
    for(i=0; i<N; ++i) {
        getsReturn = fgets(*(lista + i), (pow(10,3) + 1), stdin);
        replaceNewLine(*(lista + i));
        if(getsReturn == NULL) {
            return -1;
        }
    }

    #ifdef DEBUG
    for(i=0; i<N; ++i) {
        printf("%ld) %s\n", i, *(lista + i));
    }
    #endif

    // process three steps and output one by one not in batch:
    for(i=0;i<N;++i)
    {
        char *toProcess = *(lista + i);
        primeiraEtapa(toProcess);
        segundaEtapa(toProcess);
        terceiraEtapa(toProcess);
        printf("%s\n", *(lista +i));
    }

    // desalocar memoria
    for(i=0;i<N;++i) {
        free(*(lista+i));
    }
    free(lista);

    // for (size_t i = 0; i < N; i++)
    // {
    //     printf("%ld) %s\n", i, listaP[i]);
    // }

    // free(lista);
    

    //     printf(">>>%s<<<\n",word);
    //     primeiraEtapa(word);
    //     segundaEtapa(word);
    //     terceiraEtapa(word);
    //     printf("%s\n", word);
    // }
    // printf("%s\n", txt);
    // primeiraEtapa(txt);
    // printf("%s\n", txt);
    // segundaEtapa(txt);
    // printf("%s\n", txt);
    // terceiraEtapa(txt);
    // printf("%s\n",txt);
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
    // printf(">>>%ld\n", tamanhoString);
    size_t i;
    for(i=0; i < tamanhoString / 2; ++i) {
        aux = *(texto + tamanhoString - 1 - i);
        *(texto + tamanhoString - 1 - i) = *(texto + i);
        *(texto + i) = aux;
    }
    *(texto + tamanhoString) = '\0';    
}

void terceiraEtapa(char *texto) 
{
    size_t tamanhoTexto = calcularTamanhoString(texto);
    // printf("%ld....\n",tamanhoTexto);
    size_t metadeTexto = tamanhoTexto / 2;
    // printf("%ld .........\n",metadeTexto);
    size_t i;
    for(i=metadeTexto; i<tamanhoTexto; ++i)
        *(texto+i) = *(texto+i) - 1;
}

size_t calcularTamanhoString(char *texto)
{
    size_t tamanho = 0;
    while(*texto != '\0') {
        ++tamanho;
        ++texto;
    }
    return tamanho;
}

void copiaString(char *dest, char *org)
{
    size_t lengthDest = calcularTamanhoString(dest);
    size_t o;
    for(o=0;o<lengthDest;++o)
    {
        *(dest + o) = *(org + o);
    }
    *(dest + o) = '\0'; // ensure ends with null terminator
}

void clearBuffer(void) {
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

void replaceNewLine(char *string)
{
    size_t i = 0;
    while(*(string + i) != '\n') ++i;
    *(string + i) = '\0';
}