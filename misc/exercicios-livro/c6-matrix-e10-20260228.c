#include <stdio.h>

#define L 10
#define C 3

typedef struct {
    int worstTest1;
    int worstTest2;
    int worstTest3;
} studentsScanResults;

void readStudentsScores(float [][C], size_t, size_t);
studentsScanResults scanWorstScoreOnTest(float [][C],
                                          size_t,
                                          size_t);
void printScanResults(studentsScanResults*);

int main() {
    // read students scores
    printf("Enter 3 scores of 10 students\n");
    float scores[L][C];
    readStudentsScores(scores, L, C);
    printf("nome %p\n", scores);
    printf("address %p\n", &scores[0][0]);
    // scan students that worst score was on test 1
    studentsScanResults ssr =
        scanWorstScoreOnTest(scores, L, C);
    // display results
    printScanResults(&ssr);
    return 0;
}

void readStudentsScores(float pScores[][C], 
                        size_t lines,
                        size_t cols)
{
    int j,k;
    for(j=0;j<lines;++j){
        for(k=0;k<cols;++k){
            scanf("%f", &pScores[j][k]);
        }
    }
    printf("All scores readed.\n");
}


studentsScanResults scanWorstScoreOnTest(float pScores[][C],
                                          size_t lines,
                                          size_t cols)
{
    studentsScanResults ssr = {0,0,0};    
    int j;
    float score1, score2, score3;
    for(j=0;j<lines;++j) {
        score1 = pScores[j][0];
        score2 = pScores[j][1];
        score3 = pScores[j][2];
  
        // worst on test 1
        if( score1 < score2
            && score1 < score3 )
            ++ssr.worstTest1;

        // worst on test 2
        if( score2 < score1
            && score2 < score3 )
            ++ssr.worstTest2;

        // worst on test 3
        if( score3 < score1
            && score3 < score2 )
            ++ssr.worstTest3;
    }
    return ssr;
}

void printScanResults(studentsScanResults *pSsr)
{
    printf("The number of students with "
           "worst score on test 1: %d\n", pSsr->worstTest1);
    printf("the number on test 2: %d\n", pSsr->worstTest2);
    printf("the number on test 3: %d\n", pSsr->worstTest3);
}
