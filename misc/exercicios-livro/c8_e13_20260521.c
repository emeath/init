#include <stdio.h>
#include "c8_e13_lib_20260521.h"

int main()
{
    Mes mes = 0;
    printf("Input integer from 1 to 12: ");
    scanf("%d", &mes);
    switch (mes)
    {
    case 1:
        printf("Janeiro - 31 dias");
        break;
    case FEVEREIRO:
        printf("Fev - 28 dias\n");
        break;
    case MARCO:
        printf("Marco - 31 dias\n");
        break;
    case ABRIL:
        printf("Abril - 30 dias\n");
        break;
    case MAIO:
        printf("MAIO - 31 dias\n");
        break;
    case JUNHO:
        printf("junho - 30 dias\n");
        break;
    case JULHO:
        printf("julho - 31 dias\n");
        break;
    case AGOSTO:
        printf("Agosto - 31 dias\n");
        break;
    case SETEMBRO:
        printf("Setembro - 30 dias\n");
        break;
    case OUTUBRO:
        printf("OUTUBRO - 31 dias\n");
        break;
    case NOVEMBRO:
        printf("novembro - 30 dias\n");
        break;
    case DEZEMBRO:
        printf("dezembro - 31 dias\n");
        break;
    default:
        printf("invalid value\n");
    };
    return 0;
}