#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {
	std::cout << "MutantStack default constructor called" << std::endl;
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &other) : std::stack