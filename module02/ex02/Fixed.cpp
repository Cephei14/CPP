#include "Fixed.hpp"

Fixed::Fixed()
{
	this->n = 0;
}

Fixed::Fixed(const Fixed& original)
{
	*this = original;
}

Fixed& Fixed::operator=(const Fixed& original)
{
	if (this != &original)
		this->n = original.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
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
	this->n = roundf(floatValue * (1 << nb));
}

float Fixed::toFloat(void) const
{
	return ((float)this->n / (float)(1 << nb));
}

Fixed::Fixed(const int intValue)
{
	this->n = intValue << nb;
}

int	Fixed::toInt(void) const
{
	return (this->n >> nb);
}

std::ostream& operator<<(std::ostream& COUT, const Fixed& fixed)
{
	COUT << fixed.toFloat();
	return COUT;
}


bool Fixed::operator>(const Fixed& original) const
{
	return(this->n > original.n);
}

bool Fixed::operator<(const Fixed& original) const
{
	return (this->n < original.n);
}

bool Fixed::operator>=(const Fixed& original) const
{
	return(this->n >= original.n);
}

bool Fixed::operator<=(const Fixed& original) const
{
	return(this->n <= original.n);
}

bool Fixed::operator==(const Fixed& original) const
{
	return(this->n == original.n);
}

bool Fixed::operator!=(const Fixed& original) const
{
	return(this->n == original.n);
}

Fixed Fixed::operator+(const Fixed& original) const
{
	Fixed result;

	result.setRawBits(this->n + original.n);
	return(result);
}

Fixed Fixed::operator-(const Fixed& original) const
{
	Fixed result;

	result.setRawBits(this->n - original.n);
	return(result);
}

Fixed Fixed::operator*(const Fixed& original) const
{
	return Fixed(this->toFloat() * original.toFloat());
}

Fixed Fixed::operator/(const Fixed& original) const
{
	return Fixed(this->toFloat() / original.toFloat());
}

Fixed& Fixed::operator++()
{
	this->n++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp = *this;

	this->n++;
	return tmp;
}

Fixed& Fixed::operator--()
{
	this->n--;
	return(*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp = *this;

	this->n--;
	return (tmp);
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	return (a < b ? a : b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	return (a > b ? a : b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	return (a < b ? a : b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	return (a > b ? a : b);
}
