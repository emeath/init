#include <stdio.h>
#include "c8_e14_lib_20260521.h"

int main()
{
    enum ListaDeCompras lista;
    int item = -1;

    printf("Input a integer: ");
    scanf("%d", &item);

    lista = (enum ListaDeCompras)item;

    switch (lista)
    {
    case LEITE:
        printf("%d) Leite - R$10,00", LEITE);
        break;
    case GRANOLA:
        printf("%d) Granola - R$ 5,00", GRANOLA);
        break;
    case MACA:
        printf("%d) Maca - R$ 3,00", MACA);
        break;
    case UVA:
        printf("%d) Uva - R$11,00", UVA);
        break;
    case FEIJAO:
        printf("%d) Feijao - R$30,40", FEIJAO);
        break;
    case ARROZ:
        printf("%d) Arroz - R$21,00", ARROZ);
        break;
    case QUEIJO:
        printf("%d) Queijo - R$ 12,00", QUEIJO);
        break;
    case FRANGO:
        printf("%d) - Frango R$40,00", FRANGO);
        break;
    case CHOCOLATE:
        printf("%d) Chocolate - R$ 25,00", CHOCOLATE);
        break;
    default:
        printf("Invalid value!");
    };

    printf("\n");

    return 0;
}