#include <stdio.h>
#include "c7_e12_20260328_lib.h"

int main() {
    Product product;
    product.name = getString();
    product.price = 1050;
    product.discount = 0.1; // 10%

    printf("Product name is: %s\n", product.name);
    printf("Product price: %.2f\n", product.price);
    printf("Discounted price: %.2f\n", getPriceOnDiscount(&product)); 
    return 0;
}
