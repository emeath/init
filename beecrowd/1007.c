#include <stdio.h>

#ifdef DEBUG
	#define DEBUG_PRINT(...) printf("[DEBUG] " __VA_ARGS__)
     	#define MEMORY_SIM_PRINT(x) printf(#x " -> %p    [    %d    ]\n", &x, x)
     	#define MEMORY_SIM_POINTER_PRINT(x) printf(#x " -> %p    [    %p    ]\n", &x, x)
#else
	#define DEBUG_PRINT(...)
     	#define MEMORY_SIM_PRINT(x)
     	#define MEMORY_SIM_POINTER_PRINT(x)
#endif

int main(int argc, char *argv[]) {
	int A, B, C, D, *pA, *pB, *pC, *pD;
	int diferenca;

	DEBUG_PRINT("TESTE....");
	pA = &A;
	pB = &B;
	pC = &C;
	pD = &D;

	scanf("%d %d %d %d", pA, pB, pC, pD);

	int *pDiff = &diferenca;

	*pDiff = *pA * *pB - *pC * *pD;

	printf("DIFERENCA = %d\n", *pDiff);

	MEMORY_SIM_PRINT(A);
	MEMORY_SIM_PRINT(B);
	MEMORY_SIM_PRINT(C);
	MEMORY_SIM_PRINT(D);
	MEMORY_SIM_PRINT(diferenca);
	MEMORY_SIM_POINTER_PRINT(pA);
	MEMORY_SIM_POINTER_PRINT(pB);
	MEMORY_SIM_POINTER_PRINT(pC);
	MEMORY_SIM_POINTER_PRINT(pD);
	MEMORY_SIM_POINTER_PRINT(pDiff);

	return 0;
}
