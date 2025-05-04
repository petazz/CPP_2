#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <iostream>

Base::~Base()
{
	std::cout << "Base destructor called" << std::endl;
}

Base * generate(void)
{
	srand((int)time(0));
	int numR = rand();
	if (numR % 3)
		return(new A());
	else if (numR % 2)
		return(new B());
	else
		return(new C());
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "Pointer A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Pointer B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Pointer C" << std::endl;
}

void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "Reference A" << std::endl;
        return;
    } catch (...) {}
    
    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "Reference B" << std::endl;
        return;
    } catch (...) {}
    
    std::cout << "Reference C" << std::endl;
}