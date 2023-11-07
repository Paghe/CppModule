#include "whatever.hpp"

int main (void)
{
	int	a = 10;
	int b = 50;
	int min = ::min(a, b);
	int max = ::max(a, b);
	::swap(a, b);
	std::cout << "SWAP ---> " << a << std::endl;
	std::cout << "SWAP ---> " << b << std::endl;
	std::cout << "MIN ---> " << min << std::endl;
	std::cout << "MAX ---> " << max << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	return (0);
}