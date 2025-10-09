#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout<<"Default constructor called"<< std::endl;
	this->n = 0;
}

Fixed::Fixed(const Fixed& original)
{
	std::cout<<"Copy constructor called" << std::endl;
	this->n = original.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& original)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &original)
		this->n = original.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl; 
}


int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
    return this->n;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->n = raw;
}