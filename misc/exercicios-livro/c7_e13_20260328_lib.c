#include "c7_e13_20260328_lib.h"
#include <stdio.h>
#include <stdlib.h>

void printSubString(const char *string,
                    const size_t *initialIndex,
                    const size_t *endIndex)
{
    size_t i;
    printf("Sub string:\n");
    for(i = *initialIndex; i <= *endIndex; ++i)
    {
        printf("%c", *(string + i));
    }
    printf("\n");
}

void handleNotValidInput()
{
    perror("Input not valid!!");
    exit(1);
}

int isInputValid(const int *input1,
                 const int *input2,
                 const size_t *stringLength)
{
    if ( *input1 < 0 )
        return 0;
    if ( *input2 < 0 )
        return 0;
    if ( *input1 > *input2 )
        return 0;
    if ( *input2 > *stringLength - 1 ) // 0 index based oi -> strlen = 2... 0 | 1 |
        return 0;

    return 1;
}




char* getString(void)
{
    char *string;
    size_t initialSize = 16;
    size_t currentSize = 0;
    char ch;
    size_t stringSize = initialSize;
    string = allocateMemoryForString(initialSize);
    if ( !successFullyAllocatedMemory(string) )
        handleErrorWhenReallocating(); 
    do
    {
        if ( isNecessaryToReallocate(currentSize, stringSize) )
        {
            stringSize = currentSize + 2 * initialSize;
            char *tmp = realocateMemoryForString(string, stringSize); 
            if ( successFullyAllocatedMemory(tmp) ) 
            {
                string = tmp; 
            }
            else
            {
                handleErrorWhenReallocating();
            }
        }
  
        ch = getchar(); 
        *(string + currentSize) = ch;
        currentSize++;

    } while (ch != '\n');

    *(string + currentSize - 1) = '\0';
    printf("current = %ld\n", currentSize);
    printf("string size = %ld\n", stringSize);

    return string;
}

int isNecessaryToReallocate(size_t currentSize, size_t stringSize)
{
    if ( currentSize > stringSize - 1 ) // considering \0 character
        return 1;
    else
        return 0;
} 

int successFullyAllocatedMemory(char *pointer)
{
    if (pointer == NULL)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void handleErrorWhenReallocating()
{
    perror("Error reallocating memory. Exiting");
    exit(1);
}

char* realocateMemoryForString(char *origin, size_t howManyBytes)
{
    return (char *) realloc(origin, howManyBytes * sizeof(char));
}

char* allocateMemoryForString(size_t howManyBytes)
{
    return (char *) malloc( howManyBytes * sizeof(char) );
}
