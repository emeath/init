#include "InvoiceData.h"

InvoiceData::InvoiceData(std::string customerName,
                         int customerId,
                         std::string activationDate,
                         double pastAmount,
                         double advanceAmount,
                         double creditAmount,
                         bool active)
    : customerName{customerName},
      customerId{customerId},
      activationDate{activationDate},
      pastAmount{pastAmount},
      advanceAmount{advanceAmount},
      creditAmount{creditAmount},
      active{active} {}

std::string InvoiceData::getCustomerName() { return customerName; }
int InvoiceData::getCustomerId() { return customerId; }
std::string InvoiceData::getActivationDate() { return activationDate; }
double InvoiceData::getPastAmount() { return pastAmount; }
double InvoiceData::getAdvanceAmount() { return advanceAmount; }
double InvoiceData::getCreditAmount() { return creditAmount; }
bool InvoiceData::getActive() { return active; }