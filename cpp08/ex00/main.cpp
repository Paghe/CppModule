#include "easyfind.hpp"

int main(void)
{
	try
	{
		std::list<int>container;
		container.push_back(2);
		container.push_back(5);
		easyfind(container, 5);
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}