#include "Span.hpp"

int main (void)
{
	Span sp (5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	Span sp1(10000);
	sp1.addRangeIterator(10000);
	return (0);
}