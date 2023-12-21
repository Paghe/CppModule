#include "RPN.hpp"

int main (int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "Invalid N of arguments " << "expected 2 "
					<< "provide " << argc << std::endl;
		return (0);
	}
	std::string input;
	for (int i = 1; i < argc ; i++)
	{

		input += argv[i];
		if (i < argc - 1)
			input += ' ';
	}
	Rpn MyTranslator(input);
	MyTranslator.addNode();
	return (0);
}
