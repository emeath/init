#include <stdio.h>
#include <stdlib.h>


int main() {

    int *p = calloc(3, sizeof(int));

    #if DEBUG
    for(int i =0; i<3;++i){
        printf(">%p | %p | %d\n", &p, (p+i), *(p + i));
    }
    #endif

    //1o link
    scanf("%d", (p+0));

    for(int i = 0; i < 2; i++) {
        *(p + i + 1) = *(p + i) * 2;
    }

    //2o link
    // *(p+1) = *(p+0) * 2;

    //3o link
    // *(p+2) = *(p+1) * 2;

    printf("%d\n", *(p+2));

    #if DEBUG
    for(int i =0; i<3;++i){
        printf(">%p | %p | %d\n", &p, (p+i), *(p + i));
    }
    #endif

    return 0;
}