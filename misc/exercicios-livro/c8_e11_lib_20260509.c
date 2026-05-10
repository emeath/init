#include <stdio.h>
#include <stdlib.h>
#include "c8_e11_lib_20260509.h"

void clearBuffer(void)
{
    char c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

int setDay(int *dest, int val)
{
    if (val > 31)
    {
        printf("Invalid day.\n");
        return 1; // error
    }

    *dest = val;
    return 0; // ok
}

int setMonth(int *dest, int val)
{
    if (val > 12)
    {
        printf("Invalid month.\n");
        return 1; // error
    }

    *dest = val;
    return 0; // ok
}

void getDateFromUser(struct Date *dest)
{
    unsigned int bufferDay, bufferMonth, bufferYear;
    int n = 0;

    do
    {
        printf("Enter day month year: ");
        n = scanf("%d %d %d",
                  &bufferDay,
                  &bufferMonth,
                  &bufferYear);
        if (setDay(&(dest->day), bufferDay) == 1)
        {
            n = -1;
        }
        if (setMonth(&(dest->month), bufferMonth) == 1)
        {
            n = -1;
        }
        clearBuffer();
    } while (n != 3);
    dest->year = bufferYear;
}

char *prettyFormatDate1(struct Date *src)
{
    const unsigned int numberBytes = 11;
    char *string = malloc(numberBytes * sizeof(char));
    if (string == NULL)
        return NULL;
    snprintf(string,
             numberBytes,
             "%02d/%02d/%04d",
             src->day,
             src->month,
             src->year);
    return string;
}

void prettyFormatDate2(struct Date *src, char *dest)
{
    snprintf(dest,
             11,
             "%02d/%02d/%04d",
             src->day,
             src->month,
             src->year);
}

unsigned int calculateDiffDaysFromDates(struct Date *d1,
                                        struct Date *d2)
{
    unsigned int totalDaysD1 = -1;
    unsigned int totalDaysD2 = -1;
    int ans = -1;

    totalDaysD1 = d1->year * 365 +
                  d1->month * 30 +
                  d1->day;

    totalDaysD2 = d2->day +
                  d2->month * 30 +
                  d2->year * 365;

    ans = totalDaysD2 - totalDaysD1;

    if (ans < 0)
        ans *= -1;

    return ans;
}
