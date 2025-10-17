#include "ScavTrap.hpp"

int main()
{
    ScavTrap scav("scav");
    ScavTrap trap("trap");

    scav.attack("trap");
    trap.takeDamage(20);
    trap.beRepaired(10);
    scav.guardGate();
	
    ScavTrap scav_copy(scav);
    scav_copy.attack("trap");
    trap.takeDamage(20);
	trap.guardGate();
    scav.attack("trap");
    trap.takeDamage(20);
    scav_copy.attack("trap");
    trap.takeDamage(20);
    scav.attack("trap");
    trap.takeDamage(20);
	trap.guardGate();
    scav_copy.attack("trap");
    trap.takeDamage(20);
	trap.guardGate();
    return 0;
}