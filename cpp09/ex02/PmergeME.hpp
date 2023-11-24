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
	public:
			MergeMe(std::string input);
			MergeMe(const MergeMe & cpy);
			MergeMe& operator=(MergeMe const & cpy);
			~MergeMe();
			void	pushMainVector();
			void	printPair(void);
			bool	duplicateNumber(std::vector<std::pair<int, int> > mainArray);
			void	sortPair();
};