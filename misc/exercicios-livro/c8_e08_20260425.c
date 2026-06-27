#include <stdio.h>
#include <string.h>
#include "c8_e08_lib_20260425.h"
#define SIZE 6

int main()
{
    printf("size Pessoa = %lu\n", sizeof(Pessoa));

    size_t i;
    Pessoa pessoas[SIZE];

    char *pNome;
    unsigned int n;
    unsigned int day, month, year;
    Date d;

    for (i = 0; i < SIZE; ++i)
    {
        printf("%lu) Person name: ", i);
        pNome = pessoas[i].nome;
        fgets(pNome, sizeof(pessoas[i].nome), stdin);
        // check if user overflow the buffer in this case clear
        // the buffer
        if (pNome[strlen(pNome) - 1] == '\n')
        {
            pNome[strlen(pNome) - 1] = '\0';
        }
        else
        {
            // user put alot of date on buffer, clean it
            clearBuffer();
        }
        do // validate that 3 numbers will be inserted
        {

            printf("Enter birth date: (day/month/year): ");
            n = scanf("%u %u %u", &day, &month, &year);
            clearBuffer();

            if (0 != setDate(day, month, year, &d))
            {
                // not valid date, try to set again
                n = 0;
                continue;
            }
        } while (n != 3);
        pessoas[i].date = d;
    }

    for (i = 0; i < SIZE; ++i)
    {
        printPessoa(&pessoas[i]);
    }

    printf("Oldest person is:\n");
    printPessoa(evaluateOldest(pessoas, SIZE));

    return 0;
}