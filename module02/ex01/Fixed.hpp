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

	int		getRawBits(void) const;
	void	setRawBits(int const raw);

	int		toInt(void) const;
	float	toFloat(void) const;
};

std::ostream& operator<<(std::ostream& COUT, const Fixed& fixed);

#endif