#include <stdio.h>

#define N 10

void copiarString(char *dest, char *src) {
    int i;
    for(i=0; src[i] != '\0'; ++i){
        dest[i] = src[i];
    }
    printf("i=%d\n", i);
    dest[i] = '\0';
}

int stringsSaoIguais(char *str1, char *str2) {
    int i = 0;
    while(str1[i] != '\0') {
        if(str1[i] != str2[i]) {
            return 0; // nao sao iguais
        }
        ++i;
    }
    return 1; // sao iguais
}

struct map {
    char palavra[64];
    int quantidade;
};


int main()
{
    char listaDePalavras[N][64] = \
        {"banana", "uva", "abacaxi", "maca", \
         "banana", "uva",            "maca", \
         "banana",                   "maca", \
         "banana"};

    int i;
    for (i = 0; i < N; ++i) {
        printf("%s\n", listaDePalavras[i]);
    }

    char setPalavras[N][64];
    int sizeSet=0;
    int j;
    copiarString(setPalavras[0], listaDePalavras[0]);
    ++sizeSet;
    int auxContador = 0;
    for(i=1;i<N;++i){
        auxContador = 0;
        for(j=0;j<sizeSet;++j){
            if(!stringsSaoIguais(listaDePalavras[i], setPalavras[j])) ++auxContador;
        }
        if (auxContador == sizeSet) // analisou todo o conjunto e todos os itens sao diferentes -> entao add
        {
            copiarString(setPalavras[sizeSet], listaDePalavras[i]);
            ++sizeSet;
        }
    }


    for(i = 0 ; i < N ; ++i) {
        printf("[%d] %s\n", i, setPalavras[i]);
    }

    printf("2222222222222222222\n");

    for(i = 0 ; i < sizeSet ; ++i) {
        printf("[%d] %s\n", i, setPalavras[i]);
    }

    struct map myMap[sizeSet];

    // init map
    for(i=0;i<sizeSet;++i){
        myMap[i].quantidade=0;
        copiarString(myMap[i].palavra, setPalavras[i]);
    }

    // contar quantidade
    for(i=0;i<sizeSet;++i){
        for(j=0;j<N;++j) {
            if(stringsSaoIguais(listaDePalavras[j], myMap[i].palavra)) myMap[i].quantidade++;
        }
    }

    for(i=0;i<sizeSet;++i) {
        printf("Struct -> [%d]\nPalavra: %s\nQuantidade: %d\n", i, myMap[i].palavra, myMap[i].quantidade);
    }

    return 0;

}