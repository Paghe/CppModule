#include "RPN.hpp"

int main (void)
{
	Rpn MyTranslator("1 2 + 3 - ");
	MyTranslator.addNode();
	return (0);
}
