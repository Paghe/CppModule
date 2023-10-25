#include "FragTrap.hpp"

FragTrap::FragTrap(std::string nick) : ClapTrap(nick)
{
    this->_hitPoint = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    std::cout << "FragTrap builted" << std::endl;
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