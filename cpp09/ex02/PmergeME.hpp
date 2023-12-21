#pragma once

#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <deque>
#include <sys/time.h>
#include <iomanip>

class MergeMe
{
	private:
			std::vector<std::pair<int, int> > _mainArray;
			std::string	_input;
			bool _straggler;
			std::vector<int> _mainChain;
			std::vector<int> _pendChain;
			std::vector<int> _jacobNumber;
			std::pair<int, int> _lastPair;
			std::vector<int> _combNumber;

	public:
			MergeMe(std::string input);
			MergeMe(const MergeMe & cpy);
			MergeMe& operator=(MergeMe const & cpy);
			~MergeMe();
			void	pushMainVector();
			void	printPair();
			bool	duplicateNumber(std::vector<std::pair<int, int> > mainArray);
			void	sortPair();
			void	buildChain();
			void 	pushJacob();
			void	jacobPlusIdx();
			int		binarySearch(int n);
			void	insertNumber();
			int 	checkSort();
			void	fordJohnson();
};

void	merge(std::vector<std::pair<int, int> > &array);
void	mergeSortVector(std::vector<std::pair<int, int> > &arrayLeft,
					 std::vector<std::pair<int, int> > &arrayRight,
					 std::vector<std::pair<int, int> > &mainArray);


class MergeMeDeque
{
private:
	std::deque<std::pair<int, int> > _mainArray;
	std::string	_input;
	bool _straggler;
	std::deque<int> _mainChain;
	std::deque<int> _pendChain;
	std::deque<int> _jacobNumber;
	std::pair<int, int> _lastPair;
	std::deque<int> _combNumber;

public:
	MergeMeDeque(std::string input);
	MergeMeDeque(const MergeMeDeque & cpy);
	MergeMeDeque& operator=(MergeMeDeque const & cpy);
	~MergeMeDeque();
	void	pushMainVector();
	void	printPair();
	bool	duplicateNumber(std::deque<std::pair<int, int> > mainArray);
	void	sortPair();
	void	buildChain();
	void 	pushJacob();
	void	jacobPlusIdx();
	int		binarySearch(int n);
	void	insertNumber();
	int 	checkSort();
	void	fordJohnson();
};

void	mergeDeque(std::deque<std::pair<int, int> > &array);
void	mergeSortDeque(std::deque<std::pair<int, int> > &arrayLeft,
						std::deque<std::pair<int, int> > &arrayRight,
						std::deque<std::pair<int, int> > &mainArray);