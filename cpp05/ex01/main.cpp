#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat Mark("Mark", 148);
		Bureaucrat Andrei("Andrei", 1);
		Bureaucrat default2(1);
		Andrei = Mark;
		std::cout << Andrei << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
