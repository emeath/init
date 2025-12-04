#include <iostream>
#include <stdlib.h>
#define DEBUG 0

using namespace std;

int main() {

    // int N, M, diff;
    
//     int *pN, *pM;
//     pN =(int *)calloc(1, sizeof(int));
//     pM =(int *)calloc(1, sizeof(int));
// #if DEBUG
//     cout << &pN << " | " << pN << " | " << *pN << endl;
//     cout << &pM << " | " << pM << " | " << *pM << endl;
// #endif
//     cin >> *pN >> *pM;
//     diff = *pN - *pM;

    int *pArray;
    pArray =(int *) calloc(3, sizeof(int));
    cin >> *(pArray + 0) >> *(pArray + 1);
    *(pArray + 2) = *(pArray + 0) - *(pArray + 1);
#if DEBUG
    cout << &pArray  << " | " << (pArray + 0) << " | " << *pArray << endl;
    cout << "--------------" << " | " << (pArray + 1) << " | " << *(pArray + 1) << endl;
    cout << "--------------" << " | " << (pArray + 2) << " | " << *(pArray + 2) << endl;
    /*
        0x7ffe397adf40 | 0x5f6d5e305eb0 | 33
        -------------- | 0x5f6d5e305eb4 | 66
        -------------- | 0x5f6d5e305eb8 | -33
    */
#endif
    cout << *(pArray + 2) << endl;

    // cin >> N >> M;
    // diff = N - M;
    // cout << diff << endl;

    return 0;
}