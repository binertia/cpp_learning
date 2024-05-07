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

	bool operator>(const Fixed &obj) const;
	bool operator<(const Fixed &obj) const;
	bool operator>=(const Fixed &obj) const;
	bool operator<=(const Fixed &obj) const;
	bool operator==(const Fixed &obj) const;
	bool operator!=(const Fixed &obj) const;

	Fixed operator+(const Fixed &obj) const;
	Fixed operator-(const Fixed &obj) const;
	Fixed operator*(const Fixed &obj) const;
	Fixed operator/(const Fixed &obj) const;

	Fixed &operator++(); 
	Fixed &operator--();
	Fixed operator++(int);
	Fixed operator--(int);

	static Fixed& min(Fixed &a, Fixed &b);
	const static Fixed& min(const Fixed &a, const Fixed &b);
	static Fixed& max(Fixed &a, Fixed &b);
	const static Fixed& max(const Fixed &a, const Fixed &b);

private:
	int value_;
	static const int fractional_bit_;
};

std::ostream &operator<<(std::ostream &os, const Fixed &obj);

#endif
