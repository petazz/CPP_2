#include <iostream>
#include <list>
#include "MutantStack.hpp"

int main()
{
    std::cout << "=== Test with MutantStack ===" << std::endl;
    MutantStack<int> mstack;
    
    mstack.push(5);
    mstack.push(17);
    
    std::cout << "Top: " << mstack.top() << std::endl;
    
    mstack.pop();
    
    std::cout << "Size: " << mstack.size() << std::endl;
    
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    
    ++it;
    --it;
    
    std::cout << "Iterating through MutantStack:" << std::endl;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    
    std::stack<int> s(mstack);
    
    std::cout << "\n=== Test with std::list (for comparison) ===" << std::endl;
    std::list<int> list;
    
    list.push_back(5);
    list.push_back(17);
    
    std::cout << "Back: " << list.back() << std::endl;
    
    list.pop_back();
    
    std::cout << "Size: " << list.size() << std::endl;
    
    list.push_back(3);
    list.push_back(5);
    list.push_back(737);
    list.push_back(0);
    
    std::list<int>::iterator lit = list.begin();
    std::list<int>::iterator lite = list.end();
    
    ++lit;
    --lit;
    
    std::cout << "Iterating through std::list:" << std::endl;
    while (lit != lite)
    {
        std::cout << *lit << std::endl;
        ++lit;
    }
    
    std::cout << "\n=== Additional tests ===" << std::endl;
    
    // Test con strings
    MutantStack<std::string> strStack;
    strStack.push("Hello");
    strStack.push("World");
    strStack.push("42");
    
    std::cout << "String stack:" << std::endl;
    for (MutantStack<std::string>::iterator sit = strStack.begin(); 
         sit != strStack.end(); ++sit)
    {
        std::cout << *sit << std::endl;
    }
    
    // Test copy constructor
    MutantStack<int> mstack2(mstack);
    std::cout << "\nCopied stack size: " << mstack2.size() << std::endl;
    
    return 0;
}