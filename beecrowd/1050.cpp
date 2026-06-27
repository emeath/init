#include <iostream>
#include <map>

typedef std::map<int, std::string> mapIS_t;

void initMap(mapIS_t &);
void displayMap(const mapIS_t &map);

int main()
{
    int userDDD{-1};
    std::cin >> userDDD;

    mapIS_t mapDDDCity;

    initMap(mapDDDCity);
    // displayMap(mapDDDCity);

    mapIS_t::const_iterator it;
    it = mapDDDCity.find(userDDD);
    if (it != mapDDDCity.end())
    {
        std::cout << it->second << "\n";
    }
    else
    {
        std::cout << "DDD nao cadastrado\n";
    }

    return 0;
}

void initMap(mapIS_t &map)
{
    map.insert({61, "Brasilia"});
    map[71] = "Salvador";
    map.insert({11, "Sao Paulo"});
    map[21] = "Rio de Janeiro";
    map.insert({32, "Juiz de Fora"});
    map[19] = "Campinas";
    map.insert({27, "Vitoria"});
    map[31] = "Belo Horizonte";
}

void displayMap(const mapIS_t &map)
{
    mapIS_t::const_iterator cit;
    cit = map.begin();
    for (; cit != map.end(); ++cit)
    {
        std::cout << "key = " << cit->first << " value = " << cit->second << "\n";
    }
}