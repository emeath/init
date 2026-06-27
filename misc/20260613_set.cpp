/*
mini exercicio

voce recebe um fluxo continuo de pacotes de rede que contem um intentificador uint32_t

devido a retransmissoes da rede o mesmo pacote pode ser enviado multiplas vezes

voce precisa ordenar de forma decrescente (para auditoria) os pacotes recebidos e parar quando tiver recebido todos eles

*/

#include <iostream>
#include <random>
#include <cstdlib>
#include <ctime>
#include <set>
#include <thread>
#include <chrono>

using namespace std;

struct Pacote
{
    uint32_t id;
    unsigned char dados[16];
};

class MountPackageService
{
private:
    struct Pacote mountedPackage;
    bool mountedPackageFlag = false;
    static MountPackageService *instance;

public:
    static MountPackageService *getInstance()
    {
        if (instance != nullptr)
        {
            return instance;
        }
        else
        {
            instance = new MountPackageService();
            return instance;
        }
    }

    void mountPackage(uint32_t id)
    {
        size_t i;
        for (i = 0; i < 15; ++i)
        {
            mountedPackage.dados[i] = sortear_caractere();
        }
        mountedPackage.dados[i] = '\0';

        mountedPackage.id = id;
        mountedPackageFlag = true;
    }

    char sortear_caractere()
    {
        const char caracteres[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

        static std::random_device rd;
        static std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, 61); // 62 caracteres no total (0 a 61)

        return caracteres[dis(gen)];
    }

    struct Pacote getMountedPackage(void)
    {
        if (isPackageMounted())
        {
            return mountedPackage;
        }
        else
        {
            cout << "Package not mounted! Error!\n";
            struct Pacote pacoteInvalido{0, {0}};
            return pacoteInvalido;
        }
    }

    bool isPackageMounted()
    {
        return mountedPackageFlag;
    }
};

MountPackageService *MountPackageService::instance = nullptr;

void printPackage(struct Pacote &pacote)
{
    cout << "Package id: " << pacote.id << "\n";
    cout << "Package data:\n";
    size_t i;
    for (i = 0; i < 16; ++i)
    {
        cout << pacote.dados[i];
    }
    cout << "\n\n";
}

uint32_t sortear_id()
{
    // Retorna o resto da divisão por 5, o que garante valores de 0 a 4
    return std::rand() % 5;
}

struct Pacote &packageTransmission(struct Pacote *packages)
{
    static size_t numberPackagesSent = 0;
    cout << "Number Packages Sent: " << ++numberPackagesSent << "\n";
    cout << "Transmitting package: >>>>>>>>>>>>>>>>>>\n";
    size_t id = sortear_id();
    printPackage(packages[id]);

    // simular demora na transmissao
    this_thread::sleep_for(150ms * sortear_id());

    return packages[id];
}

size_t capturePackages(struct Pacote &package)
{
    static struct Pacote packagesReceived[5];
    static set<uint32_t, greater<uint32_t>> setPackages;

    cout << "\t\t<<<<<<<<<<<<< Package captured now:\n\n";
    printPackage(package);

    size_t id = package.id;
    packagesReceived[id] = package;

    cout
        << "\t\t<<<<<<<<<<<<< All packated capture until now:\n\n";
    for (size_t j = 0; j < 5; ++j)
    {
        printPackage(packagesReceived[j]);
    }

    uint32_t last;
    setPackages.insert(package.id);
    set<uint32_t, greater<uint32_t>>::iterator it;
    it = setPackages.begin();
    last = *it;

    if (setPackages.size() == 5)
    {
        last += 1;
    }

    return last;
}

int main()
{
    srand(time(nullptr));

    bool allPackagesReceived = false;
    size_t packagesReceived = 0;

    // criar pacotes
    MountPackageService *mps = MountPackageService::getInstance();
    struct Pacote p[5];
    size_t i;
    for (i = 0; i < 5; ++i)
    {
        mps->mountPackage(i);
        p[i] = mps->getMountedPackage();
        printPackage(p[i]);
    }

    do
    {
        // transmitir
        struct Pacote received = packageTransmission(p);

        // capturar ate que todos sejam recebidos
        packagesReceived = capturePackages(received);
        if (5 == packagesReceived)
            allPackagesReceived = true;

    } while (!allPackagesReceived);

    return 0;
}