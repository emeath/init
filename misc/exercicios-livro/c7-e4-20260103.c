#include <stdio.h>
#include <string.h>

int main() {
    char string[32];
    gets(string);
    int i;
    for(i = strlen(string); i > -1; --i){
        printf("%c", string[i]);
    }
    printf("\n");
    return 0;
}
