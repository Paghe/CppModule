#include "iter.hpp"

int main (void)
{
	char arrayChar[] = {'a', 'b', 'c'};
	int arrayInt[] = {23,121, 42, 4343, 6};
	::iter(arrayChar, 3, printfArr);
	::iter(arrayInt, 3, printfArr);
	return (0);
}