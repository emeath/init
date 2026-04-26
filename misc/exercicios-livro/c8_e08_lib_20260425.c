#include "c8_e08_lib_20260425.h"
#include <stdio.h>

void calculateTotalInDays(Date *date)
{
    date->totalInDays = date->year * 365 +
                        date->month * 30 +
                        date->day;
}

void clearBuffer(void)
{
    char c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

int setDate(unsigned int d,
            unsigned int m,
            unsigned int y,
            Date *date)
{
    int returnCode = 0;
    if (d == 0 || d > 31)
        returnCode = -1;
    if (m == 0 || m > 12)
        returnCode = -1;
    if (y == 0)
        returnCode = -1;

    if (-1 == returnCode)
        return returnCode;

    date->year = y;
    date->month = m;
    date->day = d;

    calculateTotalInDays(date);

    return returnCode;
}

void printPessoa(const Pessoa *p)
{
    printf("Pessoa:\n");
    printf("nome: %s\n", p->nome);
    printf("Birthdate (dd/mm/yyyy): %02u/%02u/%04u\n",
           p->date.day,
           p->date.month,
           p->date.year);
    printf("Total in days: %u\n\n", p->date.totalInDays);
}

Pessoa *evaluateOldest(Pessoa *pArray, size_t lenArray)
{
    // oldest is who has less days
    size_t i = 0;
    unsigned int totalInDaysCurrent, totalInDaysNext;
    totalInDaysCurrent = (pArray + 0)->date.totalInDays;
    Pessoa *oldest = (pArray + 0);
    for (i = 0; i < lenArray - 1; ++i)
    {
        totalInDaysCurrent = oldest->date.totalInDays;
        totalInDaysNext = (pArray + i + 1)->date.totalInDays;
        if (totalInDaysCurrent > totalInDaysNext)
        {
            oldest = (pArray + i + 1);
        }
    }
    return oldest;
}