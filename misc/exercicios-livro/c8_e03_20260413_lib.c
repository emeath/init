#include <stdio.h>
#include <math.h>
#include "c8_e03_20260413_lib.h"

void getFromUserPoint(Point *storePoint)
{
    printf("Enter X and Y for point: ");
    float x, y;
    scanf("%f %f", &x, &y);
    storePoint->x = x;
    storePoint->y = y;
}

float calculateDistanceBetween(const Point *p1, const Point *p2)
{
    return sqrt( pow((p1->x - p2->x), 2) + pow((p1->y - p2->y), 2));
}
