#ifndef INTERN_HPP	
#define INTERN_HPP

#include <string>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Intern {
	public:
		Intern();
		~Intern();
		Intern(const Intern &intern);
		Intern &operator=(const Intern &intern);
		static AForm *makeForm(std::string formName, std::string target);
} ;

#endif