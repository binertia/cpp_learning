#include "Animal.hpp"

Animal::Animal() {
	std::cout << "[Animal] default constructor called" << std::endl;
}
Animal::~Animal() {
	std::cout << "[Animal] destructor called" << std::endl;
}

Animal::Animal(const Animal &other) : type_(other.type_) {
	std::cout << "[Animal] copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &other) {
	std::cout << "[Animal] assign operator overload called" << std::endl;
	if (this != &other) {
		type_ = other.type_;
	}
	return (*this);
}

std::string Animal::getType() const {
	return (this->type_);
}

void Animal::makeSound() const {
	std::cout << "no sound .." << std::endl;
}
