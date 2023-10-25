#include "FragTrap.hpp"

FragTrap::FragTrap(std::string nick) : ClapTrap(nick)
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