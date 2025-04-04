#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : target("TARGET")
{
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string &target) : AForm("ShrubberyCreationForm", 145, 137), target(target)
{
	std::cout << "ShrubberyCreationForm constructor called" << std::cout;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &shrubberyCreationForm) : AForm(shrubberyCreationForm), target(shrubberyCreationForm.target)
{
	std::cout << "ShrubberyCreationForm constructor copy called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &shrubberyCreationForm)
{
	std::cout << "ShrubberyCreationForm assigement called" << std::endl;
	if(this != &shrubberyCreationForm)
		*this = shrubberyCreationForm;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm::execute(Bureaucrat const &bureaucrat) const
{
	try
	{
		if (bureaucrat.getGrade > this->getSignGrade())
			throw	GradeTooLowException();
		
		if (!this->getIsSigned())
			std::cout << "Is not signed" << std::endl;
		else
		{
			std::ofstream file(this->target + "_shrubbery");
			if (!file)
				std::cerr << "Error opening file" << std::endl;
	

			file << "       _-_       " << std::endl;
			file << "    /~~   ~~\\   " << std::endl;
			file << " /~~         ~~\\ " << std::endl;
			file << "{               }" << std::endl;
			file << " \\  _-     -_  /" << std::endl;
			file << "   ~  \\\\ //  ~ " << std::endl;
			file << "_- -  | | _- _  " << std::endl;
			file << "  _ - | |   -_  " << std::endl;
			file << "      // \\      " << std::endl;

			file.close();
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

