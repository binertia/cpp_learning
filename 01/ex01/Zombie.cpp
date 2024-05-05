#include "Zombie.hpp"

Zombie::Zombie() : name_("Zombie next door"), index_(0) {
	std::cout << "default constructor created zombie: " << name_ <<std::endl;
}

Zombie::Zombie(const std::string name, size_t N) : name_(name), index_(N) {
	std::cout << "constructor created zombie: " << name_ << index_ << std::endl;
}

Zombie::~Zombie() {
	std::cout << "destructor cleanup zombie: " << name_ << index_ << std::endl;
}

void	Zombie::setName(const std::string name) {
	name_ = name;
}

void	Zombie::setIndex(const size_t index) {
	index_ = index;
}

void	Zombie::announce() {
	std::cout << name_ << index_ << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

