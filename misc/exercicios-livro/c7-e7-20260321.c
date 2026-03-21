#include <stdio.h>
#include <string.h>
int isPalindrome(char word[]);

int main() 
{
char w[40];
fgets(w,40,stdin);
w[strlen(w) - 1] = '\0'; // replace \n char
if(isPalindrome(w)) printf("%s is Palindrome.\n", w);
else printf("%s is not palindrome.\n", w);
return 0;
}

int isPalindrome(char word[])
{
    size_t len = strlen(word);
//    printf("%d\n",len);
    size_t i;
    for(i = 0 ; i < len / 2; ++i)
    {
        if(word[i] != word[len-1 - i])
            return 0;
    }
    // after comparting all chars we can say is palindrome
    return 1;
}
