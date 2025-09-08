#include "iter.hpp"

template<typename T>
void printElement(T &element) {
    std::cout << element << " ";
}

int main() {
    int intArray[] = {1, 2, 3, 4, 5};
    iter(intArray, 5, printElement<int>); // Imprime: 1 2 3 4 5
    
    std::string strArray[] = {"hola", "mundo"};
    iter(strArray, 2, printElement<std::string>); // Imprime: hola mundo
}