#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>  
#include <iomanip> 

class ScalarConverter
{
	public:
		static void convert(std::string literal);
	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter &scalarConverter);
		ScalarConverter &operator=(const ScalarConverter &scalarConverter);
} ;

int isChar(std::string literal);
int isInt(std::string literal);
int isFloat(std::string literal);
int isDouble(std::string literal);
void convertChar(std::string literal);
void convertInt(std::string literal);
void convertFloat(std::string literal);
void convertDouble(std::string literal);

#endif