#include "ReportGeneratorService.h"
#include <thread>
#include <chrono>

using namespace std::chrono_literals;

ReportGeneratorService::ReportGeneratorService(InvoiceData invoiceData)
    : invoiceData{invoiceData} {}

std::string ReportGeneratorService::generateReport()
{
    std::this_thread::sleep_for(5s);
    report = "================\n";
    report += "Customer: " + invoiceData.getCustomerName() + "\n";
    report += "Id: " + std::to_string(invoiceData.getCustomerId()) + "\n";
    report += "Charges:\n";
    report += "Past: " + std::to_string(invoiceData.getPastAmount()) + "\n";
    report += "Advance: " + std::to_string(invoiceData.getAdvanceAmount()) + "\n";
    report += "Credit: " + std::to_string(invoiceData.getCreditAmount()) + "\n";
    report += "================\n";
    return report;
}