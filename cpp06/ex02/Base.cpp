#include "Base.hpp"

Base::Base(){}

Base * Base::generate(void)
{
	int random;
	std::srand(time(0));
	random = std::rand() % 3;
	switch (random)
	{
		case 0:
		{
			return (new A);
		}
		case 1:
		{
			return (new B);
		}
		case 2:
		{
			return (new C);
		}
		default:
			return (nullptr);
	}
}
void	Base::identify(Base* p)
{
	if (p == nullptr)
		std::cout << "You provide a nullptr" << std::endl;
	else if (p == dynamic_cast<A*>(p))
	{
		std::cout << "Class A has been generated" << std::endl;
	}
	else if (p == dynamic_cast<B*>(p))
	{
		std::cout << "Class B has been generated" << std::endl;
	}
	else if (p == dynamic_cast<C*>(p))
	{
		std::cout << "Class C has been generated" << std::endl;
	}
}

void	Base::identify(Base& p)
{
	if (&p == nullptr)
		std::cout << "You provide a nullptr" << std::endl;
	if (dynamic_cast<A*>(&p))
	{
		std::cout << "Class A has been generated" << std::endl;
	}
	else if (dynamic_cast<B*>(&p))
	{
		std::cout << "Class B has been generated" << std::endl;
	}
	else if (dynamic_cast<C*>(&p))
	{
		std::cout << "Class C has been generated" << std::endl;
	}
}

Base::~Base(){};