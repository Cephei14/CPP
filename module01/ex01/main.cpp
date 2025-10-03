#include "Zombie.hpp"

int main(int ac, char **av)
{
	if (ac == 3)
	{
		int n = atoi(av[1]);
		std::cout << "creating a horde of " << n << " Zombies :\n";
		if(n > 0)
		{
			Zombie *horde = zombieHorde(n, av[2]);
			delete[] horde;
		}
		else
			std::cout << "----> Do you want " << n << " Zombie ? that's impossible\n";
	}
	else
		std::cout << "Usage : "<< av[0] <<" <Horde SIZE> <Horde NAME>\n";
	return 0;
}