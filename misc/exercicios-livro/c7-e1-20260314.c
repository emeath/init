#include <stdio.h>
int main() {
	char string[30];
	fgets(string,30,stdin);
	printf("Vc digitou %s\n", string);
	return 0;
}
