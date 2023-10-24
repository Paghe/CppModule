#include "Convert.hpp"

void fromFloatToInt(float format)
{
	int num = static_cast<int>(format);
	std::cout <<"Int: " << num << std::endl;
}

void fromFloatToDouble(float format)
{
	std::stringstream stream;
	float value = static_cast<const float>(format);
	stream << std::fixed << std::setprecision(1) <<"Double: " << value;
	std::cout << stream.str() << std::endl;
}

void FloatConvertToDoubleAndInt(float format)
{
	if (format <= -2147483648.0 ||  format >= 2147483647.0)
	{
		std::cout << ERROR_COLOR << "Out of range" << RESET_TEXT << std::endl;
		return ;
	}
	fromFloatToInt(format);
	fromFloatToDouble(format);
}