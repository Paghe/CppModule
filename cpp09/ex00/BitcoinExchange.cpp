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
	std::map<std::string, double>::iterator it = this->find(key);
	if (it != end())
		return (it->second);
	else
	{
		std::map<std::string, double>::iterator it = this->lower_bound(key);
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
			value  = atof(str.c_str());
			insertElement(date, value);
		}
		else
		{
			std::cout << "Invalid format" << std::endl;
			return ;
		}
	}
}

int	splitStr(std::string str, char delimiter)
{
	std::istringstream split(str);
	std::string splittedValueFirst, splittedValueSecond, splittedValueThird;
	while (getline(split, splittedValueFirst, delimiter) &&
			getline(split, splittedValueSecond, delimiter) &&
			getline(split, splittedValueThird, delimiter))
	if (splittedValueSecond[0] >= '4' || (splittedValueSecond[0] == '3' && splittedValueSecond[0] >= '2'))
		return (-1);
	else if (splittedValueThird[0] >= '2' || (splittedValueSecond[0] == '1' && splittedValueSecond[0] >= '3'))
		return (-1);
	return (0);
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
			if (value < 0)
			{
				std::cerr << "Negative number are not allowed\n";
				continue ;
			}
			else if (value > 1000)
			{
				std::cerr << "Error: too large a number\n";
				continue ;
			}
			if (splitStr(date, '-') == -1)
			{
				std::cout << "Wrond Date: " << date << std::endl;
				continue ;
			}
			dataValue = getDataValue(date);
			if (dataValue == -1)
			{
				std::cout << "No data has been found on the database" << std::endl;
				continue ;
			}
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
