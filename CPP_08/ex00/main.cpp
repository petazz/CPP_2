#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main() {
    int arr_v[] = {1, 2, 3, 4, 5};
    std::vector<int> v(arr_v, arr_v + 5);
    int arr_l[] = {10, 20, 30, 40};
    std::list<int> l(arr_l, arr_l + 4);

    try {
        std::vector<int>::iterator it = easyfind(v, 3);
        std::cout << "Found in vector: " << *it << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Vector error: " << e.what() << std::endl;
    }

    try {
        std::list<int>::iterator it = easyfind(l, 50);
        std::cout << "Found in list: " << *it << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "List error: " << e.what() << std::endl;
    }

    return 0;
}
