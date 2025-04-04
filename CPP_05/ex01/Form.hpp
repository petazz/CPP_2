#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;
class Form
{
	private:
		const std::string _name;
		bool _sign;
		const int _signGrade;
		const int _executeGrade;

	public:
		Form();
		Form(const std::string name, const int signGrade, const int executeGrade);
		Form(const Form &form);
		~Form();

		Form &operator=(const Form &form);

		class GradeTooHighException : public std::exception{
		public:
			virtual const char* what() const throw(); 
		};
		class GradeTooLowException : public std::exception{
		public:
			virtual const char* what() const throw();
		};

		void beSigned(Bureaucrat &bureaucrat);
		std::string getName() const;
		int getSignGrade() const;
		int getExecuteGrade() const;
		
} ;
	
	std::ostream &operator<<(std::ostream &os, const Form &form);

#endif