#ifndef AForm_HPP
#define AForm_HPP

#include <string>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;
class AForm
{
	private:
		const std::string _name;
		bool _sign;
		const int _signGrade;
		const int _executeGrade;

	public:
		AForm();
		AForm(const std::string name, const int signGrade, const int executeGrade);
		AForm(const AForm &AForm);
		virtual ~AForm();

		AForm &operator=(const AForm &AForm);

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
		virtual void execute(Bureaucrat const &bureaucrat) const = 0;
		
} ;
	
	std::ostream &operator<<(std::ostream &os, const AForm &AForm);

#endif