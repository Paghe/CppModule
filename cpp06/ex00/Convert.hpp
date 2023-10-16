#pragma once

#include <string>
#include <iostream>


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

