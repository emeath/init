#include <stdio.h>
#include <string.h>
int main(){
    char st[32];
    printf("Digite uma string: ");
    fgets(st, 32, stdin);
    st[strlen(st) - 1] = '\0'; // replace \n por \0
    printf(">>%s %d\n",st, strlen(st));
    return 0;
}
