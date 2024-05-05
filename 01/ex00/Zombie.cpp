#include "Zombie.hpp"

Zombie::Zombie() : name_("Zombie next door"){
	std::cout << "default constructor created zombie: " << name_ << std::endl;
}

Zombie::Zombie(const std::string name) : name_(name) {
	std::cout << "constructor created zombie: " << name_ << std::endl;
}

Zombie::~Zombie() {
	std::cout << "destructor cleanup zombie: " << name_ << std::endl;
}

void	Zombie::announce() {
	std::cout << name_ << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
