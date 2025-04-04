#ifndef	RobotomyRequestForm_HPP
#define RobotomyRequestForm_HPP

#include <string>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"


class RobotomyRequestForm : public AForm
{
	private:
		std::string target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string &target);
		RobotomyRequestForm(const RobotomyRequestForm &RobotomyRequestForm);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &RobotomyRequestForm);
		~RobotomyRequestForm();

		void execute(Bureaucrat const &bureaucrat) const;
} ;

#endif