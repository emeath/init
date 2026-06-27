#include <stdio.h>
#include "c8_e07_lib_20260425.h"

void getTempo(struct Tempo *tempo)
{
    tempo->hasValidData = 0;
    
    uint8_t buffer;

    printf("Hour (0 - 23)? ");
    scanf("%hhu", &buffer);
    if(buffer > 23)
    {
        fprintf(stderr, "Bad Input!\n");
        cleanInputBuffer();
        return;
    }
    // assuring that will only set values if
    // they are valid
    tempo->hour = buffer;


    printf("Minutes (0 - 59)? ");
    scanf("%hhu", &buffer);
    if(buffer > 59)
    {
        fprintf(stderr, "Bad Input!\n");
        cleanInputBuffer();
        return;
    }
    tempo->minutes = buffer;

    printf("Seconds (0 - 59)? ");
    scanf("%hhu", &buffer);
    if(buffer > 59)
    {
        fprintf(stderr, "Bad Input!\n");
        cleanInputBuffer();
        return;
    }
    tempo->seconds = buffer;

    tempo->totalInSeconds =
        tempo->hour * 3600
        + tempo->minutes * 60
        + tempo->seconds;

    tempo->hasValidData = 1;
}

void cleanInputBuffer(void)
{
    char c;
    while( (c = getchar()) != '\n' && c != EOF );
}

void printTempo(const struct Tempo *tempo)
{
    printf("Tempo:\n");
    if (tempo->hasValidData != 1)
        printf("ATTENTION! STRUCT HASN'T VALID DATA!\n");
    printf("Hour Minutes Seconds: "); 
    printf("%02u:%02u:%02u\n", tempo->hour, tempo->minutes, tempo->seconds);
    printf("Total in seconds: %u\n\n", tempo->totalInSeconds);
}
