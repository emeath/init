#include <stdio.h>
#include "c8_e09_lib_20260502.h"
#include "c8_e10_lib_20260502.h"

/*
    uses implementation of c8_e09
*/

void evaluateOldestToYoungets(Atleta *a,
                              size_t len,
                              Atleta *dest)
{
    size_t i, j;
    for (i = 0; i < len; ++i)
    {
        for (j = 0; j < len - i - 1; ++j)
        {
            if ((a + j)->idade < (a + j + 1)->idade)
            {
                *(dest + j) = *(a + j + 1);
                *(dest + j + 1) = *(a + j);
            }
        }
    }
}

void pointersEvaluateOldestToYoungets(
    Atleta *a,
    size_t lenArray,
    Atleta **arrayOfPointers)
{
    size_t i, j;
    // init dest arrayOfPointers
    for (i = 0; i < lenArray; ++i)
    {
        *(arrayOfPointers + i) = (a + i);
    }

    for (i = 0; i < lenArray; ++i)
    {
        for (j = 0; j < lenArray - i - 1; ++j)
        {
            // the if statement below was a mistake from my side
            // the check must be done on a "changing"/"mutable"
            // array, not a fixed one, because the swapping
            // will not be reflected.. and a eerie bug will
            // happen
            /*
            if ((a + j)->idade < (a + j + 1)->idade)
            {
                // swap
                *(arrayOfPointers + j) = (a + j + 1);
                *(arrayOfPointers + j + 1) = (a + j);
            }
            */

            // fixed
            if ((*(arrayOfPointers + j))->idade <
                (*(arrayOfPointers + j + 1))->idade)
            {
                // swap
                /* wrong again... do not use addresses
                of a fixed array, the sorting
                algorithm must use the array that
                is beeing sorted itself */
                //*(arrayOfPointers + j) = a + j + 1;
                //*(arrayOfPointers + j + 1) = a + j;

                Atleta *temp = *(arrayOfPointers + j);
                *(arrayOfPointers + j) = *(arrayOfPointers + j + 1);
                *(arrayOfPointers + j + 1) = temp;
            }
        }
    }
}

void printArrayOfPointers(const Atleta **pA, size_t len)
{
    size_t i;
    printf("Address pointer to pointer: %p\n", &pA);
    for (i = 0; i < len; ++i)
    {
        printf("[%p][  %p  ]--->[%p][  %d  ]\n",
               (pA + i),
               *(pA + i),
               *(pA + i),
               (**(pA + i)).idade);
    }
}
