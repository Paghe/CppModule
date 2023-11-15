#pragma once

#include <list>
#include <iostream>
#include "stdexcept"

class ValueError : public std::exception
{
public:
	virtual const char* what() const throw()
	{
		return ("Value not found!");
	}
};

template <typename T>
void	easyfind(T &container, int i)
{
	typename T::iterator it = container.begin();
	while (it != container.end()) {
		if (*it == i) {
			std::cout << "Value inside the list" << std::endl;
			return;
		}
		it++;
	}
	throw ValueError();
}