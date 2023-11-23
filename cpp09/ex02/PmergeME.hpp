#pragma once

#include <vector>
#include <string>
#include <sstream>
#include <iostream>

class MergeMe
{
	private:
			std::vector<int> _mainArray;
			std::string	_input;
	public:
			MergeMe(std::string input);
			MergeMe(const MergeMe & cpy);
			MergeMe& operator=(MergeMe const & cpy);
			void pushMainVector();
};