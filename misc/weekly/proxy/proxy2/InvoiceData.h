#pragma once
#include <string>

class InvoiceData
{
private:
    std::string customerName;
    int customerId;
    std::string activationDate;
    double pastAmount;
    double advanceAmount;
    double creditAmount;
    bool active;

public:
    InvoiceData(
        std::string customerName,
        int customerId,
        std::string activationDate,
        double pastAmount,
        double advanceAmount,
        double creditAmount,
        bool active);
    std::string getCustomerName();
    int getCustomerId();
    std::string getActivationDate();
    double getPastAmount();
    double getAdvanceAmount();
    double getCreditAmount();
    bool getActive();
};