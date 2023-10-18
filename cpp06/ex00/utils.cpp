#include "Convert.hpp"

typedef void (*FunctionArray)(const void *format);

void	printFloat(const void* format)
{
	std::stringstream stream;
	float value = *static_cast<const float*>(format);
	stream << std::fixed << std::setprecision(1) << value << "f";
	std::cout << stream.str() << std::endl;
}

void	printDouble(const void* format)
{
	std::stringstream stream;
	float value = *static_cast<const double*>(format);
	stream << std::fixed << std::setprecision(1) << value;
	std::cout << stream.str() << std::endl;
}

void printOneDecimal(const void* format, std::string token)
{
	std::string const matchArray[FORMAT_ARRAY] = {"float", "double"};
	FunctionArray formatArray[FORMAT_ARRAY] = {&printFloat, &printDouble};
	if (format == nullptr)
	{
		std::cout << ERROR_COLOR << "Invalid format provide"
									<< RESET_TEXT << std::endl;
		return ;
	}
	for(int i = 0; i < FORMAT_ARRAY; i++)
	{
		if (matchArray[i] == token)
		{
			formatArray[i](format);
			return ;
		}
	}
	std::cout << ERROR_COLOR << "Invalid format provide"
			  << RESET_TEXT << std::endl;
}

void convertInt(std::string const &input)
{
	char* endptr;
	int check = strtol(input.c_str(), &endptr, 10);
	std::cout << check << std::endl;
}

void convertFloat(std::string const &input)
{
	char* endptr;
	std::string validFormat;

	validFormat = input.substr(0, input.length() - 1);
	float check = strtof(validFormat.c_str(), &endptr);
	printOneDecimal(&check, "float");
}

void convertDouble(std::string const &input)
{
	char* endptr;
	double check = strtod(input.c_str(), &endptr);
	printOneDecimal(&check, "double");
}