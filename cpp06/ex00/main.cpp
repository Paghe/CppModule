#include "Convert.hpp"

void leaks(void)
{
	system("leaks convert");
}

int main(int argc, char **argv)
{
//	atexit(leaks);
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
		if (!test.checkInputErrors())
			return (1);
		else
			test.convert(input);
	}
	return (0);
}