#include <iostream>
#include "Array.hpp"

int main() {
    // Empty array
    Array<int> a;
    std::cout << "a size = " << a.getSize() << std::endl;

    // Array with 5 ints
    Array<int> b(5);
    for (unsigned int i = 0; i < b.getSize(); ++i) {
        b[i] = static_cast<int>(i * 10);
    }
    std::cout << "b elements: ";
    for (unsigned int i = 0; i < b.getSize(); ++i) {
        std::cout << b[i] << ' ';
    }
    std::cout << std::endl;

    // Copy constructor
    Array<int> c = b;
    b[2] = 999;
    std::cout << "After modification b[2]=" << b[2] << " c[2]=" << c[2] << std::endl;

    // Exception test
    try {
        std::cout << b[10] << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
