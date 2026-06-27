#include <stdio.h>

float maior(float a, float b)
{
    if (a > b) return a;
    return b;
}

void cleanBuffer()
{
    char c;
    while( ( c = getchar() ) != '\n' && c != EOF );
}

int main()
{
    float x, y;
    int n;
    char c;
    do {
        printf("enters two numbers: ");
        n = scanf("%f %f", &x, &y);
        cleanBuffer();
    } while (n != 2);
    printf("bigger is: %f\n", maior(x, y));

    return 0;
}
