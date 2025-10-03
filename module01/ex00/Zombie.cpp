#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name)
{
	this->_name = name;
	std::cout<<"-> . . . Something is spawning . . . <-\n\n";
}

Zombie::~Zombie()
{
	std::cout << this->_name << ": Ate low IQ brain and died from diarrhea\n\n";		
}

void Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}