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
};

struct Competidor *init(int guess, int id, char name[32]) {
    struct Competidor *pointer = malloc(1 * sizeof(struct Competidor));
    if (!pointer) {
        fprintf(stderr, "Could not allocate memory for Competidor\n");
        return 1;
    } 
    (*pointer).guess = guess;
    (*pointer).id = id;
    strcpy(pointer->name, name);
    return pointer;
}

void printCompetidor(struct Competidor *p) {
    printf("---\n");
    printf("guess: %d\n", p->guess);
    printf("id: %d\n", (*p).id);
    printf("name: %s\n", p->name);
    printf("---\n");
}

int main(){

    struct Competidor *um = init(1, 99, "abcnome sobrenome");

    printCompetidor(um);

    return 0;
}