#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stack>

class RPN {
    private:
        std::stack<float> _stack;
        
        bool isOperator(const std::string& token);
        bool isNumber(const std::string& token);
        float applyOperator(float a, float b, char op);
        
    public:
        RPN();
        ~RPN();
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);
        
        float evaluate(const std::string& expression);
};

#endif
