#include "Zombie.hpp"

int	main(void) {
	randomChump("");
	std::cout << "-----------" << std::endl;
	Zombie *lot = newZombie("");
	lot->announce();
	delete lot;
	std::cout << "-----------" << std::endl;
	randomChump("hello");
	std::cout << "-----------" << std::endl;
	Zombie *god = newZombie("world");
	god->announce();
	delete god;
}
