#include "Convert.hpp"

int			ScalarConverter::_integer = 0;
double		ScalarConverter::_double = 0.0;
float		ScalarConverter::_float = 0.0f;
char		ScalarConverter::_char = '\0';
std::string	ScalarConverter::_input = "";

ScalarConverter::ScalarConverter(std::string &input)
{
	_input = input;
}

