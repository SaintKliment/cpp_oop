#include <iostream>
#include "darray.h"

int main() {
    DArray ar1, ar2;

    for(int i = 0; i < 10; i++) {
        ar1.push_back(i+1);
        std::cout << i + 1 << std::endl;
    }

    std::cout << ar1.size() << std::endl;

    ar2 = ar1;

    std::cout << ar2.size() << "\t" << ar2.capacity_ar() << std::endl;

    for(int i = 0; i < ar2.size(); i++) {
        std::cout << ar2.get_data()[i] << std::endl;
    }

    return 0;
}