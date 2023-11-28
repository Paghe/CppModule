#include "PmergeME.hpp"

MergeMe::MergeMe(std::string input) : _input(input), _straggler(false) {}

MergeMe::MergeMe(const MergeMe &cpy) : _mainArray(cpy._mainArray), _input(cpy._input), _straggler(cpy._straggler){}

MergeMe& MergeMe::operator=(const MergeMe &cpy)
{
	if (this != &cpy)
	{
		this->_input = cpy._input;
		this->_mainArray = cpy._mainArray;
		this->_straggler = cpy._straggler;
	}
	return (*this);
}

void MergeMe::printPair()
{
	for(size_t i = 0; i < this->_mainArray.size(); i++)
	{
		std::cout << this->_mainArray[i].first << " ";
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
	if (this->_input.length() < 2)
	{
		std::cerr << "Digits are less than 2" << std::endl;
	}
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
 		this->_mainArray.push_back(std::make_pair(first, -1));
		this->_straggler = true;
	}
	if (duplicateNumber(this->_mainArray))
	{
		std::cerr << "Error: " << "duplicate numbers are not allowed" << std::endl;
		return ;
	}
}


void MergeMe::sortPair()
{
	for(size_t i = 0; i < this->_mainArray.size(); i++)
	{
		if (this->_mainArray[i].first > this->_mainArray[i].second)
		{
			std::swap(this->_mainArray[i].first, this->_mainArray[i].second);
		}
	}
	if (this->_straggler && !this->_mainArray.empty())
	{
		this->_lastPair = this->_mainArray.back();
		this->_mainArray.pop_back();
		merge(this->_mainArray);
	}
	else
		merge(this->_mainArray);
}

void merge(std::vector<std::pair<int, int> > &array)
{
	int size = array.size();
	if (size <= 1)
		return ;
	int mid = size / 2;
	int i = 0;
	std::vector<std::pair<int, int> > arrayLeft;
	std::vector<std::pair<int, int> > arrayRight;
	for(; i < size; i++)
	{
		if (i < mid)
			arrayLeft.push_back(array[i]);
		else
			arrayRight.push_back(array[i]);
	}
	merge(arrayLeft);
	merge(arrayRight);
	mergeSortVector(arrayLeft, arrayRight, array);
}

void mergeSortVector(std::vector<std::pair<int, int> > &arrayLeft,
			   	std::vector<std::pair<int, int> > &arrayRight,
				   std::vector<std::pair<int, int> > &mainArray)
{
	int leftSize = mainArray.size() / 2;
	int rightSize = mainArray.size() - leftSize;
	int left = 0;
	int right = 0;
	int i = 0;
	while (left < leftSize && right < rightSize)
	{
		if (arrayLeft[left].second < arrayRight[right].second)
		{
			mainArray[i] = arrayLeft[left];
			left++;
		}
		else
		{
			mainArray[i] = arrayRight[right];
			right++;
		}
		i++;
	}
	while (left < leftSize)
	{
		mainArray[i] = arrayLeft[left];
		left++;
		i++;
	}
	while (right < rightSize)
	{
		mainArray[i] = arrayRight[right];
		right++;
		i++;
	}
}

int jacobSthal(int n)
{
	if (n == 0)
		return (0);
	else if (n == 1)
		return (1);
	else
		return (jacobSthal(n - 1) + 2 * jacobSthal(n - 2));
}

void printChain(std::vector<int> chain)
{
	for (size_t i = 0; i < chain.size(); i++)
		std::cout << chain[i] << " ";
	std::cout << "\n";
}

void MergeMe::pushJacob()
{
	size_t jacob;
	size_t size = this->_pendChain.size() - 1;
	int i = 3;
	jacob = jacobSthal(i);
	while ((jacob = jacobSthal(i)) < size - 1)
	{
		this->_jacobNumber.push_back(jacob);
		i++;
	}
}

void MergeMe::buildChain()
{
	size_t i = 0;
	for (; i < this->_mainArray.size(); i++)
		this->_mainChain.push_back(this->_mainArray[i].second);
	for (i = 0; i < this->_mainArray.size(); i++)
		this->_pendChain.push_back(this->_mainArray[i].first);
	this->_mainChain.insert(this->_mainChain.begin(), this->_pendChain[0]);
	this->_pendChain.erase(this->_pendChain.begin());
}

void	MergeMe::jacobPlusIdx()
{
	size_t j;
	size_t prevPos = 1;
	for (size_t i = 0;  i < this->_jacobNumber.size(); i++)
	{
		size_t n = this->_jacobNumber.at(i);
		this->_combNumber.push_back(n);
		j = n - 1;
		while( j > prevPos)
		{
			this->_combNumber.push_back(j);
			j--;
		}
		prevPos = n;
	}
}

int	MergeMe::binarySearch(int n)
{
	int left = 0;
	int right = this->_mainChain.size() - 1;
	int mid = (left + right) / 2;
	pushJacob();
	jacobPlusIdx();
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (n > this->_mainChain[mid])
			left = mid + 1;
		else
			right = mid - 1;
	}
	if (n > this->_mainChain[mid])
		return (mid + 1);
	else
		return (mid);
}


void	MergeMe::insertNumber()
{
	if (this->_pendChain.size() == 1)
		binarySearch(this->_pendChain[0]);
	int pos;
	for (size_t i = 0; i < this->_pendChain.size(); i++)
	{
		pos = binarySearch(this->_pendChain[i]);
		this->_mainChain.insert(this->_mainChain.begin() + pos, this->_pendChain[i]);
	}
	if (this->_straggler)
	{
		pos = binarySearch(this->_lastPair.second);
		this->_mainChain.insert(this->_mainChain.begin() + pos, this->_lastPair.second);
	}
	printChain(this->_mainChain);
}

MergeMe::~MergeMe() {}