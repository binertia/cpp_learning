#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	std::cout << "[WrongAnimal] default constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "[WrongAnimal] destructor called" << std::endl;
}

void WrongAnimal::makeSound() const {
	std::cout << "no sound to make" << std::endl;
}
