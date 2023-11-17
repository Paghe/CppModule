#pragma once
#include <iostream>
#include <map>
#include <fstream>
#include <string>

class Bitcoin : std::map<std::string, int>
{
private:
		std::string _inputFile;
public:
		Bitcoin(std::string inputFile);
		Bitcoin(const Bitcoin &cpy);
		Bitcoin& operator=(Bitcoin const & cpy);
		void openFile(void);
		~Bitcoin();
};