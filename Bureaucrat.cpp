#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150)
{
	std::cout << "Bureacrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string _name, int grade) : _name(_name)
{
	if(this->_grade > 150)
		//funcion
	else if (this->_grade < 1)
		//funcion
	this->_grade = _grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name), grade(copy._grade)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &bureaucrat)
{
	this->_grade = bureaucrat._grade;
	std::cout << "Assigment operator called" << std::endl;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor called" << std::endl;
}

