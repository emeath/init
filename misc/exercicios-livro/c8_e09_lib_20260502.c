#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "c8_e09_lib_20260502.h"

Atleta *evaluateHigher(Atleta *a, size_t len)
{
    size_t i;
    Atleta *higher = a;
    for (i = 0; i < len; ++i)
    {
        if (higher->altura < (a + i)->altura)
        {
            higher = (a + i);
#ifdef DEBUG
            printf("Resseting from  %p to %p\n",
                   higher,
                   (a + i));
#endif
        }
    }
    return higher;
}

Atleta *evaluateOldest(Atleta *a, size_t len)
{
    size_t j;
    Atleta *oldest = a;
    for (j = 1; j < len; ++j)
    {
        if (oldest->idade < (a + j)->idade)
        {
            oldest = (a + j);
#ifdef DEBUG
            printf("Resseting from %p to %p\n",
                   oldest,
                   (a + j))
#endif
        }
    }
    return oldest;
}

void getAtletasFromUserInput(Atleta *dest, size_t len)
{
    size_t i;
    char *nome = malloc(sizeof(dest->nome) * sizeof(char));
    if (!nome)
        return;
    char *esporte = malloc(
        sizeof(dest->esporte) * sizeof(char));
    if (!esporte)
        return;
    uint8_t idade, altura;
    for (i = 0; i < len; ++i)
    {
        printf("Nome? ");
        setString(nome, sizeof(dest->nome));
        setAtletaNome((dest + i), nome);

        printf("Esporte? ");
        setString(esporte, sizeof(dest->esporte));
        setAtletaEsporte((dest + i), esporte);

        printf("Idade? ");
        scanf("%hhu", &idade);
        setAtletaIdade((dest + i), idade);

        printf("Altura? ");
        scanf("%hhu", &altura);
        setAtletaAltura((dest + i), altura);

        clearBuffer();
    }
    free(nome);
    free(esporte);
}

void setAtletaNome(Atleta *dest, char *nome)
{
    // validation
    // will not be imp

    strcpy(dest->nome, nome);
}

void setAtletaEsporte(Atleta *dest, char *esporte)
{
    // validation
    // will not be imp

    strcpy(dest->esporte, esporte);
}

void setAtletaIdade(Atleta *dest, uint8_t idade)
{
    // validation
    // will not be imp

    dest->idade = idade;
}

void setAtletaAltura(Atleta *dest, uint8_t altura)
{
    // validation
    // will not be imp

    dest->altura = altura;
}

void clearBuffer(void)
{
    char c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

void setString(char *pointer, size_t maxLen)
{
    fgets(pointer, maxLen, stdin);
    if (pointer[strlen(pointer) - 1] == '\n')
    {
        pointer[strlen(pointer) - 1] = '\0';
    }
    else
    {
        clearBuffer();
    }
}

void printAtleta(const Atleta *a)
{
    printf("Atleta:\n--------------\n");
    printf("Nome: %s\n", a->nome);
    printf("Esporte: %s\n", a->esporte);
    printf("Idade: %hhu\n", a->idade);
    printf("Altura: %hhu\n\n", a->altura);
}