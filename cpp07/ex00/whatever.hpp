#pragma once

#include <iostream>

template <typename Arg>

void swap(Arg &first, Arg &second)
{
	if (first != second)
	{
		Arg tmp = first;
		first = second;
		second = tmp;
	}
	else
		return ;
}

template <typename Arg>

Arg	min(Arg &first, Arg &second)
{
	if (first > second)
		return (second);
	else if (first  < second)
		return (first);
	else
		return (second);
}

template <typename Arg>

Arg	max(Arg &first, Arg &second)
{
	if (first < second)
		return (second);
	else if (first  > second)
		return (first);
	else
		return (second);
}