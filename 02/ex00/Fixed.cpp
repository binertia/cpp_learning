#include "Fixed.hpp"

Fixed::Fixed() : value_(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &obj) {
	std::cout << "Copy constructor called" << std::endl;
	this->value_ = obj.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &obj) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj)
		this->value_ = obj.getRawBits();
	return (*this);
}

Fixed::~Fixed() {
	std::cout << "Decontruct called" << std::endl;
}

void	Fixed::setRawBits(int num) {
	std::cout << "setRawBits member function called" << std::endl;
	this->value_ = num;
}

int	Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->value_);
}
