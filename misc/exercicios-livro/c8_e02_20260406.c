#include <stdio.h>
#include "c8_e02_20260406_lib.h"

// gcc c8_e02_20260406.c c8_e02_20260406_lib.c -lm

int main()
{
	Ponto ponto1;
	Ponto ponto0 = {0, 0};
	printf("Enter point 1 coordinates (x, y): ");
	scanf("%f %f", &ponto1.x, &ponto1.y);

	printf("Distance beetwen (%.2f, %.2f) and (0, 0) is: %.2f\n",
		   ponto1.x,
		   ponto1.y,
		   calculateDistanceBetween(&ponto1, &ponto0));

	return 0;
}
