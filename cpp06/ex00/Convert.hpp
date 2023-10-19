#pragma once

#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>

const char* const ERROR_COLOR = "\033[1;31m";
const char* const RESET_TEXT = "\033[0m";
#define FORMAT_ARRAY 3

class ScalarConverter
{
private:
		static int			_integer;
		static double		_double;
		static float		_float;
		static char 		_char;
		static std::string	_input;
public:
	ScalarConverter(std::string& input);
	ScalarConverter(const ScalarConverter &set);
	ScalarConverter& operator=(const ScalarConverter & cpy);
	static int 			getInteger();
	static double 		getDouble();
	static float 		getFloat();
	static char 		getChar();
	static std::string	getInput();
	~ScalarConverter();
	static	void	convert(std::string &input);

};

void convertInt(std::string const &input);
void convertFloat(std::string const &input);
void convertDouble(std::string const &input);
