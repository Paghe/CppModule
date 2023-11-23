#include "PmergeME.hpp"

MergeMe::MergeMe(std::string input) : _input(input) {}

MergeMe::MergeMe(const MergeMe &cpy) : _mainArray(cpy._mainArray), _input(cpy._input){}

MergeMe& MergeMe::operator=(const MergeMe &cpy)
{
	if (this != &cpy)
	{
		this->_input = cpy._input;
		this->_mainArray = cpy._mainArray;
	}
	return (*this);
}

void MergeMe::pushMainVector()
{
	std::istringstream line(this->_input);
	int value;
	std::string str;
	for (size_t i = 0; i < this->_input.length(); i++)
	{
		if (line >> value)
		{
			if (value < 0)
				std::cerr << "Error: negative numbers are not allowed\n";
			else
				this->_mainArray.push_back(value);
		}
	}
}