#include "ClapTrap.hpp"

int main() {
    ClapTrap clappy("Clappy");
    ClapTrap trappy("Trappy");

    clappy.attack("Trappy");
    trappy.takeDamage(1);
    trappy.beRepaired(5);
    trappy.attack("Clappy");

    ClapTrap clappy_copy(clappy);
    clappy_copy.attack("Trappy");

    return 0;
}