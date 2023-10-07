#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat test("Mark", 150);
		test.decrementGrade();
		std::cout << test.getGrade() << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}