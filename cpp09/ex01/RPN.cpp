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

void Rpn::addNode()
{
	std::istringstream line(this->_input);
	int value;
	while  (line >> value)
	{
		this->_myStack.push(value);
		std::cout << this->_myStack.top() << std::endl;
	}
}

Rpn::~Rpn() {}