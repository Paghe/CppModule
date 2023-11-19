#pragma once
#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <sstream>


class Bitcoin : std::map<std::string, double>
{
private:
		std::string _inputFile;
public:
		Bitcoin(std::string inputFile);
		Bitcoin(const Bitcoin &cpy);
		Bitcoin& operator=(Bitcoin const & cpy);
		void	insertElement(std::string key, double value);
		void	openFile(void);
		double getDataValue(std::string key);
		void	calcValueMultiplied(const std::string valueFile);
		~Bitcoin();
};