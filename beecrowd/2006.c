#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Tea {
    int type;
    char name[32];
};

struct Competidor {
    int guess;
    int id;
    char name[32];
    int rightAnswer;
};

struct Competidor *init(int guess, int id, const char *pName) {
    struct Competidor *pointer = malloc(1 * sizeof(struct Competidor));
    if (!pointer) {
        fprintf(stderr, "Could not allocate memory for Competidor\n");
        return NULL;
    } 
    (*pointer).guess = guess;
    (*pointer).id = id;
    strcpy(pointer->name, pName);
    pointer->rightAnswer = -1;
    return pointer;
}

const char *formatedAns(struct Competidor *pComp) {
    if (pComp->rightAnswer < 0 || (*pComp).guess != 0) {
        return "Didn't guessed yet or Answer is not processed yet.";
    } else if ((*pComp).rightAnswer == 0) {
        return "Right answer!";
    } else {
        return "Wrong answer!";
    }
}

void printCompetidor(struct Competidor *p) {
    printf("---\n");
    printf("guess: %d\n", p->guess);
    printf("id: %d\n", (*p).id);
    printf("name: %s\n", p->name);
    printf("answer: %s\n", formatedAns(p));
    printf("---\n");
}

void setTea(struct Tea *pTea, int *pType) {
    pTea->type = *pType;
    if(*pType == 1) {
        strcpy((*pTea).name, "chá branco");
    } else if(*pType == 2) {
        strcpy(pTea->name, "chá verde");
    } else if(*pType == 3) {
        strcpy(pTea->name, "chá preto");
    } else if(*pType == 4) {
        strcpy(pTea->name, "chá de ervas");
    } else {
        strcpy(pTea->name, "????????");
    }
}

int main(){

    struct Competidor *um = init(1, 99, "Jairo Altair");
    struct Competidor *dois = init(2, 83, "Maria Gomes");
    struct Competidor *tres = init(3, 21, "Zarya Ruskh");

    printCompetidor(um);
    printCompetidor(dois);
    printCompetidor(tres);

    return 0;
}