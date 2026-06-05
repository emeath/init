#include "Cache.h"
#include <fstream>
#include <filesystem>
#include <iostream>

void Cache::store(std::string data)
{
    std::ofstream file(filename);
    if (file.is_open())
    {
        file << data;
        file.close();
    }
    else
    {
        std::cerr << "Cache error...\n";
    }
}
std::string Cache::getCachedData()
{
    std::ifstream file(filename);
    if (file.is_open())
    {
        data = "";
        std::string linha;
        while (std::getline(file, linha))
        {
            data += linha + "\n";
        }
        file.close();
        return data;
    }
    else
    {
        std::cerr << "Cache error reading...\n";
        return "";
    }
}
bool Cache::isCacheValid()
{
    if (std::filesystem::exists(filename))
        return true;
    else
        return false;
}
