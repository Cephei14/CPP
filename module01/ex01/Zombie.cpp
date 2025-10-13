#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie()
{
}

void Zombie::set_name(std::string name, int n)
{
	std::stringstream ss;
	ss << n;
	this->_name = name + ss.str();
}

Zombie::~Zombie()
{
	std::cout << "\n" <<  this->_name << ": Ate a low IQ brain and died.\n";		
}

void Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
