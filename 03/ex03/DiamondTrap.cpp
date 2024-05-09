#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
/* #include "ClapTrap.hpp" */
/* #include "FragTrap.hpp" */
/* #include "ScavTrap.hpp" */

DiamondTrap::DiamondTrap() : ScavTrap(), FragTrap(), name_("DEFAULT"){
	std::cout << "[DiamondTrap] Default constructor called" << std::endl;
	ClapTrap::name_ += "_clap_trap";
	this->hp_ = FragTrap::hp_;
	this->ep_ = ScavTrap::ep_;
	this->atk_ = FragTrap::atk_;
}

DiamondTrap::DiamondTrap(const std::string &name) : ScavTrap(name), FragTrap(name), name_(name){
	std::cout << "[DiamondTrap] Constructor called" << std::endl;
	ClapTrap::name_ = name + "_clap_trap";
	this->hp_ = FragTrap::hp_;
	this->ep_ = ScavTrap::ep_;
	this->atk_ = FragTrap::atk_;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ScavTrap(other), FragTrap(other) {
	std::cout << "[DiamondTrap] Constructor called" << std::endl;
	*this = other;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {
	std::cout << "[DiamondTrap] Assigned overload operator called" << std::endl;
	if (this != &other) {
		this->name_ = other.name_;
		ClapTrap::name_ = other.ClapTrap::name_;
		this->hp_ = other.hp_;
		this->ep_ = other.ep_;
		this->atk_ = other.atk_;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap() {
	std::cout << "[DiamondTrap] destructor called" << std::endl;
}

void	DiamondTrap::whoAmI() {
	std::cout << "DiamondTrap run 'Who am i?' : DiamondTrap name:" << this->name_ << "|| ClapTrap name " << ClapTrap::name_ << std::endl;
}
