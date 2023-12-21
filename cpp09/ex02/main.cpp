#include "PmergeME.hpp"

void leaks(void)
{
	system("leaks PmergeMe");
}

int	main(int argc, char **argv)
{
//	atexit(leaks);
	if (argc < 2)
	{
		std::cerr << "Invalid N of argument provided: " << argc << " expected 2" << std::endl;
		return (0);
	}
	std::string input;
	for(int i = 1; i < argc; i++)
	{
		input += argv[i];
		if (i < argc - 1)
			input += ' ';
	}
	MergeMe test(input);
	MergeMeDeque test1(input);
	std::cout << "\n";
	std::cout << "\n";
	test.fordJohnson();
	std::cout << "\n";
	std::cout << "\n";
	test1.fordJohnson();
	std::cout << "\n";
	std::cout << "------------ VECTOR ------------" << "\n";
	test.checkSort();
	std::cout << "\n";
	std::cout << "------------ DEQUE ------------" << "\n";
	test1.checkSort();
	return (0);
}