#include <stdio.h>
int main(){
    char st[32];
    gets(st);
    int i;
    for(i=0;i<4;++i){
        printf("%c", st[i]);
    }
    printf("\n");
    return 0;
}
