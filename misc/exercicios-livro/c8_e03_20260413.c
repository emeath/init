#include <stdio.h>
#include "c8_e03_20260413_lib.h"

int main ()
{
    Point p1, p2;
    getFromUserPoint(&p1);
    getFromUserPoint(&p2);
    printf("Distance between p1 (%.2f, %.2f) and p2 (%.2f, %.2f) is: %.2f\n",
            p1.x, p1.y,
            p2.x, p2.y,
            calculateDistanceBetween(&p1, &p2)); 
    return 0;
}
