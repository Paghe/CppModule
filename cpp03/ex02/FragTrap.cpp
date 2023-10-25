#include "FragTrap.hpp"

FragTrap::FragTrap(std::string nick) : ClapTrap(nick)
{
    std::cout << "FragTrap built" << std::endl;
}

FragTrap::FragTrap(const FragTrap &preset) : ClapTrap(preset){}

FragTrap& FragTrap::operator=(const FragTrap &cpy)
{
	ClapTrap::operator=(cpy);
	return (*this);
}

void FragTrap::highFiveGuys(void)
{
    std::cout << this->_name << " high five folks! 🖐🏼" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destroyed" << std::endl;
}