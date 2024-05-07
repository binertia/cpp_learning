#pragma once
#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

// franction_bit = 8;
// 8,388,607 is the cap that value_ can nhandle (<<8 to max int);
// 1.79769e308 is max float; // cap :: [(−1e8) to (1e7 - 1e-8)] = [-128 ~ 127.996]

class Fixed {
public:
	Fixed();

	Fixed(const int num);
	Fixed(const float num);

	Fixed(const Fixed &obj);
	Fixed &operator=(const Fixed &obj);
	~Fixed();

	void setRawBits(int num);
	int getRawBits() const;

	float toFloat() const;
	int	toInt() const;

private:
	int value_;
	static const int fractional_bit_; // init in src file [When defining static class data members, 
	                                  //                  initialize them in the appropriate .cc file.
	                                  //                  Do not initialize them in the header.] 
	                                  //   (avoid potential issues with multiple definitions)(ref. gg style)
};

std::ostream &operator<<(std::ostream &os, const Fixed &obj);

#endif
