#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main()
{
    vector<string> frutas = {"uva", "uva", "banana", "laranja", "banana", "uva"};
    size_t i;
    // criar mapa
    map<string, int> mapFrutas;
    map<string, int>::iterator itMF;

    for (i = 0; i < frutas.size(); ++i)
    {
        cout << frutas[i] << endl;
        // existe?
        itMF = mapFrutas.find(frutas[i]);
        if (itMF == mapFrutas.end())
        {
            mapFrutas[frutas[i]] = 1;
        }
        else
        {
            mapFrutas[frutas[i]] += 1;
        }
    }

    itMF = mapFrutas.begin();
    for (; itMF != mapFrutas.end(); ++itMF)
    {
        cout << "Fruta: " << itMF->first << " - Qtd: " << itMF->second << "\n";
    }

    return 0;
}