#include "Intern.hpp"

Intern::Intern() {
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::~Intern() {
	std::cout << "Intern destructor called" << std::endl;
}

Intern::Intern(const Intern &intern) {
	std::cout << "Intern copy constructor called" << std::endl;
	*this = intern;
}

Intern &Intern::operator=(const Intern &intern) {
	std::cout << "Intern assignation operator called" << std::endl;
	if (this == &intern)
		return *this;
	return *this;
}

Aform *Intern::makeForm(std::string formName, std::string target) {
	std::string formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm *form = NULL;
	for(int i=0; i < 3; i++) {
		if (formName == formNames[i]) {
			switch (i) {
				case 0:
					form = new ShrubberyCreationForm(target);
					break;
				case 1:
					form = new RobotomyRequestForm(target);
					break;
				case 2:
					form = new PresidentialPardonForm(target);
					break;
			}
			std::cout << "Intern creates " << formName << std::endl;
			return form;
		}
	}
	std::cout << "Intern could not create " << formName << std::endl;
	return NULL;
}
