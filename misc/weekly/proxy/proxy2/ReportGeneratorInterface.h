#pragma once
#include <string>

class ReportGeneratorInterface
{
    virtual std::string generateReport() = 0;
};