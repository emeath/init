#include <stdio.h>

int main() {
	char frase[20] = "Hello World!";
	printf("%s\n", frase);
	frase[4] = '%';
	printf("%s\n", frase);
	return 0;
}
