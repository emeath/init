#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int isSubStringValid(char *s1, char *s2); 
char* getString();
int isSubStringInString(char *main, char *sub);
int countHowManyTimesSubstringInMainString(char *main, char *sub);
int isPossibleToCutMainString(char *mainString, size_t currentPositionCursorOnMain, size_t howManyToCut);
void copySliceStringToBuffer(char *buffer, char *subString, size_t whereToStart, size_t goUntil);


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

    printf("Substring %s is present in %s -> %d times\n", s4, s3, countHowManyTimesSubstringInMainString(s3, s4));

    free(s3);
    free(s4);
    return 0; 
}

int isPossibleToCutMainString(char *mainString, size_t currentPositionCursorOnMain, size_t howManyToCut)
{
   if( currentPositionCursorOnMain + howManyToCut > strlen(mainString) )
       return 0;

   return 1;
}

void copySliceStringToBuffer(char *buffer, char *mainString, size_t whereToStart, size_t goUntil)
{
    size_t i,j;
    for(i = whereToStart, j = 0; i <= goUntil; ++i, ++j) {
        buffer[j] = mainString[i];
    }
}

int countHowManyTimesSubstringInMainString(char *main, char *sub)
{
    int count = 0;
    char *buffer;
    size_t i;
    for(i=0;i<strlen(main);++i){
        if( *(main + i) == *(sub + 0) ) {
            if (isPossibleToCutMainString(main, i, strlen(sub))) {
                buffer = (char *) malloc ( (strlen(sub)) * sizeof(char) );
                if (buffer == NULL) {
                    printf("Not possible to allocate mem for buffer. Fatal error.\n");
                    return -1;
                }
                size_t start, end;
                start = i;
                end = start + strlen(sub) - 1; 
                copySliceStringToBuffer(buffer, main, start, end);

                if ( isSubStringInString(buffer, sub) )
                    ++count; 

                free(buffer);
            }
        }
    }

    return count;
}

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

int isSubStringInString(char *main, char *sub)
{
    // main string
    size_t lenMainString, lenSubString;
    lenMainString = strlen(main);
    lenSubString = strlen(sub);
    size_t i,j;
    int substringIn = 0;
    for(i=0;i<lenMainString;++i){
        if(sub[0] == main[i])
        {
            // check if main string has characters left
            // to avoid go beyond array limits
            if( ( lenMainString - i ) < lenSubString ) {
                substringIn = 0;
                printf("aqui...~");
                return substringIn;
            }

            for(j=0;j<lenSubString;++j) {
                if( sub[j] != main[i + j]) {
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
