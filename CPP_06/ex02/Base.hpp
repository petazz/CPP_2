#ifndef BASE_HPP
#define BASE_HPP

#include <cstdlib>
#include <ctime>
#include <iostream>

class A;
class B;
class C;

class Base
{
	public:
		virtual ~Base() = 0;
};
Base * generate(void);
void identify(Base* p);
void identify(Base& p);

#endif