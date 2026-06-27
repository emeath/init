#include <stdio.h>

struct Ponto
{
    float x, y;
};

struct Retangulo
{
    struct Ponto *pse;
    struct Ponto *pid;
};

int main()
{
    struct Retangulo rectangle;
    printf("Enter a rectangle:\n");
    printf("superior left point coordinates (x, y):\n");
    size_t got = 0;
    char c;
    struct Ponto point1;
    do
    {
        printf("Enter two float numbers: ");
        got = scanf("%f %f", &point1.x, &point1.y);
        while( (c = getchar() ) != '\n' && c != EOF );
    } while (2 != got);
    rectangle.pse = &point1;
    
    printf("inferior right point coordinates (x, y):\n");
    struct Ponto point2;
    do {
        printf("Enter two float numbers: ");
        got = scanf("%f %f", &point2.x, &point2.y);
        while( (c = getchar() ) != '\n' && c != EOF );
    } while ( 2 != got );
    rectangle.pid = &point2;
    
    printf("Enter a point to check if it's inside the previous rectangle\n");
    struct Ponto point3;
    do {
        printf("Enter two float numbers: ");
        got = scanf("%f %f", &point3.x, &point3.y);
        while( (c = getchar() ) != '\n' && c != EOF );
    } while ( 2 != got );
    
    // check
    if (    point3.x < rectangle.pse->x 
         || point3.x > rectangle.pid->x )
        printf("(%.2f, %.2f) is not inside the rectangle!\n", 
                point3.x, point3.y);
    
    else if (    point3.y < rectangle.pid->y 
         || point3.y > rectangle.pse->y )
         printf("(%.2f, %.2f) is not inside the rectangle!\n",
                 point3.x, point3.y);
    else
        printf("(%.2f, %.2f) IS inside the rectangle!\n",
               point3.x, point3.y);
    
    return 0;
}
    
    
    
    
