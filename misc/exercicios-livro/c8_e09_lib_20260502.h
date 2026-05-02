#ifndef C8_E09_LIB_20260502
#define C8_E09_LIB_20260502
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

/*
disclaimer no user input validation will be done due to
time constraints
*/

#define SIZE 5

typedef struct
{
    uint8_t idade;
    uint8_t altura;
    char nome[100];
    char esporte[100];
} Atleta;

Atleta *evaluateHigher(Atleta *a, size_t len);
Atleta *evaluateOldest(Atleta *a, size_t len);
void getAtletasFromUserInput(Atleta *dest, size_t len);
void setAtletaNome(Atleta *dest, char *nome);
void setAtletaEsporte(Atleta *dest, char *esporte);
void setAtletaIdade(Atleta *dest, uint8_t idade);
void setAtletaAltura(Atleta *dest, uint8_t altura);
void clearBuffer(void);
void setString(char *pointer, size_t maxLen);
void printAtleta(const Atleta *a);

#endif