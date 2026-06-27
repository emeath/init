#include <stdlib.h>
#include <stdio.h>
#include "c7_e12_20260328_lib.h"


double getPriceOnDiscount(const Product *produtc)
{
    return produtc->price - produtc->discount * produtc->price;
}

char* getString(void)
{
    size_t initialSize = 8; //bytes
    size_t newSize =0;
    size_t currentSize = 0;
    char ch;
    char *string = (char *) malloc ( initialSize * sizeof(char) );
    if(!string) return NULL;
    do
    {
        if ( currentSize > initialSize - 1 ) // considering \0 
        {
            newSize = newSize + initialSize * 2;
            char *tmp = realloc( string, newSize * sizeof(char) );
            if(!tmp) return NULL;
            string = tmp; // protect from memory leak
        }
    
        ch = getchar();
        *(string + currentSize) = ch;
        ++currentSize;
    } while ( ch != '\n');
    *(string + currentSize - 1) = '\0'; // not include \n on string
    return string;
}
