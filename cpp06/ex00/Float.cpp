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
	fromFloatToInt(format);
	fromFloatToDouble(format);
}