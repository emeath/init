#include <stdio.h>
#include <stdlib.h>

struct Regua {
    int entradas;
    int entradasDisponiveis;
    int conectadaOutraRegua;
    int label;
};

struct Regua *initRegua(int numeroEntradas, int label) {
    struct Regua *pRegua = NULL;
    pRegua = malloc(sizeof(struct Regua));
    if (pRegua == NULL)
    {
        fprintf(stderr, "Error on allocating memory on *init()\n");
        return 1;
    }

    (*pRegua).conectadaOutraRegua = 0;
    (*pRegua).entradas = numeroEntradas;
    (*pRegua).entradasDisponiveis = (*pRegua).entradas;
    pRegua->label = label;
    return pRegua;
}

void connectReguas(struct Regua *pR1, struct Regua *pR2) {
    if (pR1->conectadaOutraRegua)
    {
        printf("Erro! Regua label %d ja conectada...\n", pR1->label);
        return;
    }
    if (pR2->conectadaOutraRegua)
    {
        printf("Erro! Regua label %d ja conectada...\n",pR2->label);
        return;
    }
    pR2->conectadaOutraRegua = 1;
    pR2->entradasDisponiveis--;   
    #ifdef DEBUG
        printf("Regua %d --> conectada em --> Regua %d\n", pR1->label, pR2->label); 
    #endif
} 

int main () {
    
    int nE1, nE2, nE3, nE4;
    int *pnE1, *pnE2, *pnE3, *pnE4;
    pnE1 = &nE1;
    pnE2 = &nE2;
    pnE3 = &nE3;
    pnE4 = &nE4;
    scanf("%d %d %d %d", pnE1, pnE2, pnE3, pnE4); 


    struct Regua *pR1 = initRegua(nE1, 1);
    struct Regua *pR2 = initRegua(nE2, 2);
    struct Regua *pR3 = initRegua(nE3, 3);
    struct Regua *pR4 = initRegua(nE4, 4);
   
    connectReguas(pR2, pR1);
    connectReguas(pR3, pR2);
    connectReguas(pR4, pR3);

    int tomadasDisponiveis = (*pR1).entradasDisponiveis +
                             (*pR2).entradasDisponiveis +
                             (*pR3).entradasDisponiveis +
                             (*pR4).entradasDisponiveis;
    
    printf("%d\n", tomadasDisponiveis);


    return 0;
}