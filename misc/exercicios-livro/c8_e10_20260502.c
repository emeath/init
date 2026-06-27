#include <stdio.h>
#include "c8_e09_lib_20260502.h"
#include "c8_e10_lib_20260502.h"

/*
    uses implementation of c8_e09
*/

int main()
{
    printf("size Atleta = %lu\n", sizeof(Atleta));
    Atleta atletas[SIZE];
    Atleta *pointersAtletas[SIZE];
    getAtletasFromUserInput(atletas, SIZE);
    for (size_t g = 0; g < SIZE; ++g)
    {
        printAtleta(&atletas[g]);
    }

    pointersEvaluateOldestToYoungets(atletas,
                                     SIZE,
                                     pointersAtletas);

    printArrayOfPointers((const Atleta **)pointersAtletas, SIZE);

    return 0;
}

/*
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