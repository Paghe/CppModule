#include "easyfind.hpp"

int main(void)
{
	try
	{
		std::list<int>container;
		container.push_back(2);
		easyfind(container, 2);
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}