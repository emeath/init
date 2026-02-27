#include <iostream>
#include <chrono>
#include <thread>
#include <unistd.h>

void doSomething(int);
void doSomethingSafely(int);

int main(int argc, char *argv[]) {
    if(argc < 2) {
    	std::cerr << "Opcao invalida! Use -h para saber mais" << std::endl;
	return 1;
    }
    	
    int opt;
    int quantityInGB = 1;
    bool usar_safe = false;
    bool usar_unsafe = false;
    
    while( -1 != (opt = getopt(argc, argv, "suq:h") ) ) {
    	switch(opt) {
	    	case 's':
	    		usar_safe = true;
	    		break;
	    	case 'u':
	    		usar_unsafe = true;
	    		break;
	    	case 'q':
	    		quantityInGB = std::stoi(optarg);
	    		break;
	    	case 'h':
	    		std::cout << "Uso: " << argv[0] << " [-u|-s] -q [GB]" << std::endl;
	    		return 0;
	    	case '?':
	    		std::cerr << "Opcao invalida! Use -h para saber mais" << std::endl;
	    		return 1;
    	}
    }
    
    if (usar_safe) doSomethingSafely(quantityInGB);
    if (usar_unsafe) doSomething(quantityInGB);
    
    std::cout << "Back to main..." << std::endl;
    		
    while(1) {
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
}

void doSomething(int quantity)
{
    long len = (long)quantity * 1024*1024*1024;
    len = len / sizeof(int);
    // int = 4 Bytes
    std::cout << "Vai alocar " << quantity << " GB" << std::endl;
    int *ptrArr { new int[len]{} };
    std::cout << "Finishing doSomething()" << std::endl;
}

void doSomethingSafely(int quantity)
{
    long len = (long)quantity * 1024*1024*1024;
    len = len / sizeof(int);
    std::cout << "Vai alocar " << quantity << " GB" << std::endl;
    int *ptrArr { new int[len]{} };
    int i;
    for(i = 0; i < 5; ++i) { // wait 10 seconds
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
    delete[] ptrArr;
    std::cout << "Finishing doSomethingDafely()" << std::endl;
}
