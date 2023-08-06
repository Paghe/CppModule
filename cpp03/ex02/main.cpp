#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
int main(void)
{
    ScavTrap preset("GINO");
    FragTrap presetFrag("Marcello");
    FragTrap frag(presetFrag);
    ScavTrap scav(preset);
    scav.attack("a kid");
    scav.takeDamage(10);
    scav.beRepaired(10);
    scav.guardGate();
    frag.highFiveGuys();
    return (0);
}