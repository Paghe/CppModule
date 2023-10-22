#include "Convert.hpp"

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
/*	if (!isprint(format))
	{
		std::cout << "Char: Non displayable"<< std::endl;
		return ;
	}*/
	std::cout << "Char: " << format << std::endl;
	fromCharToInt(format);
	fromCharToDouble(format);
	fromCharToFloat(format);
}