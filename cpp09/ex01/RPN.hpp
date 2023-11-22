#pragma once

#include <stack>
#include <sstream>
#include <string>
#include <iostream>

class Rpn
{
private:
	std::stack<int>_myStack;
	std::string _input;
public:
	Rpn(std::string input);
	Rpn(const Rpn & cpy);
	Rpn& operator=(Rpn const & cpy);
	void	addNode();
	void	sumOperator();
	void	subOperator();
	void	multOperator();
	void	divOperator();
	int		calcOperator(std::string token);
	~Rpn();
};
