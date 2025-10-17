#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap Default constructor called" << std::endl << "\"default\" has been created !" << std::endl;
	this->_name = "Default";
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap \"" << this->_name << "\" has been created!" << std::endl;
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Default destructor called : \"" << this->_name << "\" has been destroyed" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << "ScavTrap copy constructor called, a duplicated of \"" << other._name << " \"has been created !" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << "ScavTrap copy assignment called" << std::endl;
	if (this != &other)
		ClapTrap::operator=(other);
	return *this;
}

void ScavTrap::attack(const std::string& target)
{
	if(this->_energy_points < 1)
	{
		std::cout << "\"" << this->_name << "\" Have no energy left to attack !" << std::endl;
		return;
	}
	if(this->_hit_points < 1)
	{
		std::cout << "\""  << this->_name  << "\" Is fainted !" << std::endl;
		return;
	}
	std::cout << "\""  << this->_name << "\" Attacks \"" << target << "\", causing \"" << this->_attack_damage << "\" points of damage !" << std::endl;
	this->_energy_points--;
}

void ScavTrap::guardGate()
{
		if(this->_energy_points < 1)
	{
		std::cout << "\"" << this->_name << "\" Has no energy left !" << std::endl;
		return;
	}
	if(this->_hit_points < 1)
	{
		std::cout << "\""  << this->_name  << "\" Is fainted !" << std::endl;
		return;
	}
	std::cout << "\"" << this->_name << " \" is in Gate keeper mode." << std::endl;
}
