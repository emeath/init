#include <future>
#include <iostream>
#include <chrono>
#include <thread>

using namespace std::chrono_literals;

int lerDoBanco(void) {
	std::this_thread::sleep_for(60s);
	return 42;
}

void imprimeHoraAtual() {
    auto agora = std::chrono::system_clock::now();
    std::time_t tempo_formato_c = std::chrono::system_clock::to_time_t(agora);
    std::cout << "Hora atual: " << std::ctime(&tempo_formato_c);
}

int main() {
	std::cout << "inicio main...\n";
	imprimeHoraAtual();
	// dispara tarefa sem travar main
	std::future<int> resposta = std::async(lerDoBanco);
	
	imprimeHoraAtual();
	std::cout << "Inicio Simulacao processamento main...\n";
	std::this_thread::sleep_for(40s);
	imprimeHoraAtual();
	std::cout << "Fim Simulacao processamento main...\n";
	
	imprimeHoraAtual();
	std::cout << "a seguir obter dado do async...\n";
	// recuperar valor (se nao estiver pronto vai esperar)
	int valor = resposta.get();
	imprimeHoraAtual();
	std::cout << "obtido dado do async...\n";
	
	std::cout << "Valor do banco: " << valor << "\n";
	
	return 0;
}
