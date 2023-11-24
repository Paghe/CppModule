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

void MergeMe::printPair()
{
	for(size_t i = 0; i < this->_mainArray.size(); i++)
	{
		std::cout << this->_mainArray[i].first << "\n";
		std::cout << this->_mainArray[i].second << std::endl;
	}
}

bool MergeMe::duplicateNumber(std::vector<std::pair<int, int> > mainArray)
{
	for(size_t i = 0; i < mainArray.size(); i++)
	{
		for(size_t j = i + 1; j < mainArray.size(); j++)
		{
			if (mainArray[i].first == mainArray[j].first)
				return (true);
			else if (mainArray[i].first == mainArray[j].second)
				return (true);
			else if (mainArray[i].second == mainArray[j].first)
				return (true);
			else if (mainArray[i].second == mainArray[j].second)
				return (true);
			else if (mainArray[i].first == mainArray[i].second)
				return (true);
		}
	}
	return (false);
}

void MergeMe::pushMainVector()
{
	std::istringstream line(this->_input);
	std::string str;
	int value;
	int count = 0;
	int first = 0;
	int second = 0;
	for (size_t i = 0; i < this->_input.length(); i++)
	{
		if (line >> value)
		{
			if (value < 0)
			{
				std::cerr << "Error: negatives numbers are not allowed\n";
				return ;
			}
			else
			{
				count++;
				if (count == 1)
					first = value;
				else if (count == 2)
				{
					second = value;
					count = 0;
					this->_mainArray.push_back(std::make_pair(first,second));
				}
			}
		}
		else if (line.fail() && !line.eof())
		{
			line.clear();
			line >> str;
			std::cerr <<  "Error: " << "\"" << str << "\"" << " is not a digit\n";
			return ;
		}
	}
	if (count == 1)
	{
		std::cout << "straggler ----> " << first << std::endl;
 		this->_mainArray.push_back(std::make_pair(first, -1));
	}
	if (duplicateNumber(this->_mainArray))
	{
		std::cerr << "Error: " << "duplicate numbers are not allowed" << std::endl;
		return ;
	}
	printPair();
}