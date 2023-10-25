#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string nick) : ClapTrap(nick)
{
    this->_hitPoint = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    std::cout << "ScavTrap Constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &preset) : ClapTrap(preset){}

ScavTrap& ScavTrap::operator=(const ScavTrap &cpy)
{
	ClapTrap::operator=(cpy);
	return (*this);
}

void    ScavTrap::attack(const std::string& target)
{
    if (this->_energyPoints > 0)
    {
        std::cout << "ScavTrap " << this->_name << " attacks " << target
                  << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
        this->_energyPoints--;
    }
    else
        std::cout << "OUT OF MANA! 💧" << std::endl;
}

void    ScavTrap::guardGate()
{
    std::cout << this->_name << " is now in Gate keeper mode!" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destroyed" << std::endl;
}