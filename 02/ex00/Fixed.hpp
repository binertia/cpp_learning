#pragma once
#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
public:
	Fixed();
	Fixed(const Fixed &obj);
	Fixed &operator=(const Fixed &obj);
	~Fixed();

	void setRawBits(int num);
	int getRawBits() const;
private:
	int value_;
	static const int fractional_bit_ = 8;
};

#endif
