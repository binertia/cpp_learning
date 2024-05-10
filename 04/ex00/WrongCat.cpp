#include "WrongCat.hpp"

WrongCat::WrongCat() {
	type_ = "Cat";
	std::cout << "[WrongCat] default constructor called" << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << "[WrongCat] destructor called" << std::endl;
}

void WrongCat::makeSound() const {
	Dog::makeSound();
}
