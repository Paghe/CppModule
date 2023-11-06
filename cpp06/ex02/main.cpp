#include "Base.hpp"

void	leaks(void)
{
	system("leaks Base");
}

int	main (void)
{
//	atexit(leaks);
	Base test;
	Base *check;
	check = test.generate();
	Base &ref = *check;
	test.identify(check);
	test.identify(ref);
	delete check;
	return (0);
}