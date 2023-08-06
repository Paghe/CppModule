#include "FragTrap.hpp"

FragTrap::FragTrap(std::string nick) : ClapTrap(nick)
{
    this->_hitpoint = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    std::cout << "FragTrap builted" << std::endl;
}

void FragTrap::highFiveGuys(void)
{
    std::cout << this->_name << " high five folks! 🖐🏼" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destroyed" << std::endl;
}