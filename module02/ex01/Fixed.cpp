#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout<<"Default constructor called"<< std::endl;
	this->n = 0;
}

Fixed::Fixed(const Fixed& original)
{
	std::cout<<"Copy constructor called" << std::endl;
	*this = original;
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
    return this->n;
}

void Fixed::setRawBits(int const raw)
{
	this->n = raw;
}

Fixed::Fixed(const float floatValue)
{
	std::cout << "Float constructor called" << std::endl;
	this->n = roundf(floatValue * (1 << nb));
}

float Fixed::toFloat(void) const
{
	return (float)this->n / (float)(1 << nb);
}

Fixed::Fixed(const int intValue)
{
	std::cout << "Int constructor called" << std::endl;
	this->n = intValue << nb;
}

int	Fixed::toInt(void) const
{
	return this->n >> nb;
}

std::ostream& operator<<(std::ostream& COUT, const Fixed& fixed)
{
	COUT << fixed.toFloat();
	return COUT;
}