#include <iostream>
int main(){
    int *p1{new int};
    int *p2;
    int v1 = 4;
    p2=&v1;
    *p2=66;
    return 0;
}