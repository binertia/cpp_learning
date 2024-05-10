#include "Cat.hpp"
#include "Animal.hpp"

Cat::Cat() {
	std::cout << "[Cat] construct called" << std::endl;
	type_ = "Cat";
}

Cat::~Cat() {
	std::cout << "[Cat] destruct called" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "meow" << std::endl;
}
