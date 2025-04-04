#ifndef	PresidentialPardonForm_HPP
#define PresidentialPardonForm_HPP

#include <string>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"


class PresidentialPardonForm : public AForm
{
	private:
		std::string target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string &target);
		PresidentialPardonForm(const PresidentialPardonForm &PresidentialPardonForm);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &PresidentialPardonForm);
		~PresidentialPardonForm();

		void execute(Bureaucrat const &bureaucrat) const;
} ;

#endif