#include "Zombie.hpp"

int main(int ac, char **av)
{
	if (ac == 3)
	{
		randomChump(av[2]);
		Zombie *zombie  = newZombie(av[1]);
		zombie->announce();
		delete zombie;
	}
	else
		std::cout << "Usage : ./zombie <Zombie name1> <Zombie name2>\n";
	return 0;
}