#include <stdio.h>
#include <string.h>

int main() {
	char string[100];
	char aux;
	size_t i;
	printf("OI BOM DIA! Digite uma string ai meu parceiro:");
	fgets(string, 100, stdin);
	string[ strlen(string) - 1 ] = '\0';
	size_t tam = strlen(string);
	for (i =0; i < tam / 2; ++i) {
		aux = string[tam - 1 - i];
		string[tam - 1 - i] = string[i];
		string[i] = aux;
	}
	printf("Ta na mao sua string invertida ;)\n");
	printf("%s\n", string);
	return 0;
}
