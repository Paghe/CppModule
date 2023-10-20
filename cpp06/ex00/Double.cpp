#include "Convert.hpp"

void fromDoubleToInt(double format)
{
	int num = static_cast<int>(format);
	std::cout <<"Int: " << num << std::endl;
}

void fromDoubleToFloat(double format)
{
	std::stringstream stream;
	float value = static_cast<const double>(format);
	stream << std::fixed << std::setprecision(1) <<"Float: " <<value << "f";
	std::cout << stream.str() << std::endl;
}

void doubleConvertToFloatAndInt(double format)
{
	fromDoubleToInt(format);
	fromDoubleToFloat(format);
}