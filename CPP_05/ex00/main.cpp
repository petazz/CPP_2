#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat b1("Alice", 0);  // Error: demasiado alto
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try {
        Bureaucrat b2("Bob", 200);  // Error: demasiado bajo
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try {
        Bureaucrat b3("Charlie", 42);  // Correcto
        std::cout << b3.getName() << " tiene grado " << b3.getGrade() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
