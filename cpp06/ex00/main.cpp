#include "Convert.hpp"

int main(int argc, char **argv)
{
	if (argc == 1)
		std::cerr << ERROR_COLOR << "Argument 1 expected 2"
								<< RESET_TEXT << std::endl;
	else if (argc > 2)
		std::cerr << ERROR_COLOR << "Argument " << argc << " expected 2"
				  << RESET_TEXT << std::endl;
	else
	{
		std::string	input(argv[1]);
		ScalarConverter test(input);
		test.convert(input);
	}
	return (0);
}