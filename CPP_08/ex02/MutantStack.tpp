#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() {
	std::cout << "Constructor MutantStack" << std::endl;
}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack &data)
{
	std::cout << "Constructor MutantStack Copy" << std::endl;
	if(this != &data)
		*this = data;
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &other) {
	std::cout << "MutantStack assignament operator" << std::endl;
    if (this != &other) {
        std::stack<T>::operator=(other);
    }
    return *this;
}

template <typename T>
MutantStack<T>::~MutantStack() {
	std::cout << "Destructor MutantStack" << std::endl;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
    return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
    return this->c.end();
}