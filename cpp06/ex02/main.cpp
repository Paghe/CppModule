#include "Base.hpp"

int	main (void)
{
	Base test;
	Base *check;
	check = test.generate();
	Base &ref = *check;
	test.identify(check);
	test.identify(ref);
	return (0);
}