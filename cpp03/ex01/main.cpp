#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
int main(void)
{
   ScavTrap preset("GINO", 150, 50, 20);
   ScavTrap scav(preset);
   std::cout << scav << std::endl;
   scav.attack("a kid");
   scav.takeDamage(10);
   scav.beRepaired(10);
   scav.guardGate();
   return (0);
}