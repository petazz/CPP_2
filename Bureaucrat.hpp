#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <cstdlib>
#include <iomanip>
#include <iostream>

class Bureaucrat
{
	private:
		const std::string _name;
		int _grade;
	public:
		Bureaucrat();
		Bureaucrat(const std::string _name, int grade);
		Bureaucrat(const Bureaucrat &bureaucrat);
		~Bureaucrat();

		Bureaucrat &operator=(const Bureaucrat &bureaucrat);
		Bureaucrat &operator<<(const Bureaucrat &bureaucrat);
		class GradeTooHighException : public std::exception{
		public:
			virtual const char* what() const throw(); 
		};
		class GradeTooLowException : public std::exception{
		public:
			virtual const char* what() const throw();
		};

		int getGrade() const;
		std::string getName() const;

} ;

#endif