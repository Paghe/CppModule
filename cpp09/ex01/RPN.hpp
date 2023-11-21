#pragma once

#include <stack>
#include <string>

class Rpn
{
private:
	std::stack<int>_myStack;
	std::string _input;
public:
	Rpn(std::string input);
	Rpn(const Rpn & cpy);
	Rpn& operator=(Rpn const & cpy);
	void addNode();
	~Rpn();
};
