#include <iostream>

void printPointer(int *ptr) {
    std::cout << "ADDRESS             VALUE" << std::endl;
    std::cout << ptr << "     | [ " << *ptr << "     ]" << std::endl;
}

int main() {
    int *p = (int *) calloc(3, sizeof(int));

    // t clicks 3o link
    std::cin >> *p;

    // 2o link
    *(p + 1) = 2 * *(p + 0);

    // 1o link
    *(p + 2) = 2 * *(p + 1);

    #if DEBUG
        std::cout << "clicks no 3o link: " << std::endl;
        printPointer(p);
        std::cout << "clicks no 2o link: " << std::endl;
        printPointer(p+1);
        std::cout << "clicks no 1o link: " << std::endl;
        printPointer(p+2);
    #endif

    std::cout << *(p+2) << std::endl;

    return 0;
}