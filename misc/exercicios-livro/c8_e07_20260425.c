#include <stdio.h>
#include <stdint.h>

struct Tempo
{
    uint8_t hour;
    uint8_t minutes;
    uint8_t seconds;
    unsigned int totalInSeconds;
    uint8_t hasValidData;
};


void getTempo(struct Tempo *tempo);

void cleanInputBuffer(void);

void printTempo(const struct Tempo *tempo);

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
    printf("Hour: %u\n", tempo->hour);
    printf("Minutes: %u\n", tempo->minutes);
    printf("Seconds: %u\n", tempo->seconds);
    printf("Total in seconds: %u\n", tempo->totalInSeconds);
    printf("\n\n");
}

int main()
{
    struct Tempo arrayTempo[5];
    struct Tempo *pointerArrayTempo[5];
    
    // check struct padding
    printf("size of struct: %u\n", sizeof(struct Tempo)); // with padding = 12

    size_t i = 0;
    size_t j = 0;

    while (i < 5)
    {
        getTempo( (arrayTempo + i) );
        ++i;
    }

    i = 0;
    while (i < 5)
    {
        printTempo( &arrayTempo[i++] );
    }
    // pre assigning the pointers
    i = 0;
    while (i < 5)
    {
        pointerArrayTempo[i] = &arrayTempo[i]; 
        i++;
    }
    


    // sorting
    for( i = 0 ; i < 5; ++i )
    {
        for ( j = 0 ; j < 5 - i - 1; ++j )
        {
            if ( pointerArrayTempo[j]->totalInSeconds > pointerArrayTempo[j + 1]->totalInSeconds)
            {
                struct Tempo *bufferIndex = pointerArrayTempo[j + 1];
                pointerArrayTempo[j + 1] = pointerArrayTempo[j];
                pointerArrayTempo[j] = bufferIndex;
            }
        }
    }
    i = 0; 
    while (i < 5)
    {
        printf("aqui...\n");
        printTempo( pointerArrayTempo[i++] );
    }
}

