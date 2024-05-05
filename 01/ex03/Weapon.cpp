#include "Weapon.hpp"

Weapon::Weapon(const std::string type) : type_(type) {

}

Weapon::~Weapon() {

}

void	Weapon::setType(const std::string new_type) {
	type_ = new_type;
}

const std::string	Weapon::getType() {
	return (type_);
}
