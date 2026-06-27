#include <stdio.h>
#include "c7_e11_20260328_string_lib.h"

int main() 
{
    char *s = getString();
    printf("-> %s\n", s);
    printf("Lower case: %s\n", convertStringToLowerCase(s));
    return 0;
}

