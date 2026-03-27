#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

// cadeado / cahve
std::mutex mutex;

int contador = 0;

void altera(int valor)
{    
    for(int i = 0; i < 1000000; ++i) {
        // trancar - recurso sera utilizado
        mutex.lock();
        // processar
        contador += valor;
        if (contador > 400) {
        	std::cout << std::this_thread::get_id() << " | Recurso travado pra semre...\n";
        	return; // objeto lock guard saira de escopo -> destructor
        }
        // destrancar - liberar recurso
        mutex.unlock();
    }
}

int main()
{

    std::thread t1(altera, 1);
    std::thread t2(altera, -1);
    std::vector<std::thread::id> threads;
    threads.push_back(t1.get_id());
    threads.push_back(t2.get_id());

	std::cout << "Threads iniciadas:\n";

	for( auto& thread_id : threads) {
		std::cout << thread_id << "\n";
    }

    t1.join();
    t2.join();

    std::cout << "Esperado contador = 0\n";
    std::cout << "Obtido contador = " << contador << "\n";

    return 0;
}
