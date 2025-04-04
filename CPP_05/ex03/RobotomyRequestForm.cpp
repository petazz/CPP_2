#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : target("TARGET")
{
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string &target) : AForm("RobotomyRequestForm", 25, 5), target(target)
{
	std::cout << "RobotomyRequestForm constructor called" << std::cout;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &RobotomyRequestForm)
{
	std::cout << "RobotomyRequestForm constructor copy called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &RobotomyRequestForm)
{
	std::cout << "RobotomyRequestForm assigement called" << std::endl;
	this->target = RobotomyRequestForm.target;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm::execute(Bureaucrat const &bureaucrat) const
{
	try
	{
		if (bureaucrat.getGrade > this->getSignGrade())
			throw	GradeTooLowException();
		if(bureaucrat.getGrade < 1)
			throw	GradeTooHighException();
		if (!this->getIsSigned())
			std::cout << "Is not signed" << std::endl;
		else
		{
			std::cout << "Informs that " << this->target << "has been pardoned by Zaphod Beeblebrox" << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}