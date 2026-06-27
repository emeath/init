#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void convertToLower( char * );

int main()
{
    char string[200];
    
    size_t initialSize = 8;
    char *string2 = (char *) malloc( initialSize * sizeof(char) );
    char ch;
    size_t sizeCounter = 0;
    while (( ch = getchar() ) != '\n') {
        *(string2 + sizeCounter) = ch;
        sizeCounter++;
     
        if (sizeCounter > initialSize) {
            initialSize *= 2;
            printf("duplicando tamanho...\n");
            char *tmp = realloc(string2, initialSize * sizeof(char));
            if (tmp != NULL) string2 = tmp;
        }
    }
    *(string2 + sizeCounter + 1) = '\0';
     
    printf("string 2 dinamica = %s\n", string2); 
    printf("initialSize = %ld\n", initialSize);
    printf("sizeCounter = %ld\n", sizeCounter);
    printf("size: %ld\n", strlen(string2));
    convertToLower(string2);
    printf("upper! = %s\n", string2);


    fgets(string, sizeof(string), stdin);
    string[strlen(string)-1]='\0';
    printf("...%s\n", string);
    convertToLower(string);
    printf(">%s\n", string); 
    return 0;
}

void convertToLower(char *s)
{
    printf("strlen %ld\n", strlen(s));
    if( s == NULL) return;
    while ( *s != '\0' ) {
        if ( *s >= 97 && *s <= 122 ) 
            *s = *s - 32;
        s++;
    }
} 
