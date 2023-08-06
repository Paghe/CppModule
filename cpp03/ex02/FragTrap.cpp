#include "FragTrap.hpp"

FragTrap::FragTrap(std::string nick, int life, int mana, int dps) : ClapTrap(nick, life, mana, dps)
{
    std::cout << "FragTrap built" << std::endl;
}

void FragTrap::highFiveGuys(void)
{
    std::cout << this->_name << " high five folks! 🖐🏼" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destroyed" << std::endl;
}