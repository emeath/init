#include <stdio.h>
#include <string.h>
int main()
{
    char st[32];
    char aux;
    gets(st);
    int i, j;
    printf("antes = %s .. %d\n", st, strlen(st));    
    for(i = strlen(st) - 1, j = 0; j < strlen(st) /2; i--, j++) {
        aux = st[i];
        st[i] = st[j];
        st[j] = aux;
    }
    printf("depois = %s\n", st);    
    return 0;
}
