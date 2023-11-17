#pragma once

#include <stack>
#include <iostream>
template <typename T>

class MutantStack : public std::stack<T>
{
	public:
			MutantStack() : std::stack<T>() {};
			MutantStack(const MutantStack<T>  & cpy): std::stack<T>(cpy) {};
			~MutantStack() {};
			MutantStack& operator=(MutantStack<T> const &cpy)
			{
				if (this != cpy) // check with addres
				{
					std::stack<T>::operator=(cpy);
				}
				return (*this);
			}
			typedef typename std::stack<T>::container_type::iterator iterator;
			iterator begin()
			{
				return (std::stack<T>::c.begin());
			}
			iterator end()
			{
				return (std::stack<T>::c.end());
			}
};
