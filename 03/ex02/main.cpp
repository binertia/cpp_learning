#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void) {
	FragTrap hi;
	std:: cout << "-------------" << std::endl;
	FragTrap love(hi);
	std:: cout << "-------------" << std::endl;

	hi.attack("papa");
	hi.beRepaired(90);
	love.attack("mama");
	std:: cout << "-------------" << std::endl;
	hi = love;
	std:: cout << "-------------" << std::endl;
	hi.attack("papa");
	std:: cout << "-------------" << std::endl;
	hi.takeDamage(1000);
	hi.takeDamage(2222222222);
	std:: cout << "-------------" << std::endl;
}
