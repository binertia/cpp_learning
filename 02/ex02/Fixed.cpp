#include "Fixed.hpp"


const int Fixed::fractional_bit_ = 8;

Fixed::Fixed() : value_(0) {

}

Fixed::Fixed(const int num) {
	value_ = num << fractional_bit_;
}
Fixed::Fixed(const float num) {
	value_ = std::roundf(num * (1 << fractional_bit_));
}

Fixed::Fixed(const Fixed &obj) {
	*this = obj;
}

Fixed &Fixed::operator=(const Fixed &obj) {
	if (this != &obj) {
		this->value_ = obj.value_;
	}
	return (*this);
}

Fixed::~Fixed() {

}

void Fixed::setRawBits(int num) {
	this->value_ = num;
}

int	Fixed::getRawBits() const {
	return (value_);
}

float	Fixed::toFloat() const {
	return ((static_cast<float>(this->getRawBits())) / (1 << fractional_bit_));
}

int	Fixed::toInt() const {
	return (this->getRawBits() >> fractional_bit_);
}

std::ostream &operator<<(std::ostream &os, const Fixed &obj) {
	return (os << obj.toFloat());
}

bool Fixed::operator>(const Fixed &obj) const {
	return (this->getRawBits() > obj.getRawBits());
}

bool Fixed::operator<(const Fixed &obj) const {
	return (this->getRawBits() < obj.getRawBits());
}

bool Fixed::operator>=(const Fixed &obj) const {
	return (this->getRawBits() >= obj.getRawBits());
}

bool Fixed::operator<=(const Fixed &obj) const {
	return (this->getRawBits() <= obj.getRawBits());
}

bool Fixed::operator==(const Fixed &obj) const {
	return (this->getRawBits() == obj.getRawBits());
}

bool Fixed::operator!=(const Fixed &obj) const {
	return (this->getRawBits() != obj.getRawBits());
}

Fixed Fixed::operator+(const Fixed &obj) const {
	return (Fixed(this->toFloat() + obj.toFloat()));
}

Fixed Fixed::operator-(const Fixed &obj) const {
	return (Fixed(this->toFloat() - obj.toFloat()));
}
Fixed Fixed::operator*(const Fixed &obj) const {
	return (Fixed(this->toFloat() * obj.toFloat()));
}

Fixed Fixed::operator/(const Fixed &obj) const {
	return (Fixed(this->toFloat() / obj.toFloat()));
}


Fixed &Fixed::operator++(void) {
	this->value_ += 1;
	return (*this);
}

Fixed &Fixed::operator--(void) {
	this->value_ -= 1;
	return (*this);
}

Fixed Fixed::operator++(int) {
	Fixed ref(*this);
	++(*this);
	return (ref);
}

Fixed Fixed::operator--(int) {
	Fixed ref(*this);
	--(*this);
	return (ref);
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
	return (a.getRawBits() < b.getRawBits() ? a : b);
}
const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
	return (a.getRawBits() < b.getRawBits() ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	return (a.getRawBits() > b.getRawBits() ? a : b);
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b) {
	return (a.getRawBits() > b.getRawBits() ? a : b);
}
