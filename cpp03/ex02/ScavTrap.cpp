#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string nick) : ClapTrap(nick)
{
    std::cout << "ScavTrap Constructor called" << std::endl;
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