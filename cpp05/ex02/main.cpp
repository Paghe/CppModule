#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int	main(void) {
	try
	{
		Bureaucrat Marcello("Marcello", 137);
		ShrubberyCreationForm test("Three");
		test.beSigned(Marcello);
		test.execute(Marcello);
		Bureaucrat Alberto("Alberto", 45);
		RobotomyRequestForm test1("Three");
		test.beSigned(Marcello);
		test1.beSigned(Alberto);
		test.execute(Marcello);
		test1.execute((Alberto));
		Marcello.executeForm(test);
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
