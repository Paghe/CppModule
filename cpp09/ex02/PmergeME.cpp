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
		if (this->_mainArray[i].first >= 0)
			std::cout << this->_mainArray[i].first << " ";
		if (this->_mainArray[i].second >= 0)
			std::cout << this->_mainArray[i].second << " ";
	}
	std::cout << "\n";
	std::cout << "\n";
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
		exit(1);
	}
	for (size_t i = 0; i < this->_input.length(); i++)
	{
		if (line >> value)
		{
			if (value < 0)
			{
				std::cerr << "Error: negatives numbers are not allowed\n";
				exit(1) ;
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
			exit(1);
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
		exit(1);
	}
	std::cout << "\n";
	std::cout << "Before: ";
	printPair();
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
	std::cout << "\n";
}

void MergeMe::pushJacob()
{
	size_t jacob;
	size_t size = this->_pendChain.size();
	int i = 3;
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
}

void	MergeMe::jacobPlusIdx()
{
	size_t j;
	size_t n = 1;
	size_t prevPos = 1;
	for (size_t i = 0;  i < this->_jacobNumber.size(); i++)
	{
		n = this->_jacobNumber.at(i);
		this->_combNumber.push_back(n);
		j = n - 1;
		while( j > prevPos)
		{
			this->_combNumber.push_back(j);
			j--;
		}
		prevPos = n;
	}
	if (n < this->_pendChain.size())
	{
		for (; n < this->_pendChain.size(); n++)
			this->_combNumber.push_back(n);
	}
}

int	MergeMe::binarySearch(int n)
{
	int left = 0;
	int right = this->_mainChain.size() - 1;
	int mid = (left + right) / 2;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (n > this->_mainChain.at(mid))
			left = mid + 1;
		else
			right = mid - 1;
	}
	if (n > this->_mainChain.at(mid))
		return (mid + 1);
	else
		return (mid);
}


void	MergeMe::insertNumber()
{
	int pos;
	if (this->_pendChain.size() == 1)
	{

		pos = binarySearch(this->_pendChain[0]);
		this->_mainChain.insert(this->_mainChain.begin() + pos, this->_pendChain[0]);
		if (this->_straggler)
		{
			pos = binarySearch(this->_lastPair.second);
			this->_mainChain.insert(this->_mainChain.begin() + pos, this->_lastPair.second);
		}
		std::cout << "After using vector: ";
		printChain(this->_mainChain);
		return ;
	}
	pushJacob();
	jacobPlusIdx();
	int idx;
	for (size_t i = 0; i < this->_combNumber.size(); i++)
	{
		idx = this->_combNumber[i] - 1;
		pos = binarySearch(this->_pendChain[idx]);
		this->_mainChain.insert(this->_mainChain.begin() + pos, this->_pendChain[idx]);
	}
	if (this->_straggler)
	{
		pos = binarySearch(this->_lastPair.second);
		this->_mainChain.insert(this->_mainChain.begin() + pos, this->_lastPair.second);
	}
	std::cout << "After using vector: ";
	printChain(this->_mainChain);
}



int	MergeMe::checkSort()
{
	std::vector<int>::iterator it = this->_mainChain.begin();
	int i = 1;
	while (it != this->_mainChain.end())
	{
		std::vector<int>::iterator it2 = this->_mainChain.begin() + i;
		while (it2 != this->_mainChain.end())
		{
			if (*it > *it2)
			{
				std::cout << "KO!" << std::endl;
				return(0);
			}
			it2++;
		}
		it++;
		i++;
	}
	std::cout << "OK!" << std::endl;
	return (1);
}

void MergeMe::fordJohnson()
{
	pushMainVector();
	timeval start, end;
	gettimeofday(&start, NULL);
	sortPair();
	buildChain();
	insertNumber();
	gettimeofday(&end, NULL);
	unsigned long long micro = static_cast<unsigned long long> (1000000 * (end.tv_sec - start.tv_sec)
																+ end.tv_usec - start.tv_usec);
	double microSec = static_cast<double>(micro);
	std::cout << "Time to process a range of " << this->_mainChain.size() <<" elements with vector: " << microSec << "us" << std::endl;
}

MergeMe::~MergeMe() {}

// ---------------------------- DEQUE ----------------------------

MergeMeDeque::MergeMeDeque(std::string input) : _input(input), _straggler(false) {}

MergeMeDeque::MergeMeDeque(const MergeMeDeque &cpy) : _mainArray(cpy._mainArray), _input(cpy._input), _straggler(cpy._straggler){}

MergeMeDeque& MergeMeDeque::operator=(const MergeMeDeque &cpy)
{
	if (this != &cpy)
	{
		this->_input = cpy._input;
		this->_mainArray = cpy._mainArray;
		this->_straggler = cpy._straggler;
	}
	return (*this);
}

void MergeMeDeque::printPair()
{
	for(size_t i = 0; i < this->_mainArray.size(); i++)
	{
		if (this->_mainArray[i].first >= 0)
			std::cout << this->_mainArray[i].first << " ";
		if (this->_mainArray[i].second >= 0)
			std::cout << this->_mainArray[i].second << " ";
	}
	std::cout << "\n";
	std::cout << "\n";
}

bool MergeMeDeque::duplicateNumber(std::deque<std::pair<int, int> > mainArray)
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

