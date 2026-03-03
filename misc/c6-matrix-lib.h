#ifndef C6_MATRIX_LIB
#define C6_MATRIX_LIB

static const int sizeMatrix = 5;


int isInMainDiag(size_t i, size_t j);

int isInSecondaryDiag(size_t i, size_t j, size_t lenSquareMatrix);

void calculateElementsInMainOrSecondaryDiag(int m[][sizeMatrix],
                                            size_t lines,
                                            size_t cols,
                                            int *destAns);

void calculateElementsOutsideDiags(int m[][sizeMatrix],
                                    size_t lines,
                                    size_t cols,
                                    int *destAns);

void readMatrix(int destM[][sizeMatrix],
                size_t lines,
                size_t cols);

void multiplyMatrix(int a[][sizeMatrix], int b[][sizeMatrix], int ans[][sizeMatrix]);

void printMatrix(int m[][sizeMatrix]);

#endif

