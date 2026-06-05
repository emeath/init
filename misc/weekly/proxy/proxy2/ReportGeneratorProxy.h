#pragma once
#include "ReportGeneratorInterface.h"
#include "ReportGeneratorService.h"
#include "Cache.h"

class ReportGeneratorProxy : public ReportGeneratorInterface
{
private:
    ReportGeneratorService rgs;
    Cache cache;

public:
    ReportGeneratorProxy(ReportGeneratorService reportGeneratorService);
    std::string generateReport() override;
};
