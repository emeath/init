#include <stdio.h>
#include <string.h>

int ehVogal(char *);
size_t contarVogais(char *);
void substituirVogalPorCaracter(char *, char *, char *);

int main() {
	char string[100];
	fgets(string, 100, stdin);
	string[ strlen(string) - 1 ] = '\0';
	printf("Eu entendi que voce digitou: %s\n", string);
	printf("Possui %zu vogais.\n", contarVogais(string));
	printf("Digite vogal e outro caracter: ");
	char vogal, caracter;
	scanf(" %c %c", &vogal, &caracter);
	substituirVogalPorCaracter(string, &vogal, &caracter);
	printf("Nova string: %s\n", string);
}

int ehVogal(char *c) {
	char vogais[] = { 'a', 'A',
			  'e', 'E',
			  'i', 'I',
			  'o', 'O',
			  'u', 'U',
			  '\0' };
	char *andar = vogais;
	size_t qtd = 0, i;
	for(i=0; *andar != '\0'; andar++) {
		if ( *c == *andar ) return 1;
	}
	return 0;
}	

size_t contarVogais(char *s)
{
	size_t i,j;
	for (i=0; *s != '\0'; ++s) {
		if( ehVogal(s) ) ++i;
	}
	return i;
}

void substituirVogalPorCaracter(char *string, char *vogal, char *caracter)
{
	size_t i;
	for(i=0;string[i] != '\0'; ++i) {
		if ( ehVogal(vogal) && *vogal == string[i] ) {
			string[i] = *caracter;
		}	
	}
}
