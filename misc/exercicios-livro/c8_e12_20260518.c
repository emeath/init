#include <stdio.h>
#include <string.h>
#include "c8_e12_lib_20260518.h"

int main()
{
    DiaSemana dia = SEGUNDA;
    printf("Digite um num. correspondente oa dia da semana:\n");
    printf("1 - DOMINGO\n");
    printf("3 - SEGUNDA\n");
    printf("5 - TERCA\n");
    printf("7 - QUARTA\n");
    printf("9 - QUINTA\n");
    printf("11 - SEXTA\n");
    printf("13 - SABADO\n\n");

    int input = 0;
    char c;
    do
    {
        input = scanf("%d", &dia);
        // clear input buffer
        while (c = getchar() != '\n' && c != EOF)
            ;
    } while (input != 1);

    char resposta[50] = "vc digitou: ";

    switch (dia)
    {
    case DOMINGO:
        strcat(resposta, " DOMINGO!\n");
        break;
    case SEGUNDA:
        strcat(resposta, " SEGUNDA\n");
        break;
    case 5:
        strcat(resposta, "TERCa\n");
        break;
    case QUARTA:
        strcat(resposta, "QUARTA\n");
        break;
    case QUINTA:
        strcat(resposta, "QUINTA\n");
        break;
    case SEXTA:
        strcat(resposta, "SEXTA\n");
        break;
    case SABADO:
        strcat(resposta, "SABADO\n");
        break;
    default:
        printf("Error!\n");
        return 1;
    };

    printf("%s\n", resposta);
}