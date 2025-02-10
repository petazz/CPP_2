#include "Form.hpp"

Form::Form() : _name("Default"), _signGrade(150), _executeGrade(150)
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string name, const int signGrade, const int executeGrade)
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

	std::cout << "Form constructor called" << std::endl;
}

Form::Form(const Form &form) : _name(form._name), _signGrade(form._signGrade), _executeGrade(form._executeGrade)
{
	std::cout << "Constructor copy called" << std::endl;
	this->_sign = _sign;
}

Form::~Form()
{
	std::cout << "Destructor called" << std::endl;
}

Form &Form::operator=(const Form &form)
{	
	std::cout << "Form assignament called" << std::endl;
	this->_sign =form._sign;
	return *this;
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
	os << form.getName() << ", Form sign grade " << 
	form.getSignGrade() << ", Form execute grade " << 
	form.getExecuteGrade() << std::endl;
	return os;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Form: Grade is too high\n";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Form: Grade is too low\n";
}

std::string Form::getName() const
{
	return this->_name;
}

int Form::getSignGrade() const
{
	return this->_signGrade;
}

int Form::getExecuteGrade() const
{
	return this->_executeGrade;
}

void Form::beSigned(Bureaucrat &bureaucrat)
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