void MergeMeDeque::pushMainVector()
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
		exit(1);
	}
	for (size_t i = 0; i < this->_input.length(); i++)
	{
		if (line >> value)
		{
			if (value < 0)
			{
				std::cerr << "Error: negatives numbers are not allowed\n";
				exit(1) ;
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
			exit(1);
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
		exit(1);
	}
	std::cout << "\n";
	std::cout << "Before: ";
	printPair();
}


void MergeMeDeque::sortPair()
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
		mergeDeque(this->_mainArray);
	}
	else
		mergeDeque(this->_mainArray);
}

void mergeDeque(std::deque<std::pair<int, int> > &array)
{
	int size = array.size();
	if (size <= 1)
		return ;
	int mid = size / 2;
	int i = 0;
	std::deque<std::pair<int, int> > arrayLeft;
	std::deque<std::pair<int, int> > arrayRight;
	for(; i < size; i++)
	{
		if (i < mid)
			arrayLeft.push_back(array[i]);
		else
			arrayRight.push_back(array[i]);
	}
	mergeDeque(arrayLeft);
	mergeDeque(arrayRight);
	mergeSortDeque(arrayLeft, arrayRight, array);
}

void mergeSortDeque(std::deque<std::pair<int, int> > &arrayLeft,
					 std::deque<std::pair<int, int> > &arrayRight,
					 std::deque<std::pair<int, int> > &mainArray)
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

void printChain(std::deque<int> chain)
{
	for (size_t i = 0; i < chain.size(); i++)
		std::cout << chain[i] << " ";
	std::cout << "\n";
	std::cout << "\n";
}

void MergeMeDeque::pushJacob()
{
	size_t jacob;
	size_t size = this->_pendChain.size();
	int i = 3;
	while ((jacob = jacobSthal(i)) < size - 1)
	{
		this->_jacobNumber.push_back(jacob);
		i++;
	}
}

void MergeMeDeque::buildChain()
{
	size_t i = 0;
	for (; i < this->_mainArray.size(); i++)
		this->_mainChain.push_back(this->_mainArray[i].second);
	for (i = 0; i < this->_mainArray.size(); i++)
		this->_pendChain.push_back(this->_mainArray[i].first);
	this->_mainChain.insert(this->_mainChain.begin(), this->_pendChain[0]);
}

void	MergeMeDeque::jacobPlusIdx()
{
	size_t j;
	size_t n = 1;
	size_t prevPos = 1;
	for (size_t i = 0;  i < this->_jacobNumber.size(); i++)
	{
		n = this->_jacobNumber.at(i);
		this->_combNumber.push_back(n);
		j = n - 1;
		while( j > prevPos)
		{
			this->_combNumber.push_back(j);
			j--;
		}
		prevPos = n;
	}
	for (;n < this->_pendChain.size(); ++n)
			this->_combNumber.push_back(n + 1);
}

int	MergeMeDeque::binarySearch(int n)
{
	int left = 0;
	int right = this->_mainChain.size() - 1;
	int mid = (left + right) / 2;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (n > this->_mainChain.at(mid))
			left = mid + 1;
		else
			right = mid - 1;
	}
	if (n > this->_mainChain.at(mid))
		return (mid + 1);
	else
		return (mid);
}


void	MergeMeDeque::insertNumber()
{
	int pos;
	if (this->_pendChain.size() == 2)
	{
		pos = binarySearch(this->_pendChain[1]);
		this->_mainChain.insert(this->_mainChain.begin() + pos, this->_pendChain[1]);
		if (this->_straggler)
		{
			pos = binarySearch(this->_lastPair.second);
			this->_mainChain.insert(this->_mainChain.begin() + pos, this->_lastPair.second);
		}
		std::cout << "After using deque: ";
		printChain(this->_mainChain);
		return ;
	}
	pushJacob();
	jacobPlusIdx();
	int	number;
	std::deque<int>::iterator it = this->_combNumber.begin();
	for (; it < this->_combNumber.end(); it++)
	{
		number = this->_pendChain.at(*it - 1);
		pos = binarySearch(number);
		this->_mainChain.insert(this->_mainChain.begin() + pos, number);
	}
	if (this->_straggler)
	{
		pos = binarySearch(this->_lastPair.second);
		this->_mainChain.insert(this->_mainChain.begin() + pos, this->_lastPair.second);
	}
	std::cout << "After using deque: ";
	printChain(this->_mainChain);
}



int	MergeMeDeque::checkSort()
{
	std::deque<int>::iterator it = this->_mainChain.begin();
	int i = 1;
	while (it != this->_mainChain.end())
	{
		std::deque<int>::iterator it2 = this->_mainChain.begin() + i;
		while (it2 != this->_mainChain.end())
		{
			if (*it > *it2)
			{
				std::cout << "KO!" << std::endl;
				return(0);
			}
			it2++;
		}
		it++;
		i++;
	}
	std::cout << "OK!" << std::endl;
	return (1);
}

void MergeMeDeque::fordJohnson()
{
	pushMainVector();
	timeval start, end;
	gettimeofday(&start, NULL);
	sortPair();
	buildChain();
	insertNumber();
	gettimeofday(&end, NULL);
	unsigned long long micro = static_cast<unsigned long long> (1000000 * (end.tv_sec - start.tv_sec)
																	+ end.tv_usec - start.tv_usec);
	double microSec = static_cast<double>(micro);
	std::cout << "Time to process a range of " << this->_mainChain.size() <<" elements with deque: " << microSec << "us" << std::endl;
}

MergeMeDeque::~MergeMeDeque() {}