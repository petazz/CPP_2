#include "ScalarConverter.hpp"
#include <cstdlib>
#include <cctype>
#include <climits>

int isChar(std::string literal)
{
    return (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'');
}

int isInt(std::string literal)
{
    if (literal.empty()) return 0;
    
    size_t i = 0;
    if (literal[0] == '-' || literal[0] == '+') i++;
    
    for (; i < literal.length(); i++) {
        if (!isdigit(literal[i])) {
            return 0;
        }
    }
    
    char* end;
    long value = strtol(literal.c_str(), &end, 10);
    return (*end == '\0' && value >= INT_MIN && value <= INT_MAX);
}

int isFloat(std::string literal)
{
    if (literal == "nanf" || literal == "inff" || literal == "-inff")
        return 1;
        
    if (literal.empty() || literal[literal.size()-1] != 'f')
        return 0;
        
    std::string without_f = literal.substr(0, literal.size()-1);
    if (without_f.empty()) return 0;
    
    size_t i = 0;
    if (without_f[0] == '-' || without_f[0] == '+') i++;
    
    bool has_dot = false;
    for (; i < without_f.size(); i++) {
        if (!isdigit(without_f[i])) {
            if (without_f[i] == '.' && !has_dot) {
                has_dot = true;
            } else {
                return 0;
            }
        }
    }
    
    return 1;
}

int isDouble(std::string literal)
{
    if (literal == "nan" || literal == "inf" || literal == "-inf")
        return 1;
        
    if (literal.empty()) return 0;
    
    size_t i = 0;
    if (literal[0] == '-' || literal[0] == '+') i++;
    
    bool has_dot = false;
    for (; i < literal.size(); i++) {
        if (!isdigit(literal[i])) {
            if (literal[i] == '.' && !has_dot) {
                has_dot = true;
            } else {
                return 0;
            }
        }
    }
    
    return 1;
}