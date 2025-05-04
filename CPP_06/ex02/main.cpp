#include "Base.hpp"

int main (void)
{
	Base *randomize = generate();
	identify(randomize);
	identify(*randomize);
	delete randomize;
}