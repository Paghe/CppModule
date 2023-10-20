#include "Convert.hpp"

void fromIntToDouble(int format)
{
	std::stringstream stream;
	double value = static_cast<const double>(format);
	stream << std::fixed << std::setprecision(1) <<"Dobule: " << value;
	std::cout << stream.str() << std::endl;
}

void fromIntToFloat(int format)
{
	std::stringstream stream;
	float value = static_cast<const double>(format);
	stream << std::fixed << std::setprecision(1) <<"Float: " <<value << "f";
	std::cout << stream.str() << std::endl;
}

void intConvertToFloatAndDouble(int format)
{
	fromIntToDouble(format);
	fromIntToFloat(format);
}