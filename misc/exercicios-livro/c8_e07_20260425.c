#include <stdio.h>
#include "c8_e07_lib_20260425.h"

#define SIZE 5

int main()
{
    struct Tempo arrayTempo[SIZE];
    struct Tempo *pointerArrayTempo[SIZE];
    
    // check struct padding
    printf("size of struct: %lu\n", sizeof(struct Tempo)); // with padding = 12
    //without = 8 bytes

    size_t i = 0;
    size_t j = 0;

    while (i < SIZE)
    {
        getTempo( (arrayTempo + i) );
        ++i;
    }

    i = 0;
    while (i < SIZE)
    {
        printTempo( &arrayTempo[i++] );
    }
    // pre assigning the pointers
    i = 0;
    while (i < SIZE)
    {
        pointerArrayTempo[i] = &arrayTempo[i]; 
        i++;
    }
    


    // sorting
    for( i = 0 ; i < SIZE; ++i )
    {
        for ( j = 0 ; j < SIZE - i - 1; ++j )
        {
            if ( pointerArrayTempo[j]->totalInSeconds > pointerArrayTempo[j + 1]->totalInSeconds)
            {
                struct Tempo *bufferIndex = pointerArrayTempo[j + 1];
                pointerArrayTempo[j + 1] = pointerArrayTempo[j];
                pointerArrayTempo[j] = bufferIndex;
            }
        }
    }

    #ifdef DEBUG    
    i = 0; 
    while (i < SIZE)
    {
        printf("aqui...\n");
        printTempo( pointerArrayTempo[i++] );
    }
    #endif
    
    printf("\n\nBiggest Tempo is: %02u:%02u:%02u\n\n",
            pointerArrayTempo[SIZE - 1]->hour,
            pointerArrayTempo[SIZE - 1]->minutes,
            pointerArrayTempo[SIZE - 1]->seconds);
}

