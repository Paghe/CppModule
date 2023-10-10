#include "Bureaucrat.hpp"

int	main(void) {
	try
	{
		Bureaucrat Marcello("Marcello", 45);
		Form Constitution("Constitution", 45, 1);
		Constitution.beSigned(Marcello);
		Marcello.signForm(Constitution);
		std::cout << Constitution << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
