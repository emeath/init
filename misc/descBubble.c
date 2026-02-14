#include <stdio.h>
int main()
{
    // bubble sort pra decrescente funciona?
    int lista[10] = {31,32,33,35,36,37,38,39,40,41};
    int i,j, aux;
    printf("antes\n");
    for(i=0;i<10;++i) printf("%d ", lista[i]);
    printf("\n\n");
    for(i=0;i<10;++i) {
        for(j=0;j<10-i-1;++j) {
            if(lista[j] < lista[j+1]) {
                aux = lista[j+1];
                lista[j+1] = lista[j];
                lista[j] = aux;
            }
        }
    }
    printf("depois\n");
    for(i=0;i<10;++i) printf("%d ", lista[i]);
    printf("\n\n");
    // conclusao: sim. Funciona.
    return 0;
}