#include <stdio.h>
#include <string.h>

int main()
{
    char string1[100];
    char string2[100];
    
    char result[202];

    fgets(string1, sizeof(string1), stdin);
    string1[ strlen(string1) - 1 ] = '\0'; // removes \n when reaind from line buffer
    
    fgets(string2, sizeof(string2), stdin);
    string2[ strlen(string2) - 1 ] = '\0';

    // compare alphabetically two strings
    size_t len1 = strlen(string1);
    size_t len2 = strlen(string2);
    size_t i, shorter = 0;
 
    // iterate based on shorter len
    if ( len1 > len2 )
        shorter = len2;
    else
        shorter = len1;    
    
    for (i = 0; i < shorter; ++i )
    {
        if ( *(string1 + i) > *(string2 + i) )
        {
            snprintf(result, sizeof(result), "%s\n%s\n", string2, string1);
            break;
        }
        else if ( *(string1 + i) < *(string2 + i) )
        {
            snprintf(result, sizeof(result), "%s\n%s\n", string1, string2);
            break;
        }
        
        // if chars are equals go to next iteration to check


        // if reached end of shorter string and chars are quals
        // e.g word aa and word aam aa should be printed first

        if( i == shorter - 1)
        {
            if ( strlen(string1) == shorter )
                snprintf(result, sizeof(result), "%s\n%s\n", string1, string2);
            else
                snprintf(result, sizeof(result), "%s\n%s\n", string2, string1);
        }
    }

    printf("%s", result);

    return 0;
}
