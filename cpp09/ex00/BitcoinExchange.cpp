#include "BitcoinExchange.hpp"

Bitcoin::Bitcoin(std::string inputFile) : std::map<std::string, int>(), _inputFile(inputFile) {}

Bitcoin::Bitcoin(const Bitcoin &cpy) : std::map<std::string, int>(cpy), _inputFile(cpy._inputFile) {}

Bitcoin &Bitcoin::operator=(const Bitcoin &cpy)
{
	if (this != &cpy)
	{
		std::map<std::string, int>::operator=(cpy);
	}
	return (*this);
}

void 	Bitcoin::openFile()
{
	std::ifstream inputFile(this->_inputFile.c_str());
	if (!inputFile.is_open()) {
		std::cerr << "error: impossible to open this file" << std::endl;
		return;
	}

}

Bitcoin::~Bitcoin() {}
