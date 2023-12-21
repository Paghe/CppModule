m:#pragma once

#include <iostream>

template <typename Arg>

void	iter(Arg *first, size_t size, void (*f)(Arg))
{
	for (size_t i = 0 ; i < size; i++)
		f(first[i]);
	std::cout << std::endl;
}

template <typename Arg>

void printfArr(Arg array)
{
	std::cout << array << " ";
}
