#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150)
{
	std::cout << "Bureacrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string _name, int grade) : _name(_name)
{
	if(this->_grade > 150)
		throw Bureaucrat::GradeTooHighException();
	else if (this->_grade < 1)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = _grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	this->_grade = _grade;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &bureaucrat)
{
	this->_grade = bureaucrat._grade;
	std::cout << "Assigment operator called" << std::endl;
	return (*this);
}

Bureaucrat &Bureaucrat::operator<<(const Bureaucrat &Bureaucrat)

Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor called" << std::endl;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Bureaucrat: Grade is too high\n";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Bureaucrat: Grade is too low\n";
}

int Bureaucrat::getGrade() const
{
	return this->_grade;
}

std::string Bureaucrat::getName() const{
	return this->_name;
}
