#ifndef C8_E11_LIB_20260509
#define C8_E11_LIB_20260509

struct Date // expected sizeof = 3 * 4 = 12 bytes
{
    unsigned int day, month, year;
};

void clearBuffer(void);
int setDay(int *, int);
int setMonth(int *, int);
void getDateFromUser(struct Date *);
char *prettyFormatDate1(struct Date *);
void prettyFormatDate2(struct Date *, char *);
unsigned int calculateDiffDaysFromDates(struct Date *,
                                        struct Date *);

#endif