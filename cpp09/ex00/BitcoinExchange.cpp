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

double Bitcoin::getDataValue(std::string key)
{
	std::map<std::string, double>::iterator it = find(key);
	if (it != end())
		return (it->second);
	else
	{
		std::map<std::string, double>::iterator it = lower_bound(begin(), end(), key);
		std::cout << "FOUND" << it->second <<  std::endl;
		return (it->second);
	}
	return (-1);
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

void Bitcoin::calcValueMultiplied(const std::string valueFile)
{
	std::ifstream inputFile(valueFile);
	if (!inputFile.is_open())
	{
		std::cerr << "error: impossible to open this file" << std::endl;
		return;
	}
	std::string date, str, line;
	double value;
	double dataValue;
	while (getline(inputFile, line))
	{
		std::istringstream ss(line);
		if (getline(ss, date, '|') &&
			getline(ss, str, '|'))
		{
			value = atof(str.c_str());
			dataValue = getDataValue(date);
			/*std::cout << "DATE ---> " << date << std::endl;
			std::cout << "DATABASE VALUE ---> " << dataValue << std::endl;
			std::cout << "FILE VALUE ---> " << value << std::endl;*/
			if (dataValue == -1)
				std::cout << "No has been found on the database" << std::endl;
			std::cout << "VALUE MULTIPLIED " << value * dataValue << std::endl;
		}
		else
		{
			std::cout << "Invalid format" << std::endl;
			return ;
		}
	}
}

Bitcoin::~Bitcoin() {}
