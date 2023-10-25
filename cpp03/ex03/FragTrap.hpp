#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
    public:
    FragTrap(std::string nick);
	FragTrap(FragTrap const & preset);
	FragTrap&  operator=(FragTrap const & cpy);
    ~FragTrap();
    void highFiveGuys(void);
};
#endif
