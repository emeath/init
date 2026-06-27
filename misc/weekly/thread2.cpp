#include <iostream>
#include <thread>

int contador = 0;

void altera(int valor)
{    
    for(int i = 0; i < 1000000; ++i)
        contador += valor;
}

int main()
{
    std::thread t1(altera, 1);
    std::thread t2(altera, -1);

    t1.join();
    t2.join();

    std::cout << "Esperado contador = 0\n";
    std::cout << "Obtido contador = " << contador << "\n";

    return 0;
}
