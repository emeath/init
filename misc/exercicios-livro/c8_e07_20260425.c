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

    printf("Hour (0 - 23)? ");
    scanf("%u", &tempo->hour);
    if(tempo->hour > 23)
    {
        fprintf(stderr, "Bad Input!\n");
        cleanInputBuffer();
        return;
    }
    printf("Minutes (0 - 59)? ");
    scanf("%u", &tempo->minutes);
    if(tempo->minutes > 59)
    {
        fprintf(stderr, "Bad Input!\n");
        cleanInputBuffer();
        return;
    }
    printf("Seconds (0 - 59)? ");
    scanf("%u", &tempo->seconds);
    if(tempo->seconds > 59)
    {
        fprintf(stderr, "Bad Input!\n");
        cleanInputBuffer();
        return;
    }
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
    struct Tempo t1;
    getTempo(&t1);
    printTempo(&t1);
}

