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

static int countDot(const std::string &format)
{
	int dotCount;

	dotCount = 0;

	for (size_t i = 0; i < format.length(); i++)
	{
		if (!isdigit(format[0]) && (format[0] != '-' && format[0] != '+'))
			return (false);
		if (!isdigit(format[i]))
		{
			if (format[i] == '.' && !isdigit(format[i + 1]))
			{
				std::cerr << ERROR_COLOR << "Invalid format \"" << format[i] <<"\" is not allowed"<<
																			RESET_TEXT << std::endl;
				return (false);
			}
			else if (format[i] == '.')
				dotCount++;
		}
		if (dotCount > 1)
		{
			std::cerr << ERROR_COLOR << "Please provide only one \"" << format[i] <<"\""
																	<< RESET_TEXT << std::endl;
			return (false);
		}
	}
	return (dotCount);
}

static bool isFloat(const std::string &input)
{
	char 		*endptr;
	std::string validFormat;
	int 		dotCount;

	dotCount = 0;
	if (input.length() > 0 && input[input.length() - 1 ] == 'f') {
		validFormat = input.substr(0, input.length() - 1);
		dotCount = countDot(validFormat);
		strtof(validFormat.c_str(), &endptr);
		if (dotCount == 1)
			return (*endptr == '\0');
	}
	return (false);
}

static bool isDouble(const std::string &input)
{
	char 		*endptr;
	int 		dotCount;

	dotCount = 0;
	if (input.length() > 0)
	{
		strtof(input.c_str(), &endptr);
		dotCount = countDot(input);
		if (dotCount == 1)
			return (*endptr == '\0');
	}
	return (false);
}

static bool isInt(const std::string &input)
{
	for(size_t i = 0; i < input.length(); i++)
		if (!isdigit(input[i]))
			return (false);
	return (true);
}

void ScalarConverter::convert(std::string &input)
{
	if (isFloat(input))
		convertFloat(input);
	else if (isDouble(input))
		convertDouble(input);
	else if (isInt(input))
		convertInt(input);
	else
		convertChar(input);
}

ScalarConverter::~ScalarConverter() {}
