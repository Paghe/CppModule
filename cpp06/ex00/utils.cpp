#include "Convert.hpp"

typedef void (*FunctionArray)(const void *format, std::string token);

typedef void (*CastArray)(const void *format);

void	castDouble(const void* format)
{
	const double value = *static_cast<const double*>(format);
	char ascii = static_cast<char>(value);
	std::cout << ascii << std::endl;
}

void	castFloat(const void* format)
{
	const float value = *static_cast<const float*>(format);
	char ascii = static_cast<char>(value);
	std::cout << ascii << std::endl;
}

void	castInt(const void* format)
{
	const int value = *static_cast<const int*>(format);
	char ascii = static_cast<char>(value);
}

void	printChar(const void* format, std::string token)
{
	CastArray printCast[3] = {&castDouble, &castFloat, &castInt};
	std::string castMatch[3] = {"double", "float", "int"};
	for (int i = 0; i < 3; i++)
	{
		if (token == castMatch[i])
		{
			printCast[i](format);
			return ;
		}
	}
}

void	printFloat(const void* format, std::string token)
{
	std::stringstream stream;
	float value = *static_cast<const float*>(format);
	stream << std::fixed << std::setprecision(1) << value << "f";
	std::cout << stream.str() << std::endl;
	printChar(format, token);
}

void	printDouble(const void* format, std::string token)
{
	std::stringstream stream;
	float value = *static_cast<const double*>(format);
	stream << std::fixed << std::setprecision(1) << value;
	std::cout << stream.str() << std::endl;
	printChar(format, token);
}

void printOneDecimal(const void* format, std::string token)
{
	std::string const matchArray[FORMAT_ARRAY] = {"float", "double", "char"};
	FunctionArray formatArray[FORMAT_ARRAY] = {&printFloat, &printDouble, &printChar};
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
			formatArray[i](format,token);
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
	printChar(&check, "int");
}

void convertFloat(std::string const &input)
{
	char* endptr;
	std::string validFormat;

	validFormat = input.substr(0, input.length() - 1);
	float check = strtof(validFormat.c_str(), &endptr);
	printOneDecimal(&check, "float");
	printOneDecimal(&check, "char");
}

void convertDouble(std::string const &input)
{
	char* endptr;
	double check = strtod(input.c_str(), &endptr);
	printOneDecimal(&check, "double");
}