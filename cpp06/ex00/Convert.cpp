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
ScalarConverter::ScalarConverter(const ScalarConverter &set)
{
	this->_input = set._input;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &cpy)
{
	this->_input = cpy._input;
	return (*this);
}

int ScalarConverter::getInteger()
{
	return (_integer);
}

double 		ScalarConverter::getDouble()
{
	return (_double);
}

float 		ScalarConverter::getFloat()
{
	return (_float);
}

char	ScalarConverter::getChar()
{
	return (_char);
}

std::string ScalarConverter::getInput()
{
	return (_input);
}
ScalarConverter::~ScalarConverter() {}


