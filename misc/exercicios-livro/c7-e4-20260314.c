#include <stdio.h>
#include <string.h>
int main(){

char string[100];
fgets(string,100,stdin);
size_t tam = strlen(string);
printf("-->%zu\n", strlen(string));
printf("%s|\n",string);
string[tam-1]='\0';
printf("%s|\n",string);
printf("-->%zu\n", strlen(string));
for(tam=0;tam<strlen(string);++tam) printf("%c",string[strlen(string) - 1 - tam]);
printf("\n");

return 0;
}
