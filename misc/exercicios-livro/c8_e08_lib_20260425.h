#ifndef C8_E08_LIB_20260425
#define C8_E08_LIB_20260425

#include <stdio.h>

typedef struct
{
    unsigned int day;
    unsigned int month;
    unsigned int year;
    unsigned int totalInDays;
} Date;

typedef struct
{
    char nome[256];
    Date date;

} Pessoa;

void calculateTotalInDays(Date *);

void clearBuffer(void);

int setDate(unsigned int,
            unsigned int,
            unsigned int,
            Date *);

void printPessoa(const Pessoa *);

Pessoa *evaluateOldest(Pessoa *, size_t);

#endif