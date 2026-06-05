#pragma once
#include "InvoiceData.h"
#include <string>

class ReportGeneratorService
{

private:
    InvoiceData invoiceData;
    std::string report;

public:
    ReportGeneratorService(InvoiceData invoiceData);
    std::string generateReport();
};