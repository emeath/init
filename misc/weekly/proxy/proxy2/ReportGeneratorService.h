#pragma once
#include "ReportGeneratorInterface.h"
#include "InvoiceData.h"
#include <string>

class ReportGeneratorService : public ReportGeneratorInterface
{

private:
    InvoiceData invoiceData;
    std::string report;

public:
    ReportGeneratorService(InvoiceData invoiceData);
    std::string generateReport() override;
};