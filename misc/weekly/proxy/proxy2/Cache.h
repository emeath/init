#pragma once
#include <string>

class Cache
{
private:
    std::string filename = "cache.txt";
    std::string data;

public:
    void store(std::string data);
    std::string getCachedData();
    bool isCacheValid();
};