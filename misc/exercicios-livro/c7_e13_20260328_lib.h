#ifndef C7_E13_20260328_LIB
#define C7_E13_20260328_LIB
#include <stdlib.h>

int      isParametersValid(const int*, const int*);
char*    getString(void);
char*    getSubString(char *, const int*, const int*);
int      isRangeInsideStringRange(char *, const int*, const int*);
int      isNecessaryToReallocate(size_t, size_t);
char*    allocateMemoryForString(size_t);
char*    realocateMemoryForString(char *, size_t);
void     handleErrorWhenReallocating();
int      successFullyAllocatedMemory(char *);
int      isInputValid(const int*, const int*, const size_t*);
void     handleNotValidInput();
void     printSubString(const char *, const size_t *, const size_t*);

#endif
