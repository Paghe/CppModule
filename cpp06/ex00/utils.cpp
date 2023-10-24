#include "Convert.hpp"

typedef void (*FunctionArray)(const void *format, std::string token);

typedef void (*CastArray)(const void *format);

void	castDoubleAscii(const void* format)
{
	if (!isprint(*static_cast<const int*>(format)))
	{
		std::cout << "Char: Non displayable"<< std::endl;
		return ;
	}
	const double value = *static_cast<const double*>(format);
   	char ascii = static_cast<char>(value);
	std::cout << "Char: " << ascii << std::endl;
}

void	castFloatAscii(const void* format)
{
	if (!isprint(*static_cast<const int*>(format)))
	{
		std::cout << "Char: Non displayable"<< std::endl;
		return ;
	}
	const float value = *static_cast<const float*>(format);
	char ascii = static_cast<char>(value);
	std::cout << "Char: " << ascii << std::endl;
}

void	castIntAscii(const void* format)
{
	if (!isprint(*static_cast<const int*>(format)))
	{
		std::cout << "Char: Non displayable"<< std::endl;
		return ;
	}
	const int value = *static_cast<const int*>(format);
	char ascii = static_cast<char>(value);
	std::cout << "Char: " << ascii << std::endl;
}

void	printChar(const void* format, std::string token)
{
	CastArray printCast[FORMAT_ARRAY] = {&castDoubleAscii, &castFloatAscii, &castIntAscii};
	std::string castMatch[FORMAT_ARRAY] = {"double", "float", "int"};
	for (int i = 0; i < FORMAT_ARRAY; i++)
	{
		if (castMatch[i] == token)
		{
			printCast[i](format);
			return ;
		}
	}
}

void	printFloat(const void* format, std::string token)
{
	printChar(format, token);
	std::stringstream stream;
	float value = *static_cast<const float*>(format);
	if (value <= -2147483648.0f ||  value >= 2147483647.0f)
	{
		std::cout << ERROR_COLOR << "Out of range" << RESET_TEXT << std::endl;
		return ;
	}
	stream << std::fixed << std::setprecision(1) <<"Float: " << value << "f";
	std::cout << stream.str() << std::endl;
}

void	printDouble(const void* format, std::string token)
{
	std::stringstream stream;
	double value = *static_cast<const double*>(format);
	stream << std::fixed << std::setprecision(1) <<"Double: " <<value;
	std::cout << stream.str() << std::endl;
	printChar(format, token);
}


void printDigit(const void* format, std::string token)
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

bool convertInt(std::string const &input)
{
	char* endptr;
	long long check = strtol(input.c_str(), &endptr, 10);
	if (check <= -2147483648 || check >= 2147483647)
	{
		std::cout << ERROR_COLOR << "Out of range" << RESET_TEXT << std::endl;
		return (false);
	}
	printChar(&check, "int");
	std::cout <<"Int: " << check << std::endl;
	intConvertToFloatAndDouble(check);
	return (true);
}

bool convertFloat(std::string const &input)
{
	char* endptr;
	std::string validFormat;

	validFormat = input.substr(0, input.length() - 1);
	float check = strtof(validFormat.c_str(), &endptr);
	if (check <= -2147483648.0 ||  check >= 2147483647.0)
	{
		std::cout << ERROR_COLOR << "Out of range" << RESET_TEXT << std::endl;
		return (false);
	}
	printDigit(&check, "float");
	FloatConvertToDoubleAndInt(check);
	return (true);
}

bool convertDouble(std::string const &input)
{
	char* endptr;
	double check = strtod(input.c_str(), &endptr);
	if (check <= -2147483648.0 ||  check >= 2147483647.0)
	{
		std::cout << ERROR_COLOR << "Out of range" << RESET_TEXT << std::endl;
		return (false);
	}
	printDigit(&check, "double");
	doubleConvertToFloatAndInt(check);
	return (true);
}

void	convertChar(std::string const &input)
{
	if (input.length() < 0 || input.length() > 1)
	{
		std::cout << ERROR_COLOR << "Provide only one char"
				  << RESET_TEXT << std::endl;
		return ;
	}
	char check = input[0];
	CharConvertToFloatAndInt(check);
}
