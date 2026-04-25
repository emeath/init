#ifndef C8_E07_LIB_20260425
#define C8_E07_LIB_20260425
#include <stdint.h>

struct Tempo
{
    uint8_t hour;
    uint8_t minutes;
    uint8_t seconds;
    uint8_t hasValidData;
    unsigned int totalInSeconds;
};


void getTempo(struct Tempo *tempo);

void cleanInputBuffer(void);

void printTempo(const struct Tempo *tempo);


#endif

