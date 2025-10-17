#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap Default constructor called" << std::endl << "\"default\" has been created !" << std::endl;
	this->_name = "default";
	this->_hit_points = 10;
	this->_energy_points = 10;
	this->_attack_damage = 0;
}

ClapTrap::ClapTrap(std::string name) : _name(name)
{
	std::cout << "ClapTrap parameterized constructor called " << std::endl << "\"" << name << "\" has been created !" << std::endl;
	this->_hit_points = 10;
	this->_energy_points = 10;
	this->_attack_damage = 0;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Claptrap Default destructor called : \"" << this->_name << "\" has been destroyed" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "ClapTrap copy constructor called, a duplicated of \"" << other._name << " \"has been created !" << std::endl;
	this->_name = other._name;
	this->_hit_points = other._hit_points;
	this->_energy_points = other._energy_points;
	this->_attack_damage = other._attack_damage;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		this->_hit_points = other._hit_points;
		this->_energy_points = other._energy_points;
		this->_attack_damage = other._attack_damage;
	}
	return *this;
}

void ClapTrap::attack(const std::string& target)
{
	if(this->_energy_points < 1)
	{
		std::cout << "\"" << this->_name << "\" Has no energy left to attack !" << std::endl;
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

void ClapTrap::takeDamage(unsigned int amount)
{
	if(this->_hit_points == 0)
	{
		std::cout << "\""  << this->_name << "\" Is fainted !" << std::endl;
		return;
	}
	if(this->_hit_points <= amount)
	{
		this->_hit_points = 0;
		std::cout << "\""  << this->_name << "\" Took \"" << amount <<"\" of damage causing it to faint !" << std::endl;
	}
	else
	{
		this->_hit_points -= amount;
		std::cout << "\""  << this->_name << "\" Took \"" << amount <<"\" of damage leaving it with \"" << this->_hit_points << "\" Hit points!" << std::endl;
	}
}
void ClapTrap::beRepaired(unsigned int amount)
{
	if(this->_energy_points < 1)
	{
		std::cout << "\"" << this->_name << "\" Has no energy left to repair !" << std::endl;
		return;
	}
	if(this->_hit_points < 1)
	{
		std::cout << "\"" << this->_name << "\" Cannot repair itself !" << std::endl;
		return;
	}
	this->_energy_points--;
	this->_hit_points += amount;
	std::cout << "\""  << this->_name << "\" Repaired \"" << amount << "\" hit points leaving it with \""<< this->_energy_points << "\" Energy_points and \""<< this->_hit_points << "\" Hit points !" <<std::endl;
}
