#include "ScalarConverter.hpp"
#include <cstdlib>
#include <sstream>
#include <limits>
#include <cctype>
#include <iomanip>
#include <climits>

void convertChar(std::string literal)
{
    if (literal.length() != 3 || literal[0] != '\'' || literal[2] != '\'') {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: impossible\n";
        std::cout << "double: impossible\n";
        return;
    }

    char c = literal[1];
    std::cout << "char: '" << c << "'\n";
    std::cout << "int: " << static_cast<int>(c) << "\n";
    
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(c) << "f\n";
    std::cout << "double: " << static_cast<double>(c) << "\n";
}

void convertInt(std::string literal)
{
    char* end;
    long value = strtol(literal.c_str(), &end, 10);
    
    if (*end != '\0' || value > INT_MAX || value < INT_MIN) {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: impossible\n";
        std::cout << "double: impossible\n";
        return;
    }
    
    std::cout << "char: ";
    if (value < 32 || value > 126) {
        std::cout << "Non displayable\n";
    } else {
        std::cout << "'" << static_cast<char>(value) << "'\n";
    }
    
    std::cout << "int: " << static_cast<int>(value) << "\n";
    
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(value) << "f\n";
    std::cout << "double: " << static_cast<double>(value) << "\n";
}

void convertFloat(std::string literal)
{
    bool isSpecial = (literal == "nanf" || literal == "inff" || literal == "-inff");
    
    if (!isSpecial && literal.empty()) {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: impossible\n";
        std::cout << "double: impossible\n";
        return;
    }

    if (isSpecial) {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: " << literal << "\n";
        std::cout << "double: " << literal.substr(0, literal.size()-1) << "\n";
        return;
    }

    if (literal[literal.size()-1] == 'f') {
        literal = literal.substr(0, literal.size()-1);
    }

    char* end;
    double value = strtod(literal.c_str(), &end);
    
    if (*end != '\0') {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: impossible\n";
        std::cout << "double: impossible\n";
        return;
    }

    std::cout << "char: ";
    if (value < 32 || value > 126 || value != value) { // value != value comprueba NaN
        std::cout << "impossible\n";
    } else {
        std::cout << "'" << static_cast<char>(value) << "'\n";
    }

    std::cout << "int: ";
    if (value > INT_MAX || value < INT_MIN || value != value) {
        std::cout << "impossible\n";
    } else {
        std::cout << static_cast<int>(value) << "\n";
    }

    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(value) << "f\n";
    std::cout << "double: " << value << "\n";
}

void convertDouble(std::string literal)
{
    bool isSpecial = (literal == "nan" || literal == "inf" || literal == "-inf");
    
    if (isSpecial) {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: " << literal << "f\n";
        std::cout << "double: " << literal << "\n";
        return;
    }

    char* end;
    double value = strtod(literal.c_str(), &end);
    
    if (*end != '\0') {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: impossible\n";
        std::cout << "double: impossible\n";
        return;
    }

    std::cout << "char: ";
    if (value < 32 || value > 126 || value != value) {
        std::cout << "impossible\n";
    } else {
        std::cout << "'" << static_cast<char>(value) << "'\n";
    }

    std::cout << "int: ";
    if (value > INT_MAX || value < INT_MIN || value != value) {
        std::cout << "impossible\n";
    } else {
        std::cout << static_cast<int>(value) << "\n";
    }

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "float: " << static_cast<float>(value) << "f\n";
    std::cout << "double: " << value << "\n";
}