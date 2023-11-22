#include "RPN.hpp"

int main (int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Invalid N of arguments " << "expected 2 "
					<< "provide " << argc << std::endl;
		return (0);
	}
	std::string input = argv[1];
	Rpn MyTranslator(input);
	MyTranslator.addNode();
	return (0);
}
