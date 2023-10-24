#include "Convert.hpp"

bool	ScalarConverter::checkInputErrors()
{
	if (ScalarConverter::_input == "nan")
	{
		std::cout << "Char: impossible" << std::endl
				<< "Int: impossible" << std::endl
				<< "float: nanf" <<std::endl
				<< "double: nan" << std::endl;
		return (false);
	}
	else if (ScalarConverter::_input == "+inf")
	{
		std::cout << "Char: impossible" << std::endl
				  << "Int: impossible" << std::endl
				  << "float: +inff" <<std::endl
				  << "double: +inf" << std::endl;
		return (false);
	}
	else if (ScalarConverter::_input == "+inff")
	{
		std::cout << "Char: impossible" << std::endl
				  << "Int: impossible" << std::endl
				  << "float: +inff" <<std::endl
				  << "double: +inf" << std::endl;
		return (false);
	}
	else if (ScalarConverter::_input == "-inf")
	{
		std::cout << "Char: impossible" << std::endl
				  << "Int: impossible" << std::endl
				  << "float: -inff" <<std::endl
				  << "double: -inf" << std::endl;
		return (false);
	}
	else if (ScalarConverter::_input == "-inff")
	{
		std::cout << "Char: impossible" << std::endl
				  << "Int: impossible" << std::endl
				  << "float: +inff" <<std::endl
				  << "double: -inf" << std::endl;
		return (false);
	}
	return (true);
}

void fromCharToInt(char format)
{
	int num = static_cast<int>(format);
	std::cout <<"Int: " << num << std::endl;
}

void fromCharToFloat(char format)
{
	std::stringstream stream;
	float value = static_cast<const char>(format);
	stream << std::fixed << std::setprecision(1) <<"Float: " <<value << "f";
	std::cout << stream.str() << std::endl;
}

void fromCharToDouble(char format)
{
	std::stringstream stream;
	double value = static_cast<const double>(format);
	stream << std::fixed << std::setprecision(1) <<"Double: " << value;
	std::cout << stream.str() << std::endl;
}

void CharConvertToFloatAndInt(char format)
{
	std::cout << "Char: " << format << std::endl;
	fromCharToInt(format);
	fromCharToDouble(format);
	fromCharToFloat(format);
}
