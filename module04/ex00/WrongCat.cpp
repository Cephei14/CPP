#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	std::cout << "WrongCat Default constructor called" << std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	std::cout << "WrongCat copy assignment operator called" << std::endl;
	if(this != &other)
		WrongAnimal::operator=(other);
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << this->type << " : \"Meow\"" << std::endl;
}

std::string WrongCat::getType() const
{
	return (this->type);
}