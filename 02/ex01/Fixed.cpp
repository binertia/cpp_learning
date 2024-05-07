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
	this->value_ = obj.value_;
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


/* Fixed::Fixed(const float num) { */
/* 	//value_ = static_cast<int>(num * (1 << fractional_bit_)); */
/* } */   // take float and cast made output incorrect
