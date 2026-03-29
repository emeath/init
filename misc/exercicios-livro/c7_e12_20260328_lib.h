#ifndef c7_e12_20260328_lib
#define c7_e12_20260328_lib

typedef struct {
    
    char *name;
    double price;
    double discount;

} Product;

char* getString(void);
double getPriceOnDiscount(const Product *);

#endif
