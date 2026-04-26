#include <stdio.h>

enum mes
{
    janeiro = 1,
    fevereiro,
    marco,
    abril,
    maio,
    junho,
    julho,
    agosto,
    setembro,
    outubro,
    novembro,
    dezembro
};

void printInfoMes(enum mes m)
{
    switch (m)
    {
    case janeiro:
        printf("Janeiro - 31 dias\n");
        break;
    case fevereiro:
        printf("Fevereiro - 28/29 dias\n");
        break;
    case marco:
        printf("Marco - 31 dias\n");
        break;
    case abril:
        printf("Abril - 30 dias\n");
        break;
    case maio:
        printf("Maio - 31 dias\n");
        break;
    case junho:
        printf("Junho - 30 dias\n");
        break;
    case julho:
        printf("Julho - 31 dias\n");
        break;
    case agosto:
        printf("Agosto - 31 dias\n");
        break;
    case setembro:
        printf("Setembro - 30 dias\n");
        break;
    case outubro:
        printf("Outubro - 31 dias\n");
        break;
    case novembro:
        printf("Novembro - 30 dias\n");
        break;
    case dezembro:
        printf("Dezembro - 31 dias\n");
        break;
    }
}

int main()
{
    enum mes m = 5;
    printInfoMes(m);
    printInfoMes(janeiro);
    m = dezembro;
    printInfoMes(m);
}