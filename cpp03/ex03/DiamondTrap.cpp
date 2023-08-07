#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string nick) : ClapTrap(nick + "_clap_name"), ScavTrap(nick), FragTrap(nick)
{
    std::cout << "DiamondTrap Built" << std::endl;
    this->_name = nick;
    this->_energyPoints = ScavTrap::_energyPoints;
    this->_hitpoint = FragTrap::_hitpoint;
    this->_attackDamage = FragTrap::_attackDamage;
}

void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAMi()
{
    std::cout << "I am " << this->_name << " and " << ClapTrap::_name << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap destroyed" << std::endl;
}