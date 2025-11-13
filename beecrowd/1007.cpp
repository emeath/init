#include <iostream>


#ifdef DEBUG
	#define DEBUG_POINTER(p) printf(#p "=> %p [   %p    ]\n", &p, p)
	#define DEBUG_PRINT(...) printf("[DEBUG] " __VA_ARGS__ "\n")
#else
	#define DEBUG_POINTER(p)
	#define DEBUG_PRINT(...)
#endif

int main() {
	int *pA = NULL;
	int *pB = NULL;
	int *pC = NULL;
	int *pD = NULL;
	int *pDiff = NULL;
	DEBUG_POINTER(pA);
	DEBUG_POINTER(pB);
	DEBUG_POINTER(pC);
	DEBUG_POINTER(pD);
	DEBUG_POINTER(pDiff);

	DEBUG_PRINT("alocando dinamicamente memoria");
	pA = new int;
	pB = new int;
	pC = new int;
	pD = new int;
	pDiff = new int;

	DEBUG_POINTER(pA);
	DEBUG_POINTER(pB);
	DEBUG_POINTER(pC);
	DEBUG_POINTER(pD);
	DEBUG_POINTER(pDiff);

	DEBUG_PRINT("Processamento...");	
	std::cin >> *pA >> *pB >> *pC >> *pD;
	*pDiff = *pA * *pB - *pC * *pD;
	std::cout << "DIFERENCA = " << *pDiff << std::endl;

	DEBUG_PRINT("Desalocando memoria");
	delete pA;
	delete pB;	
	delete pC;	
	delete pD;	
	delete pDiff;	
	return 0;
}
