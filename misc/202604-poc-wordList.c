#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** storeList(char **store, size_t *amountWord)
{
    char *lista[] = {"banana", "uva", "ovo"};
    printf("Inside store\n");
    for(size_t i = 0 ; i < 3; ++i)
    {
        printf("%s\n", lista[i]);
    }

    *amountWord = 3;
    
    char **buffer;
    
    // alocar linhas
    buffer = (char **) malloc ( 3 * sizeof(char *) );   
    if(!buffer) return NULL;

    printf("buffer addr = %p\n", buffer);
 
    //alocar colunas (sei q temos 3 palavras)
    for(int i = 0 ; i < 3; ++i)
    {
        *(buffer + i) = (char *) malloc ( (strlen(lista[i]) + 1) * sizeof(char) );
        if( ! *(buffer + i) ) return NULL;
    }

    printf("como estava antes\n");
    for( int i = 0 ; i < 3 ; ++i )
    {
        printf("%s\n", *(buffer+i));
    }

    printf("\n\n\n");

    // copiar palavra para o local alocado dinamicamente
    for( int i = 0 ; i < 3 ; ++i )
    {
        strcpy( *(buffer+i) , lista[i] );
       *(*(buffer+i) + strlen(lista[i])) = '\0';
    }

    //print pra debugar
    printf("como ficou\n");
    for(int i = 0; i < 3; i++)
    {
        printf("%s\n", *(buffer+i));
    }

    return buffer;
}

int main ()
{
    char **lista = NULL;
    size_t amount = 0;
    printf("lista addr = %p\n", lista);
    lista = storeList(lista, &amount);
    printf("lista addr = %p\n", lista);
    for(size_t linhas = 0; linhas < amount ; ++linhas)
    {
        printf("%s\n", *(lista + linhas));
    }

    for(size_t a = 0; a < amount; ++a)
    {
        printf("freeing *(lista + a) = %p\n", *(lista + a));
        free( *(lista + a) );
    }


    printf("freeing lista = %p\n", lista);
    free (lista);

    return 0;
}
