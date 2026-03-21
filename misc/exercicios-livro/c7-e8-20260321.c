#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int isSubStringValid(char *s1, char *s2) 
{
    if (strlen(s2) > strlen(s1))
        return 0;
    return 1;
}

char* getString()
{
    char *s = (char *) malloc( 40 * sizeof(char) );
    if (s == NULL) {
        printf("Error allocating string\n");
        return NULL;
    }
    fgets(s, 40, stdin);
    // remove \n
    s[strlen(s) - 1] = '\0';
    return s;
}

int isSubStringInString(char *s1, char *s2)
{
    // main string
    size_t lenMainString, lenSubString;
    lenMainString = strlen(s1);
    lenSubString = strlen(s2);
    size_t i,j;
    int substringIn = 0;
    for(i=0;i<lenMainString;++i){
        if(s2[0] == s1[i])
        {
            // check if main string has characters left
            // to avoid go beyond array limits
            if( ( lenMainString - i ) < lenSubString ) {
                substringIn = 0;
                printf("aqui...~");
                return substringIn;
            }

            for(j=0;j<lenSubString;++j) {
                if( s2[j] != s1[i + j]) {
                    substringIn = 0;
                    break;
                }
                substringIn = 1;
            }
            if(j == lenSubString) // reached end of substring
                return substringIn;
        }
    }
    return substringIn;
        
}

int main()
{
    printf("Write two strings. First the big word, Second the sub word to search on the first\n");
    printf("1) ");
    char *s3 = getString();
    printf("2) ");
    char *s4 = getString();

    printf("%s %s\n", s3, s4);

    if(!isSubStringValid(s3, s4)) {
        printf("Error) Substring %s is bigger than string %s\n", s4, s3);
        return 1;
    }

    if(isSubStringInString(s3, s4)) {
        printf("Substring %s is inside string %s\n", s4, s3);
    } else {
        printf("Subsstring %s is not inside string %s\n", s4, s3);
    }
    
    
    free(s3);
    free(s4);
    return 0; 
}

