#include <iostream>

void seeCounter(void);
void seeRandom(void);

int main() {
    seeCounter();
    seeCounter();
    seeRandom();
    int x = 3;//dcb8
    seeCounter();
    int y = x - 2;//dcbc
    seeRandom();
    seeCounter();
    std::cout << "Goodbye world!" << std::endl;
    seeCounter();
    return 0;
}

void seeCounter(void)
{
    static int counter = 0;//8158
    std::cout << "seeCounter chamada! -> " << ++counter << std::endl;
}

void seeRandom(void)
{
    int a = 4; //dc9c
    std::cout << "seeRandom chamada! -> " << ++a << std::endl;
}