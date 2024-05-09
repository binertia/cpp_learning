#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name_("DEFAULT"), hp_(10), ep_(10), atk_(0) {
	std::cout << "[ClapTrap] Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string & name) : name_(name), hp_(10), ep_(10), atk_(0) {
	std::cout << "[ClapTrap] Constructor called for : " << name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& obj) {
	std::cout << "[ClapTrap]Copy constructor called for : " << obj.name_ << std::endl;
	*this = obj;
}

ClapTrap &ClapTrap::operator=(const ClapTrap& obj) {
	std::cout << "[ClapTrap] assigned operator overload called for : " << obj.name_ << std::endl;
	if (this != &obj) {
		this->name_ = obj.name_;
		this->hp_ = obj.hp_;
		this->ep_ = obj.ep_;
		this->atk_ = obj.atk_;
	}
	return (*this);
}

ClapTrap::~ClapTrap() {
	std::cout << "[ClapTrap] destructor called";
}

void ClapTrap::attack(const std::string &target) {
	if (this->hp_ == 0 || this->ep_ == 0) {
		std::cout << "ClapTrap " << this->name_ <<" is like crops, Can't even move" << std::endl;
	} else {
		this->ep_ -= 1;
		std::cout << "ClapTrap " << this->name_ << " attacks " << target << ", causing " << this->atk_ << " points of damage!"<< std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if(amount > std::numeric_limits<unsigned int>::max() - 10) {
		std::cout << "ClapTrap << " << this->name_ << " already arrived to heaven by massive damage" << std::endl;
		this->hp_ = 0;
		this->ep_ = 0;
		return ;
	} else if (this->hp_ == 0) {
		std::cout << "ClapTrap " << this->name_ << " is already dead! his corpse took damage " << amount << " points of damage!" << std::endl ;
		return ;
	} else if (amount >= this->hp_) {
		this->hp_ = 0;
		this->ep_ = 0;
	} else {
		this->hp_ -= amount;
	}

	std::cout << "ClapTrap " << this->name_ << " took damage " << amount << ", now left only " << this->hp_ << " points of hit point!";
	if (this->hp_ == 0) {
		std::cout << " ClapTrap " << this->name_ << " is dead!" ;
	}
	std::cout << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if(amount > std::numeric_limits<unsigned int>::max() - 10) {
		std::cout << "ClapTrap << " << this->name_ << " already arrived to heaven by over repaired" << std::endl;
		this->hp_ = 0;
		this->ep_ = 0;
		return ;
	}
	if (this->hp_ == 0 || this->ep_ == 0) {
		std::cout << "ClapTrap " << this->name_ <<" is like crops, Can't even move" << std::endl;
	}

	this->ep_ -= 1;
	std::cout << "ClapTrap " << this->name_ << " try to do self-repair. ";

	if (this->hp_ == 10) {
		std::cout << "But sadly, Already at full hp" << std::endl;
		return ;
	} 

	std::cout << "attemp to recover by " << amount << "points. ";
	this->hp_ += amount;
	if (this->hp_ >= 10) {
		this->hp_ = 10;
		std::cout << "Now hit point already full at 10" << std::endl;
	} else {
		std::cout << "Current hit point is" << this->hp_ << std::endl;
	}
}
