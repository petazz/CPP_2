#include <iostream>
#include <vector>
#include <cstdlib>
#include "Span.hpp"

int main() {
    try {
        Span sp(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;  // 2
        std::cout << sp.longestSpan() << std::endl;   // 14

        // Test agregar múltiples números con iteradores
        Span bigSpan(10000);
        std::vector<int> numbers;
        for (int i = 0; i < 10000; ++i) {
            numbers.push_back(rand() % 100000);
        }
        bigSpan.addNumbers(numbers.begin(), numbers.end());

        std::cout << "Shortest span (big): " << bigSpan.shortestSpan() << std::endl;
        std::cout << "Longest span (big): " << bigSpan.longestSpan() << std::endl;

    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}
