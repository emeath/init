#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

std::mutex mtx;

// para habilitar literais 's', 'ms', 'ns'
using namespace std::chrono_literals;

void imprimeHoraAtual() {
	auto agora = std::chrono::system_clock::now();
	std::time_t tempo_formato_c = std::chrono::system_clock::to_time_t(agora);
	std::cout << "Hora atual: " << std::ctime(&tempo_formato_c);
}

void work() { 
	std::lock_guard<std::mutex> lg(mtx);
	std::cout << "Hello Thread! " << std::this_thread::get_id() << "\n";
	
	imprimeHoraAtual();
	std::this_thread::sleep_for(5s);
	imprimeHoraAtual();
}

void work2() {
	std::lock_guard<std::mutex> lg(mtx);
	std::cout << "Hello from " << std::this_thread::get_id() << "\n";
	imprimeHoraAtual();
	std::this_thread::sleep_for(1min + 20s);
	imprimeHoraAtual();
}

int main() {
	std::thread t(work);
	std::thread t2(work2);
	t.detach();
	t2.join();
	
	return 0;
}
