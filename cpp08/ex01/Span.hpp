#pragma once

#include <list>
#include <vector>
#include  <iostream>
#include "exception"

class Span
{
private:
	unsigned int _size;
	std::list<int> container;
public:
class StoreSize : public std::exception
{
public:
	virtual const char* what() const throw()
	{
		return("Please provide more values before run this function (at least 2)");
	}
};
class sizeFull : public std::exception
		{
public:
	virtual const char* what() const throw()
	{
		return("Array full");
	}
};
	Span(unsigned int size);
	Span(const Span & cpy);
	Span& operator=(Span const & cpy);
	void	addNumber(int number);
	int		shortestSpan();
	int		longestSpan();
	void 	addRangeIterator(unsigned int size);
	~Span();

};