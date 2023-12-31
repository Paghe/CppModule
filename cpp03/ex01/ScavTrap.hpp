#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:

        ScavTrap(std::string nick, int life, int mana, int dps);
		ScavTrap(ScavTrap const & preset);
		ScavTrap& operator=(ScavTrap const & cpy);
        ~ScavTrap();
        void attack(const std::string& target);
        void guardGate(void);
};
#endif