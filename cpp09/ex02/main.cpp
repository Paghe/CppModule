#include "PmergeME.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Invalid N of argument provided " << argc << " expected 2" << std::endl;
		return (0);
	}
	std::string input = argv[1];
	MergeMe test(input);
	test.pushMainVector();
	test.sortPair();
	test.buildChain();
	return (0);
}