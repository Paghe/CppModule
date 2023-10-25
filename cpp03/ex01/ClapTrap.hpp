#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
protected:
    std::string _name;
    int   _hitPoint;
    int   _energyPoints;
    int   _attackDamage;
public:
    ClapTrap(std::string nick, int life, int mana, int dps);
    ClapTrap(ClapTrap const & preset);
    ~ClapTrap();
    ClapTrap& operator=(ClapTrap const & copy);
    std::string getName(void) const;
    int getLife(void) const;
    int getMana(void) const;
    int getDps(void) const;
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

};

std::ostream & operator<<(std::ostream &cout, const ClapTrap &other);
#endif