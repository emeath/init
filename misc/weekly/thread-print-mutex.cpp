#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;
int contador = 0;

void altera(int valor)
{
    for(int i = 0; i < 5000; ++i) {
    	std::lock_guard<std::mutex> lg(mtx);    
    	std::cout << "[" 
    		<< std::this_thread::get_id() 
    		<< "] alterando o contador...\n";
        contador += valor;
	}	
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
