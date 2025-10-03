#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie* horde = new Zombie[N];

	for (int i = 0; i < N; i++)
	{
		horde[i].set_name(name, i + 1);
		std::cout<<"\n-> . . . Something is spawning . . . <-\n";
		horde[i].announce();
	}
	return horde;
}