#include "RPN.hpp"

Rpn::Rpn(std::string input) : _input(input) {}

Rpn::Rpn(const Rpn &cpy) : _myStack(cpy._myStack), _input(cpy._input) {}

Rpn &Rpn::operator=(const Rpn &cpy)
{
	if (this != &cpy)
	{
		this->_input = cpy._input;
		this->_myStack = cpy._myStack;
	}
	return (*this);
}
void Rpn::sumOperator()
{
	int first;
	int second;

	second = this->_myStack.top();
	this->_myStack.pop();
	first = this->_myStack.top();
	this->_myStack.pop();
	this->_myStack.push(first + second);
}

void	Rpn::subOperator()
{
	int first;
	int second;

	second = this->_myStack.top();
	this->_myStack.pop();
	first = this->_myStack.top();
	this->_myStack.pop();
	this->_myStack.push(first - second);
}

void Rpn::multOperator()
{
	int first;
	int second;

	second = this->_myStack.top();
	this->_myStack.pop();
	first = this->_myStack.top();
	this->_myStack.pop();
	this->_myStack.push(first * second);
}

void Rpn::divOperator()
{
	int first;
	int second;

	second = this->_myStack.top();
	this->_myStack.pop();
	first = this->_myStack.top();
	this->_myStack.pop();
	if (second == 0)
		std::cerr << "Error: division by zero\n";
	else
		this->_myStack.push(first / second);
}

int	Rpn::calcOperator(std::string token)
{
	if (this->_myStack.size() >= 2)
	{
		if (token == "+")
			sumOperator();
		else if (token == "-")
			subOperator();
		else if (token == "*")
			multOperator();
		else if (token == "/")
			divOperator();
		return (1);
	}
	return (0);
}

void Rpn::addNode()
{
	std::istringstream line(this->_input);
	std::string str;
	while  (line >> str)
	{
		std::istringstream number(str);
		int value;
		if (number >> value)
			this->_myStack.push(value);
		else
		{
			if (!calcOperator(str))
			{
				std::cout << "Invalid format provide" << std::endl;
				return ;
			}
		}
	}
	if (this->_myStack.size() != 1)
		std::cerr << "Bad format provide" << std::endl;
	else
		std::cout << this->_myStack.top() << std::endl;
}

Rpn::~Rpn() {}