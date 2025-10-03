#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <cstdlib>

class Zombie
{
private:
	std::string _name;
public:
	Zombie();
	void	set_name(std::string name, int n);
	void	announce(void);
	~Zombie();
};

Zombie* zombieHorde( int N, std::string name);

#endif