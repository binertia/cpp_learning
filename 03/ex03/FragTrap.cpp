#include "FragTrap.hpp"
#include "ClapTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	std::cout << "[FragTrap] Default constructor called" << std::endl;
	this->hp_ = 100;
	this->ep_ = 100;
	this->atk_ = 30;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name){
	std::cout << "[FragTrap] Constructor called" << std::endl;
	this->hp_ = 100;
	this->ep_ = 100;
	this->atk_ = 30;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other){
	std::cout << "[FragTrap] Constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
	std::cout << "[FragTrap] Assigned overload operator called" << std::endl;
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	return (*this);
}

FragTrap::~FragTrap() {
	std::cout << "[FragTrap] destructor called" << std::endl;
}

void FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << this->name_ << " is request a high five." << std::endl;
}

void FragTrap::attack(const std::string &target) {
	std::cout << "FragTrap " << this->name_ << " attacks " << target << ", causing " 
		<< this->atk_ << " points of damage!" << std::endl;
}

void FragTrap::takeDamage(unsigned int amount) {
	if(amount > std::numeric_limits<unsigned int>::max() - 100) {
		std::cout << "FragTrap << " << this->name_ << " already arrived to heaven by massive damage" << std::endl;
		this->hp_ = 0;
		this->ep_ = 0;
		return ;
	} else if (this->hp_ == 0) {
		std::cout << "FragTrap " << this->name_ << " is already dead! his corpse took damage " << amount << " points of damage!" << std::endl ;
		return ;
	} else if (amount >= this->hp_) {
		this->hp_ = 0;
		this->ep_ = 0;
	} else {
		this->hp_ -= amount;
	}

	std::cout << "FragTrap " << this->name_ << " took damage " << amount << ", now left only " << this->hp_ << " points of hit point!";
	if (this->hp_ == 0) {
		std::cout << " FragTrap " << this->name_ << " is dead!" ;
	}
	std::cout << std::endl;
}

void FragTrap::beRepaired(unsigned int amount) {
	if(amount > std::numeric_limits<unsigned int>::max() - 100) {
		std::cout << "FragTrap << " << this->name_ << " already arrived to heaven by over repaired" << std::endl;
		this->hp_ = 0;
		this->ep_ = 0;
		return ;
	}
	if (this->hp_ == 0 || this->ep_ == 0) {
		std::cout << "FragTrap " << this->name_ <<" is like crops, Can't even move" << std::endl;
	}

	this->ep_ -= 1;
	std::cout << "FragTrap " << this->name_ << " try to do self-repair. ";

	if (this->hp_ == 100) {
		std::cout << "But sadly, Already at full hp" << std::endl;
		return ;
	} 

	std::cout << "attemp to recover by " << amount << "points. ";
	this->hp_ += amount;
	if (this->hp_ >= 100) {
		this->hp_ = 100;
		std::cout << "Now hit point already full at 100" << std::endl;
	} else {
		std::cout << "Current hit point is" << this->hp_ << std::endl;
	}
}
