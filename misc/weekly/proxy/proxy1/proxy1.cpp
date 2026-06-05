#include <iostream>
#include "InvoiceData.h"
#include "ReportGeneratorService.h"

InvoiceData inv(std::string("Mr. Bean"),
                77,
                std::string("2022-05-11:00:00:00"),
                344.33,
                344.33,
                -344.33,
                1);

void demo1()
{
    ReportGeneratorService rgs(inv);
    std::cout << rgs.generateReport();
}

int main()
{
    int opt = -1;
    do
    {
        std::cout << "[1] - run\n"
                  << "[n] - exit\n";
        std::cin >> opt;
        switch (opt)
        {
        case 1:
            demo1();
            break;
        default:
            opt = 0;
            std::cout << "exiting\n";
        }
    } while (opt != 0);

    return 0;
}