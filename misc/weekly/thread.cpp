#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <string>

void simularScanAuditoria(std::string, unsigned int);
void semUsoDeThreads(std::vector<std::string>&, std::vector<int>&);
void comUsoDeThreads(std::vector<std::string>&, std::vector<int>&);
int menu();

int main() {

    int opt = menu();
    std::vector<std::string> pastas = {"/home/user/docs", "/etc/config", "/var/log", "/tmp/varenv"};
    std::vector<int> tempos = {10, 3, 2, 4};
    switch(opt) {
        case 1: 
            semUsoDeThreads(pastas, tempos);
            break;
        case 2:
            comUsoDeThreads(pastas, tempos);
            break;
        default:
            return -1;
    }
    return 0;   
}

void simularScanAuditoria(std::string pasta, unsigned int tempoProcessamento)
{
    std::cout << "[Inicio] fazendo auditoria e varredura em " << pasta << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(tempoProcessamento)); // simulando IO
    std::cout << "[Fim] varredura em " << pasta << " concluida." << std::endl;
}

int menu()
{
    int opt;
    std::cout << "--- menu ---" << std::endl;
    do {
        std::cout << "[1] - sem usar threads;" << std::endl;
        std::cout << "[2] - utilizando threads;" << std::endl;
        std::cout << "-----------------------------" << std::endl;
        std::cin >> opt;
    } while (opt < 1 || opt > 2);
    return opt;
}

void semUsoDeThreads(std::vector<std::string> &pastas, std::vector<int> &tempos)
{
    size_t i;
    std::chrono::duration<double> diff;
    auto start = std::chrono::high_resolution_clock::now();
    for (i = 0; i < pastas.size(); ++i) {
      auto localStart = std::chrono::high_resolution_clock::now();
      simularScanAuditoria(pastas[i], tempos[i]);  
      auto localEnd = std::chrono::high_resolution_clock::now();
      diff = localEnd - localStart;
      std::cout << "Task finalizada em " << diff.count() << " segundos." << std::endl;
    }
    auto end = std::chrono::high_resolution_clock::now();
    diff = end - start;
    std::cout << "TEMPO TOTAL = " << diff.count() << " SEGUNDOS." << std::endl;
}

void comUsoDeThreads(std::vector<std::string> &pastas, std::vector<int> &tempos)
{
    std::chrono::duration<double> diff;
    auto start = std::chrono::high_resolution_clock::now();
    std::vector<std::thread> workers;
    for(size_t i = 0; i < pastas.size(); ++i) {
        workers.emplace_back(simularScanAuditoria, pastas[i], tempos[i]);
    }
    for (auto &worker : workers) {
        worker.join();
    }
    auto end = std::chrono::high_resolution_clock::now();
    diff = end - start;
    std::cout << "TEMPO TOTAL = " << diff.count() << " SEGUNDOS." << std::endl;
}
