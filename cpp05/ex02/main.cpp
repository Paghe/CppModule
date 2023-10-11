#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
int	main(void) {
	try
	{
		Bureaucrat Marcello("Marcello", 137);
		ShrubberyCreationForm test("Three");
		test.beSigned(Marcello);
		test.execute(Marcello);
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
