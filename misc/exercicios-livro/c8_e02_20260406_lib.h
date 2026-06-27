#ifndef C8_E02_20260406_LIB
#define C8_E02_20260406_LIB

typedef struct
{
    float x;
    float y;
    char c1;
    char c2;
} Ponto;

float calculateDistanceBetween(const Ponto *, const Ponto *);

#endif