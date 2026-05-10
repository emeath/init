#include <stdio.h>
#include <stdlib.h>
#include "c8_e11_lib_20260509.h"

int main()
{
    struct Date d1, d2;
    unsigned int diffDays = -1;
    getDateFromUser(&d1);
    getDateFromUser(&d2);
    char prettyDate2[10 + 1];
    prettyFormatDate2(&d2, prettyDate2);
    diffDays = calculateDiffDaysFromDates(&d1, &d2);
    printf("-> Difference between dates: %s and %s is %u.\n",
           prettyFormatDate1(&d1),
           prettyDate2,
           diffDays);

    return 0;
}
