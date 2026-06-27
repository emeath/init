#include <stdio.h>
#include <stdlib.h>

#define AmountStudents 5

struct Aluno
{
    unsigned int registrationNumber;
    char *name;
    float scores[3];
};

char *getString()
{
    size_t initialSize = 8;
    size_t currentSize = initialSize;
    size_t currentPosition = 0;
    char ch;
    char *tmp = NULL;
    char *string = (char *) malloc (initialSize * sizeof(char));
    if(!string) return NULL;
    do{
        if( currentPosition > currentSize - 1 )
        {
            // realloc
            currentPosition = currentPosition + 32;
            tmp = realloc( string, currentPosition * sizeof(char) );
            if (!tmp) return NULL;
            string = tmp;
        }
        ch = getchar();
        *(string + currentPosition) = ch;
        currentPosition++;
    } while ( '\n' != ch );
    *(string + currentPosition - 1) = '\0';
    return string;
}

void cleanUpBuffer()
{
    char c;
    while( (c = getchar()) != '\n' && c != EOF );
}


int main()
{
    struct Aluno students[AmountStudents];
    size_t i;
    for (i = 0; i < AmountStudents; ++i)
    {
        printf("Student #%zu\n", i+1);
        printf("Registration Number? ");
        scanf("%u", &students[i].registrationNumber);
        cleanUpBuffer();
        printf("Name? ");
        students[i].name = getString();
        printf("All 3 tests scores: ");
        scanf("%f %f %f", &students[i].scores[0], 
                          students[i].scores + 1,
                          &students[i].scores[2]);
        printf("======\nI've got:\n");
        printf("Registration Number = %u\n", students[i].registrationNumber);
        printf("Name = %s\n", students[i].name);
        printf("%.2f %.2f %.2f\n", students[i].scores[0],
                                   students[i].scores[1],
                                   students[i].scores[2]);
    }
    
    size_t bestAvgIndex = 0;
    float currentStudentAvg = 0, bestStudentAvg = 0;
    size_t j;
    for (i = 0; i < AmountStudents; ++i)
    {
        currentStudentAvg = 0;
        for(j = 0; j < 3; ++j)
        {
            currentStudentAvg += *(students[i].scores + j);
        }
        currentStudentAvg = currentStudentAvg / 3.0;
        if (currentStudentAvg > bestStudentAvg)
        {
            bestAvgIndex = i;
            bestStudentAvg = currentStudentAvg;
        }
    }
    
    // best student data
    printf("Best student data:\n------------------\n");
    printf("Registration Number: %u\n", 
            students[bestAvgIndex].registrationNumber);
    printf("Name: %s\n", 
            students[bestAvgIndex].name);
    printf("Scores: %.2f %.2f %.2f\n", 
            students[bestAvgIndex].scores[0],
            students[bestAvgIndex].scores[1],
            students[bestAvgIndex].scores[2]);
    printf("Average: %.2f\n", bestStudentAvg);
    
    for (i = 0; i < AmountStudents; ++i)
    {
        if(NULL != students[i].name)
        {
            free(students[i].name); // avoid memory leak
            students[i].name = NULL; // avoid dangling pointer
        }
    }
          
    
    return 0;
}
