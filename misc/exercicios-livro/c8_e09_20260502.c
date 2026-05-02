#include <stdio.h>
#include "c8_e09_lib_20260502.h"

int main()
{
    printf("size Atleta = %lu\n", sizeof(Atleta));
    Atleta atletas[SIZE];
    Atleta *highest, *oldest;
    getAtletasFromUserInput(atletas, SIZE);
    for (size_t g = 0; g < SIZE; ++g)
    {
        printAtleta(&atletas[g]);
    }

    highest = evaluateHigher(atletas, SIZE);
    printf("Highest atleta is: %s (%hhu cm)\n",
           highest->nome,
           highest->altura);
    oldest = evaluateOldest(atletas, SIZE);
    printf("Oldest atleta is: %s (%hhu years old)\n",
           oldest->nome,
           oldest->idade);
    return 0;
}

/*
mock
Foo F
Futebol
42
180
Carlos C
Voley
33
195
Maria M
Futebol
22
167
Fernanda Ab
Natacao
35
171
Carolina G
Judo
29
164
*/