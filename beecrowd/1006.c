#include <stdio.h>
#include <stdlib.h>   // atoi, atof
int main (int argc, char *argv[]) {
	double A, B, C, media;
	if (argc > 1) {
		if (argc < 4) {
			// para redirecionar stderr para file ./a.out ... 2>error.log
			fprintf(stderr, "Usage: %s A B C\n", argv[0]);
			return 1;
		}
		A = atof(argv[1]);
		B = atof(argv[2]);
		C = atof(argv[3]);
	} else {
		scanf("%lf %lf %lf", &A, &B, &C);
	}
	media = (A*2 + B*3 + C*5) / 10.0;
	printf("MEDIA = %.1lf\n", media);
	return 0;
}
