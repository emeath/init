#include "ReportGeneratorProxy.h"
#include <iostream>

ReportGeneratorProxy::ReportGeneratorProxy(ReportGeneratorService reportGeneratorService)
    : rgs{reportGeneratorService} {}

std::string ReportGeneratorProxy::generateReport()
{
    if (cache.isCacheValid())
    {
        return cache.getCachedData();
    }
    else
    {
        std::string data = rgs.generateReport();
        cache.store(data);
        return data;
    }
}
