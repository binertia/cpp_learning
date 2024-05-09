#include "ScavTrap.hpp"

int main(void) {
	ScavTrap hi;
	ScavTrap love(hi);

	hi.attack("papa");
	hi.beRepaired(90);
	love.attack("mama");
	hi = love;
	hi.attack("papa");
}
