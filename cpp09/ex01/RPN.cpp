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

}

Rpn::~Rpn() {}