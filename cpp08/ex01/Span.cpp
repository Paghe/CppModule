#include "Span.hpp"

Span::Span(unsigned int size) : _size(size) {}

Span::Span(const Span &cpy)
{
	this->_size = cpy._size;
	this->container = cpy.container;
}

Span &Span::operator=(const Span &cpy)
{
	this->_size = cpy._size;
	this->container = cpy.container;
	return (*this);
}

void Span::addNumber(int number)
{
	if (this->container.size() == this->_size)
	{
		throw sizeFull();
	}
	else
		this->container.push_back(number);
}


int	Span::shortestSpan()
{
	if (this->_size <= 1)
		throw StoreSize();
	std::list<int>::iterator value = this->container.begin();
	std::list<int>::iterator check = this->container.begin();
	std::advance(check, 1);
	int diff = std::abs(*value - *check);
	while (value != this->container.end())
	{
		check = this->container.begin();
		while (check != this->container.end() && check != value)
		{
			if (diff > std::abs(*value - *check))
				diff =  std::abs(*value - *check);
			check++;
		}
		value++;
	}
	return (diff);
}

int	Span::longestSpan()
{
	if (this->_size <= 1)
		throw StoreSize();
	std::list<int>::iterator value = this->container.begin();
	std::list<int>::iterator check = this->container.begin();
	std::advance(check, 1);
	int diff = std::abs(*value - *check);
	while (value != this->container.end())
	{
		check = this->container.begin();
		while (check != this->container.end() && check != value)
		{
			if (diff < std::abs(*value - *check))
				diff =  std::abs(*value - *check);
			check++;
		}
		value++;
	}
	return (diff);
}

void Span::addRangeIterator(unsigned int size)
{
	if (this->container.size() == this->_size)
	{
		throw sizeFull();
	}
	if (size > this->_size)
		std::cout << "Size too big" << std::endl;
	for (unsigned int i = 0; i < size; i++)
		addNumber(i);


}
Span::~Span() {}