#include <stdio.h>
#include "c7_e13_20260328_lib.h"
#include <string.h>

int main(int argc, char **argv)
{
    printf("Enter a string: ");
    char *userString = getString();
    size_t stringLength = strlen(userString);
    printf("vc %s\n", userString);
    printf("Enter two non negative values: ");
    size_t i, j;
    int tmp1, tmp2;
    scanf("%d %d", &tmp1, &tmp2);
    if (!isInputValid(&tmp1,  &tmp2, &stringLength))
        handleNotValidInput();
    i = tmp1;
    j = tmp2;
    printSubString(userString, &i, &j);
    return 0;

}

