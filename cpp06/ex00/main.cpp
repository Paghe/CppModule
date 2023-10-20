#include "Convert.hpp"

int main(int argc, char **argv)
{
 	if (argc != 2)
	{
		std::cerr << ERROR_COLOR << "Argument " << argc << " expected 2"
				  << RESET_TEXT << std::endl;
		return (1);
	}
	else
	{
		std::string	input(argv[1]);
		ScalarConverter test(input);
		test.convert(input);
	}
	return (0);
}