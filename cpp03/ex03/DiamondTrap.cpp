#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string nick) : ClapTrap(nick + "_clap_name"), ScavTrap(nick), FragTrap(nick)
{
    std::cout << "DiamondTrap Built" << std::endl;
    this->_name = nick;
    this->_energyPoints = ScavTrap::_energyPoints;
    this->_hitPoint = FragTrap::_hitPoint;
    this->_attackDamage = FragTrap::_attackDamage;
}

void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}

DiamondTrap::DiamondTrap(DiamondTrap const & cpy) :
	ClapTrap(cpy._name +  "_clap_name"),  ScavTrap(cpy._name), FragTrap(cpy._name), _name(cpy._name)
{
	this->_energyPoints = cpy.getMana();
	this->_hitPoint = cpy.getLife();
	this->_attackDamage = cpy.getDps();
}

DiamondTrap& DiamondTrap::operator=(DiamondTrap const &cpy)
{
	if (this != &cpy)
		*this = cpy;
	return (*this);
}

void DiamondTrap::whoAMi()
{
    std::cout << "I am " << this->_name << " and " << ClapTrap::_name << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap destroyed" << std::endl;
}