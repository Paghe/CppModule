#include "BitcoinExchange.hpp"

Bitcoin::Bitcoin(std::string inputFile) : std::map<std::string, double>(), _inputFile(inputFile) {}

Bitcoin::Bitcoin(const Bitcoin &cpy) : std::map<std::string, double>(cpy), _inputFile(cpy._inputFile) {}

Bitcoin &Bitcoin::operator=(const Bitcoin &cpy)
{
	if (this != &cpy)
	{
		std::map<std::string, double>::operator=(cpy);
	}
	return (*this);
}

void Bitcoin::insertElement(std::string key, double value)
{
	(*this)[key] = value;
}

void 	Bitcoin::openFile()
{
	std::ifstream inputFile(this->_inputFile.c_str());
	if (!inputFile.is_open()) {
		std::cerr << "error: impossible to open this file" << std::endl;
		return;
	}
	std::string date, str, line;
	double value;
	while (getline(inputFile, line))
	{
		std::istringstream ss(line);
		if (getline(ss, date, ',') &&
				getline(ss, str, ','))
		{
			value = atof(str.c_str());
			insertElement(date, value);
		}
		else
		{
			std::cout << "Invalid format" << std::endl;
			return ;
		}
	}
}

Bitcoin::~Bitcoin() {}
