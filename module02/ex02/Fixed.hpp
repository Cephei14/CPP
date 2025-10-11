#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int n;
	static const int nb = 8;

public:
	Fixed();
	Fixed(const Fixed& original);
	Fixed& operator=(const Fixed& original);
	~Fixed();

	Fixed(const int n);
	Fixed(const float n);

	int	toInt(void) const;
	int	getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;

	bool operator>(const Fixed& original) const;
	bool operator<(const Fixed& original) const;
	bool operator>=(const Fixed& original) const;
	bool operator<=(const Fixed& original) const;
	bool operator==(const Fixed& original) const;
	bool operator!=(const Fixed& original) const;

	Fixed operator+(const Fixed& original) const;
	Fixed operator-(const Fixed& original) const;
	Fixed operator*(const Fixed& original) const;
	Fixed operator/(const Fixed& original) const;
	
	Fixed& operator++();
	Fixed operator++(int);
	Fixed& operator--();
	Fixed operator--(int);

	static Fixed& min(Fixed& a, Fixed& b);
	static Fixed& max(Fixed& a, Fixed& b);
	static const Fixed& min(const Fixed& a, const Fixed& b);
	static const Fixed& max(const Fixed& a, const Fixed& b);

};

std::ostream& operator<<(std::ostream& COUT, const Fixed& fixed);

#endif