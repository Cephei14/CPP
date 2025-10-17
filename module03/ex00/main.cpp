#include "ClapTrap.hpp"

int main() 
{
    ClapTrap clap("Claaap");
    ClapTrap trap("Traaap");

    clap.attack("Traaap");
    trap.takeDamage(1);
    trap.beRepaired(5);
    trap.attack("Claaap");
	clap.takeDamage(0);

    ClapTrap c_clap(trap);
	c_clap.beRepaired(1);
    c_clap.attack("Traaap");
	trap.takeDamage(2);
	trap.beRepaired(10);
	ClapTrap t_trap;
	t_trap = trap;
	t_trap.attack("Traap");
	trap.beRepaired(2);

    return 0;
}