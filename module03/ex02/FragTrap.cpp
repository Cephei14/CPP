#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "Fragtrap Default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "Fragtrap parameterized constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << "Fragtrap copy constructor called" << std::endl;
}

FragTrap& FragTrap:: operator=(const FragTrap& other)
{
	std::cout << "Fragtrap copy assignment operator called" << std::endl;

	if(this != &other)
	{
		ClapTrap::operator=(other);
	}
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "Fragtrap Destructor called" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	if(this->_hit_points < 1)
	{
		std::cout << "\"" <<this->_name << "\" has no hit points !" << std::endl;
		return;
	}
	if(this->_energy_points < 1)
	{
		std::cout << "\"" <<this->_name << "\" has no energy points !" << std::endl;
		return;
	}
	std::cout << "\"" <<this->_name << "\" Is requesting a +HighFive !" << std::endl;
}
