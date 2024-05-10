#include "Dog.hpp"

Dog::Dog() {
	std::cout << "[Dog] construct called" << std::endl;
	type_ = "Dog";
}

Dog::~Dog() {
	std::cout << "[Dog] destruct called" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "Haw Haw!" << std::endl;
}
