#pragma once

#include <vector>
#include <string>
#include <sstream>
#include <iostream>

class MergeMe
{
	private:
			std::vector<std::pair<int, int> > _mainArray;
			std::string	_input;
			bool _straggler;
			std::vector<int> _mainChain;
			std::vector<int> _pendChain;
			std::pair<int, int> _lastPair;
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
};

void	merge(std::vector<std::pair<int, int> > &array);
void	mergeSortVector(std::vector<std::pair<int, int> > &arrayLeft,
					 std::vector<std::pair<int, int> > &arrayRight,
					 std::vector<std::pair<int, int> > &mainArray);