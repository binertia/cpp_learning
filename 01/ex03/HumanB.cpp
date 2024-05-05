#include "HumanB.hpp"

HumanB::HumanB(const std::string name) : name_(name), weapon_(NULL) {

}

HumanB::~HumanB() {

}

void	HumanB::setWeapon(Weapon &weapon) {
	weapon_ = &weapon;
}

void	HumanB::attack() {
	std::cout << name_ << " attacks with their " << std::flush;
	if (weapon_ == NULL) {
		std::cout << "cutie soft hand";
	} else {
		std::cout << weapon_->getType();
	}
	std::cout << std::endl;
}
