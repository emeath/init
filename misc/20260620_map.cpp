#include <iostream>
#include <map>
#include <string>

int main()
{
    using namespace std;

    map<string, int> mapServiceDevices = {
        {"SNmax", 3},
        {"SNpro", 1},
        {"SNvim", 8}};

    map<string, int>::iterator itMapServDev;

    for (itMapServDev = mapServiceDevices.begin();
         itMapServDev != mapServiceDevices.end();
         ++itMapServDev)
    {
        cout << itMapServDev->first << " " << itMapServDev->second << "\n";
    }

    map<string, map<string, int>> mapContracts;
    string prefix = "contract000";

    int i = 1;

    for (
        itMapServDev = mapServiceDevices.begin();
        itMapServDev != mapServiceDevices.end();
        ++itMapServDev)
    {
        mapContracts.insert({prefix + to_string(++i), {{itMapServDev->first, itMapServDev->second}}});
    }

    auto itContr = mapContracts.begin();
    for (; itContr != mapContracts.end(); ++itContr)
    {
        for (itMapServDev = itContr->second.begin();
             itMapServDev != itContr->second.end();
             ++itMapServDev)
        {
            cout << "key1: " << itContr->first << "\n"
                 << "\tkey2: " << itMapServDev->first << " - value: " << itMapServDev->second << "\n\n";
        }
    }

    return 0;
}