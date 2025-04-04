#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : target("TARGET")
{
	std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string &target) : AForm("PresidentialPardonForm", 72, 45), target(target)
{
	std::cout << "PresidentialPardonForm constructor called" << std::cout;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &PresidentialPardonForm)
{
	std::cout << "PresidentialPardonForm constructor copy called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &PresidentialPardonForm)
{
	std::cout << "PresidentialPardonForm assigement called" << std::endl;
	this->target = PresidentialPardonForm.target;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const &bureaucrat) const
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
			std::cout << " ***drilling noises***"
			std::srand((int)time(0));
			if(rand() % 2 == 0)
				std::cout << "Informs that " << this->target << "has been robotomized successfully" << std::endl;
			else
			{
				std::cout << "Informs that " << this->target << "has not been robotomized successfully" << std::endl;
				return 1;
			}
		}
		return 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}