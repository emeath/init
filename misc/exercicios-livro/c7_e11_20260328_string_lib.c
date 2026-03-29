#include <stdio.h>
#include <stdlib.h>
#include "c7_e11_20260328_string_lib.h"

char* getString() 
{
    size_t initialSize = 8;
    size_t currentSize = 0;
    char character;
    char *string;

    string = (char *) malloc ( initialSize * sizeof(char) );

    if( string == NULL ) {
        perror("Error allocating string.");
        return NULL;
    }

    do {
        character = getchar();
        logReadedCharacter(&character);
        *(string + currentSize) = character;
        currentSize++;
        // overflow initial size, need to expand
        if(currentSize > initialSize) {
            initialSize = initialSize * 2;
            char *tmp;
            tmp = (char *) realloc ( string, initialSize * sizeof(char) );
            // handle error
            if (tmp == NULL) {
                perror("Error reallocating memory!");
                return NULL;
            }
            // it;s necessary to assign the realloc memory address
            // first to a tmp because if it fails to reallocate
            // and we assign directly to string we would lost
            // the previous address that string pointed
            // resulting in a memory address not reachble to dealocate
            // resource -> memory leak
            string = tmp;
        }
    } while (character != '\n'); 
    // sucessfully termitaing the string
    *(string + currentSize - 1) = '\0'; 

    // after logging all characters, close the file
    initFile(1);


    return string;
}

void logReadedCharacter(char *ch)
{
    // i want to avoid open and close for each character readed
    FILE *g = initFile(0);
    fprintf(g, "| %c |", *ch);
}

FILE* initFile(int close)
{
    // my idea is create a singleton here
    // not sure if its correct
    static FILE *f;

    #ifdef DEBUG
    printf("f is pointing to: %p\n", f);
    #endif

	if(1 == close)
	{
		if(f == NULL) 
		{
    		perror("Error trying to close null file");
    		return NULL;
   		}
		fclose(f);
		f = NULL;
	}

    // scenario where f was not initialized
    // we will try to initialize
    // and handle possible error
    if (f == NULL) {
        f = fopen("/tmp/logChars", "a+");
        if (f == NULL) {
            perror("Error opening file!");
            return NULL;
        }
    }
    // here either the itiliaziation was sucessfully
    // or f was already initialized
    return f;
}

char* convertStringToLowerCase(char *string)
{
    if (string == NULL)
    {
        perror("Invalid string.");
        return NULL;
    }

    size_t counter = 0;
    char currentChar = *(string + counter);
    while ( currentChar != '\0' )
    {
        currentChar = *(string + counter);
        if ( currentChar >= 65 && currentChar <= 90)
            currentChar = currentChar + 32;
        *(string + counter) = currentChar;
        ++counter;
    }
    return string; // allow chain invoking
}
