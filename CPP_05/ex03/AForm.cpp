#include "AForm.hpp"

AForm::AForm() : _name("Default"), _signGrade(150), _executeGrade(150)
{
	std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(const std::string name, const int signGrade, const int executeGrade)
	: _name(name), _signGrade(signGrade), _executeGrade(executeGrade)
{
	try
	{
		if (signGrade < 1 || executeGrade < 1)
			throw GradeTooHighException();
		else if (signGrade > 150 || executeGrade > 150)
			throw GradeTooLowException();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "AForm constructor called" << std::endl;
}

AForm::AForm(const AForm &AForm) : _name(AForm._name), _signGrade(AForm._signGrade), _executeGrade(AForm._executeGrade)
{
	std::cout << "Constructor copy called" << std::endl;
	this->_sign = _sign;
}

AForm::~AForm()
{
	std::cout << "Destructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &AForm)
{	
	std::cout << "AForm assignament called" << std::endl;
	this->_sign =AForm._sign;
	return *this;
}

std::ostream &operator<<(std::ostream &os, const AForm &AForm)
{
	os << AForm.getName() << ", AForm sign grade " << 
	AForm.getSignGrade() << ", AForm execute grade " << 
	AForm.getExecuteGrade() << std::endl;
	return os;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "AForm: Grade is too high\n";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "AForm: Grade is too low\n";
}

std::string AForm::getName() const
{
	return this->_name;
}

int AForm::getSignGrade() const
{
	return this->_signGrade;
}

int AForm::getExecuteGrade() const
{
	return this->_executeGrade;
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
	try
	{
		if (bureaucrat.getGrade() > this->_signGrade)
			throw GradeTooLowException();	
		this->_sign = true;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}