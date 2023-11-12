#include "Array.hpp"

void 	leaks(void)
{
	system("leaks Array");
}

int main (void)
{
//	atexit(leaks);
	Array<int>ArrayInt(10);
	Array<std::string>ArrayString(42);
	try
	{
		unsigned int outRange = ArrayInt[11];
		std::cout << outRange << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::string outRangeStr = ArrayString[11];
		std::cout << outRangeStr << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}