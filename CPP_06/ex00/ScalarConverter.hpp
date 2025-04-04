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
		static void convert(std::string str);
	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter &scalarConverter);
		ScalarConverter &operator=(ScalarConverter &scalarConverter);
} ;

#endif