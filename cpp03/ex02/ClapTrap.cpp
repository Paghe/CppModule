#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string nick, int life, int mana, int dps) : _name(nick), _hitpoint(life),
                                                                    _energyPoints(mana), _attackDamage(dps)
{
    std::cout << "Constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & preset)
{
    std::cout << "Copy Constructor called" << std::endl;
    this->_name = preset.getName();
    this->_attackDamage = preset.getDps();
    this->_hitpoint = preset.getLife();
    this->_energyPoints = preset.getMana();
}

std::string ClapTrap::getName(void) const
{
    return (this->_name);
}

int ClapTrap::getMana(void) const
{
    return (this->_energyPoints);
}

int ClapTrap::getDps(void) const
{
    return (this->_attackDamage);
}

int ClapTrap::getLife(void) const
{
    return (this->_hitpoint);
}

ClapTrap& ClapTrap::operator=(ClapTrap const & copy)
{
    this->_name = copy.getName();
    this->_attackDamage = copy.getDps();
    this->_hitpoint = copy.getLife();
    this->_energyPoints = copy.getMana();
    return (*this);
}

std::ostream & operator<<(std::ostream &cout, const ClapTrap &other)
{
    cout << other.getName();
    cout << " ";
    cout << other.getLife();
    cout << " ";
    cout << other.getMana();
    cout << " ";
    cout << other.getDps();
    return (cout);
}

void ClapTrap::attack(const std::string& target)
{
    if (this->_energyPoints > 0)
    {
        std::cout << "ClapTrap " << this->_name << " attacks " << target
                  << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
        this->_energyPoints--;
    }
    else
        std::cout << "OUT OF MANA! 💧" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_energyPoints > 0)
    {
        std::cout << "ClapTrap " << this->_name << " repairs " << amount
                  << " life points!" << std::endl;
        this->_energyPoints--;
        this->_hitpoint += amount;
    }
    else
        std::cout << "OUT OF MANA! 💧" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << "ClapTrap " << this->_name << " has taken " << amount
              << " damage!" << std::endl;
    this->_hitpoint -= amount;
    if (this->_hitpoint <= 0)
        std::cout << this->_name << "✝︎ is dead ✝︎" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called" << std::endl;
}
