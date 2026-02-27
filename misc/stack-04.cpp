#include <iostream>
#include <chrono>
#include <thread>
#include <iomanip>

void safe_release(int **pointer) {
    delete *pointer;
    *pointer = NULL;
}

void imprimir_linha(std::string nome, int **p)
{
    std::cout << std::left << std::setw(16) << nome
                           << std::setw(16) << p
                           << std::setw(16) << *p
                           << std::setw(16) << **p << std::endl;
}

int main() {

    int *p1{new int { 4 }};

    std::cout << "Hello World!" << std::endl;

    // delete p1;
    // p1 = NULL; // <-- nullptr!!

    // safe_release(&p1);

    std::cout << std::left << std::setw(16) << "ponteiro"
                           << std::setw(16) << "&ptr"
                           << std::setw(16) << "ptr->&"
                           << std::setw(16) << "*ptr" 
                           << std::endl;
    std::cout << std::string(55, '=') << std::endl;

    delete p1; // memoria alocada para p sera provavelmente sera alocada pelo SO para p2
    int *p2 = new int{999};
    imprimir_linha("p1", &p1);
    imprimir_linha("p2", &p2);
    std::cout << std::endl;

    for(int i = 0; i < 100; ++i) {

        std::this_thread::sleep_for(std::chrono::seconds(2));
        *p1 = i; // <-----------------------------------------------------------
        imprimir_linha("p1", &p1);
        imprimir_linha("p2", &p2);
        std::cout << std::endl;
    }

    return 0;
}

    /*
    
    Hello World!
    ponteiro        &ptr            ptr->&          *ptr            
    =======================================================
    p1              0x7fffffffdbb8  0x55555556ceb0  999             
    p2              0x7fffffffdbc0  0x55555556ceb0  999             

    p1              0x7fffffffdbb8  0x55555556ceb0  0               
    p2              0x7fffffffdbc0  0x55555556ceb0  0               

    p1              0x7fffffffdbb8  0x55555556ceb0  1               
    p2              0x7fffffffdbc0  0x55555556ceb0  1               

    p1              0x7fffffffdbb8  0x55555556ceb0  2               
    p2              0x7fffffffdbc0  0x55555556ceb0  2 

    */
