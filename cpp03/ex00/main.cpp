#include "ClapTrap.hpp"

int main (void)
{
    ClapTrap preset("Pino", 10, 10, 10);
    ClapTrap characterOne(preset);
    characterOne.attack("a kid");
    characterOne.beRepaired(10);
    characterOne.takeDamage(25);
    return (0);
}