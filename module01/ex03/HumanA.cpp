#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), wA(weapon)
{
}

void HumanA::attack()
{
	std::cout << this->_name << " attacks with their " << this->wA.getType() << std::endl;
}