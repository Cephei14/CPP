#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->_name = name;
	this->wB = NULL;
}

void HumanB::setWeapon(Weapon& weapon)
{
	this->wB = &weapon;
}

void HumanB::attack()
{
	if(this->wB)
		std::cout << this->_name << " attacks with their " << this->wB->getType() << std::endl;
	else
		std::cout << this->_name << " slaps the enemy\n";
}