#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct item {
    char description[50], unitOfMeasure[10];
    float unitPrice;
    int itemId;
};

struct address {
    char street[50], city[50];
    int number;
};

struct customer {
    char name[50];
    struct address adr;
};

struct orderItem {
    struct item item;
    float qty;
};

struct order {
    struct orderItem ordItens[10];
    struct customer cust;
    char date[15];
    float orderTotal;
    int numberOfItens;
    float shippingTax;
    int orderId;
};

int calculateOrderTotal(struct order *ppOrder) {
    
    if(ppOrder->numberOfItens > 10)
        return -1;

    for(int i = 0; i < (*ppOrder).numberOfItens; ++i) {
        ppOrder->orderTotal += ppOrder->ordItens[i].item.unitPrice * ppOrder->ordItens[i].qty;
    }

    return 0;
}

void displayOrderInfo(struct order *ppOrder) {
    
    printf("- - - - - - - - - - - - - - - - - - - - - -\n");
    printf("- Order id: %d\n", ppOrder->orderId);
    printf("-------------------------------------------\n");
    printf("- Customer: %s\n", ppOrder->cust.name);
    printf("- Deliver to:\n");
    char fullAddress[256] = "";
    char buffer[20];
    strcat(fullAddress, "St: ");
    strcat(fullAddress, ppOrder->cust.adr.street);
    strcat(fullAddress, " N.: ");
    sprintf(buffer, "%d", ppOrder->cust.adr.number);
    strcat(fullAddress, buffer);
    strcat(fullAddress, " -- ");
    strcat(fullAddress, ppOrder->cust.adr.city);
    printf("---- %s\n", fullAddress);
    printf("- Ordered in %s\n", ppOrder->date);
    printf("- Net amount $ %.2f\n", ppOrder->orderTotal);
    printf("- Taxes $ %.2f\n", ppOrder->shippingTax);
    printf("- Total $ %.2f\n", ppOrder->orderTotal + ppOrder->shippingTax);
    printf("--------------------------------------------\n");
    printf("Itens:\n");
    for(int i = 0 ; i < ppOrder->numberOfItens ; ++i)
        printf("[%d] %s \t\t $ %.2f\n", i + 1, ppOrder->ordItens[i].item.description, ppOrder->ordItens[i].item.unitPrice * ppOrder->ordItens[i].qty);
    printf("\n");
    printf("- - - - - - - - - - - - - - - - - - - - - -\n");
}



int main() {

    struct item paperA4 = {"A4 Paper Ream", "unit", 4.5, 98};
    struct item paperLTR = {"Latter Paper Ream", "unit", 3, 102};
    struct item stapler = {"Red Stapler", "unit", 1, 330};
    
    struct address adr = {"Street x", "Scranton", 3384};

    struct customer cust = {"Michael Scott", adr};

    struct orderItem oi1 = { paperA4, 5 };
    struct orderItem oi2 = { paperA4, 2 };
    struct orderItem oi3 = { paperLTR, 3};
    struct orderItem oi4 = { stapler, 1 };

    struct order ord = { {oi1, oi2, oi3, oi4}, cust, "2026-03-04", 0, 4, 15, 88311 };
    
    calculateOrderTotal(&ord);
    displayOrderInfo(&ord);

    return 0;
}

/*

- - - - - - - - - - - - - - - - - - - - - -
- Order id: 88311
-------------------------------------------
- Customer: Michael Scott
- Deliver to:
---- St: Street x N.: 3384 -- Scranton
- Ordered in 2026-03-04
- Net amount $ 41.50
- Taxes $ 15.00
- Total $ 56.50
--------------------------------------------
Itens:
[1] A4 Paper Ream 		 $ 22.50
[2] A4 Paper Ream 		 $ 9.00
[3] Latter Paper Ream    $ 9.00
[4] Red Stapler 		 $ 1.00

- - - - - - - - - - - - - - - - - - - - - -


*/
