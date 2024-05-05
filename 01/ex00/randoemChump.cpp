#include "Zombie.hpp"

static void callDefaultConstructor();
static void callConstructor(std::string name);

void	randomChump(std::string name) {
	if (name.empty()) {
		callDefaultConstructor();
	} else {
		callConstructor(name);
	}
}

static void callDefaultConstructor() {
	Zombie someZombie;
	someZombie.announce();
}

static void callConstructor(std::string name) {
	Zombie someZombie(name);
	someZombie.announce();
}

