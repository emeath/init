#include <stdio.h>
int main(){
	char string[30];
	printf("digite uma string! =)\n");
	fgets(string,30,stdin);
	size_t i;
	for(i=0;i<4;++i){
	printf("%c ",string[i]);
	}
	return 0;
}
