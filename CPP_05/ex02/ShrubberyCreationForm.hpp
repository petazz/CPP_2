#ifndef	SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <string>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"


class ShrubberyCreationForm : public AForm
{
	private:
		std::string target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm &shrubclearberyCreationForm);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &shrubberyCreationForm);
		~ShrubberyCreationForm();

		void execute(Bureaucrat const &bureaucrat) const;
} ;

#endif