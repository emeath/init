#include <stdio.h>
#include <string.h>

int main() {

	char word[] = "Abacate";
	printf("%ld\n", sizeof(word)); // 8 -> includes \0
	printf("%ld\n", strlen(word)); // 7

	return 0;
}
