#ifndef C8_E10_LIB_20260502
#define C8_E10_LIB_20260502
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "c8_e09_lib_20260502.h"

/*
disclaimer no user input validation will be done due to
time constraints
*/

/*
    uses implementation of c8_e09
*/

void evaluateOldestToYoungets(Atleta *, size_t, Atleta *);

void pointersEvaluateOldestToYoungets(
    Atleta *,
    size_t,
    Atleta **);

void printArrayOfPointers(const Atleta **, size_t);

#endif