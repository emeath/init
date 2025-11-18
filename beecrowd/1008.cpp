#include <iostream>
#include <iomanip>

struct Funcionario {
    int id;
    int workedHours;
    double pricePerHour;
};

using namespace std;

int main() {
    struct Funcionario *ptrStcFuncionario = NULL;

    try {
        ptrStcFuncionario = new struct Funcionario;
    } catch (const bad_alloc& e) {
        cerr << "Faild to allocate memory: " << e.what() << endl;
        return 1;
    }
   
    cin >> (*ptrStcFuncionario).id >> ptrStcFuncionario->workedHours >> ptrStcFuncionario->pricePerHour;
   
    double amount = (*ptrStcFuncionario).workedHours * (*ptrStcFuncionario).pricePerHour;

    cout << "NUMBER = " << ptrStcFuncionario->id << endl;
    //cout << "SALARY = U$ " << fixed << setprecision(2) << amount << endl;
    cout << "SALARY = U$ " << setprecision(2) << fixed << amount << endl;


    delete ptrStcFuncionario;
    return 0;
}