#include "RPN.hpp"
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cmath>

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN& other) {
    *this = other;
}

RPN& RPN::operator=(const RPN& other) {
    if (this != &other) {
        _stack = other._stack;
    }
    return *this;
}

bool RPN::isOperator(const std::string& token) {
    return (token == "+" || token == "-" || token == "*" || token == "/");
}

bool RPN::isNumber(const std::string& token) {
    if (token.empty())
        return false;
    
    for (size_t i = 0; i < token.length(); i++) {
        if (!std::isdigit(token[i]))
            return false;
    }
    return true;
}

float RPN::applyOperator(float a, float b, char op) {
    switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            if (b == 0) {
                throw std::runtime_error("Error: division by zero");
            }
            return a / b;
        default:
            throw std::runtime_error("Error: unknown operator");
    }
}

float RPN::evaluate(const std::string& expression) {
    std::istringstream iss(expression);
    std::string token;
    
    // Limpiar la pila
    while (!_stack.empty())
        _stack.pop();
    
    while (iss >> token) {
        if (isNumber(token)) {
            _stack.push(std::atof(token.c_str()));
        } else if (isOperator(token)) {
            if (_stack.size() < 2) {
                throw std::runtime_error("Error: invalid expression");
            }
            
            float b = _stack.top();
            _stack.pop();
            float a = _stack.top();
            _stack.pop();
            
            float result = applyOperator(a, b, token[0]);
            _stack.push(result);
        } else {
            throw std::runtime_error("Error: invalid token");
        }
    }
    
    if (_stack.size() != 1) {
        throw std::runtime_error("Error: invalid expression");
    }
    
    return _stack.top();
}
