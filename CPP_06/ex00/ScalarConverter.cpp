#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter constructor called" << std::endl;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter destructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &scalarConverter)
{
	if (this != &scalarConverter)
		*this = scalarConverter;
	std::cout << "ScalarConverter copy constructor called" << std::endl; 
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &ScalarConverter)
{
	(void)ScalarConverter;
	return (*this);
}

void ScalarConverter::convert(std::string literal)
{
	if (isChar(literal))
		convertChar(literal);
	else if(isInt(literal))
		convertInt(literal);
	else if(isFloat(literal))
		convertFloat(literal);
	else if(isDouble(literal))
		convertDouble(literal);
	else
		std::cout << "Literal type not recognise" << std::endl;
}

