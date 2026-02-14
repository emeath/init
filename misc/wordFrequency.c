#include <stdio.h>

#define N 10

void copiarString(char *dest, char *src) {
    int i;

    for(i=0; src[i] != '\0'; ++i){
        dest[i] = src[i];
    }
    #ifdef DEBUG
    printf("i=%d\n", i);
    #endif
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

    #ifdef DEBUG
    for (i = 0; i < N; ++i) {
        printf("%s\n", listaDePalavras[i]);
    }
    #endif

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


    #ifdef DEBUG
    for(i = 0 ; i < N ; ++i) {
        printf("[%d] %s\n", i, setPalavras[i]);
    }

    for(i = 0 ; i < sizeSet ; ++i) {
        printf("[%d] %s\n", i, setPalavras[i]);
    }
    #endif

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

    #ifdef DEBUG
    for(i=0;i<sizeSet;++i) {
        printf("Struct -> [%d]\nPalavra: %s\nQuantidade: %d\n", i, myMap[i].palavra, myMap[i].quantidade);
    }
    #endif


    // ordernar o mapa
    struct map mapAux;
    mapAux.quantidade = 0;

    for(i=0;i<sizeSet;++i){
        for(j=0;j<sizeSet - i - 1; ++j) {
            if(myMap[j].quantidade < myMap[j+1].quantidade) {
                // fazer o swap
                //copiarString(mapAux.palavra, myMap[j+1].palavra);
                //mapAux.quantidade = myMap[j+1].quantidade;
                
                mapAux = myMap[j+1];
                myMap[j+1] = myMap[j];
                myMap[j] = mapAux;
                
            }
        }
    }

    #ifdef DEBUG
    for(i=0;i<sizeSet;++i) {
        printf("Struct -> [%d]\nPalavra: %s\nQuantidade: %d\n", i, myMap[i].palavra, myMap[i].quantidade);
    }
    #endif

    printf("3 Most Frequent:\n");
    for(i=0;i<3;++i){
        printf("Word: %s \t Frequency: %d\n", myMap[i].palavra, myMap[i].quantidade);
    }

    return 0;

}