#include <stdio.h>
#include <stdlib.h>
int myStrlen(char s[30]) {
	size_t i;
	for(i=0; s[i] != '\0'; ++i);
	return i;
}

int main() {
	char string[30];
//	fgets(string,30,stdin);
	scanf("%s", string);
	printf("Vc digitou = %s\n", string);
	printf("Existem %d (%d) caracteres nela\n", myStrlen(string), strlen(string));
	return 0;
}
