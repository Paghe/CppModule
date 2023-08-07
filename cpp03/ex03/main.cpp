#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void)
{
    ScavTrap preset("Gino");
    FragTrap presetFrag("Marcello");
    FragTrap frag(presetFrag);
    ScavTrap scav(preset);
    DiamondTrap presetDiamond("Pino");
    DiamondTrap Diamond(presetDiamond);
    scav.attack("a kid");
    scav.takeDamage(10);
    scav.beRepaired(10);
    scav.guardGate();
    frag.highFiveGuys();
    Diamond.whoAMi();
    std::cout << Diamond.getMana() << std::endl;
    return (0);
}