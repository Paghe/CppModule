#include "Convert.hpp"

int main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "Argument 1 expected 2" << std::endl;
	else
	{
		std::string	input(argv[1]);
		ScalarConverter test(input);
		test.convert(input);
	}
	return (0);
}