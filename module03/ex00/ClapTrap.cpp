#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("User"), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << "ClapTrap : \"" << this->_name << "\" has been created by default constructor !" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << "ClapTrap : \"" << this->_name << "\" has been created!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "ClapTrap : copy constructor called" << std::endl;
	*this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "ClapTrap : copy assignment operator called" << std::endl;
	if(this != &other)
	{
		this->_name = other._name;
		this->_hit_points = other._hit_points;
		this->_energy_points = other._energy_points;
		this->_attack_damage = other._attack_damage;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap : \""<< this->_name << "\" has been destroyed !" << std::endl;
}

void ClapTrap::attack(const std::string& target) 
{
    if (this->_energy_points == 0)
	{
        std::cout << "ClapTrap : \"" << this->_name << "\" is out of energy!" << std::endl;
        return;
    }
    if (this->_hit_points == 0)
	{
        std::cout << "ClapTrap : \"" << this->_name << "\" has no hit points left to attack!" << std::endl;
        return;
    }
    this->_energy_points--;
    std::cout << "ClapTrap : \"" << this->_name << "\" attacks \"" << target << "\", causing " << this->_attack_damage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (this->_hit_points == 0)
	{
        std::cout << "ClapTrap : \"" << this->_name << "\" is already destroyed!" << std::endl;
        return;
    }
    if (amount > this->_hit_points)
        this->_hit_points = 0;
    else
        this->_hit_points -= amount;
    std::cout << "ClapTrap : \"" << this->_name << "\" takes " << amount << " points of damage! Current HP: " << this->_hit_points << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_energy_points == 0)
	{
        std::cout << "ClapTrap : \"" << this->_name << "\" is out of energy!" << std::endl;
        return;
    }
    if (this->_hit_points == 0)
	{
        std::cout << "ClapTrap : \"" << this->_name << "\" cannot be repaired as it is already destroyed!" << std::endl;
        return;
    }
    this->_energy_points--;
    this->_hit_points += amount;
    std::cout << "ClapTrap : \"" << this->_name << "\" is repaired for " << amount << " points! Current HP: " << this->_hit_points << std::endl;
}
