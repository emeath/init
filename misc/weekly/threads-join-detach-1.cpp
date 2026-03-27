#include <iostream>
#include <thread>

void work() { std::cout << "Hello Thread!\n"; }

int main() {
	std::thread t(work);
	return 0;
}

