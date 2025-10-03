#include "Zombie.hpp"
#include <iostream>

void randomChump( std::string name)
{
	Zombie weak_zombie(name);
	weak_zombie.announce();
	return;
}