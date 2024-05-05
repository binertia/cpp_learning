#include "Zombie.hpp"

//prototype
static Zombie	*callDefaultConstructorAlloc ();
static Zombie	*callConstructorAlloc (const std::string name);

Zombie	*newZombie(std::string name) {
	if (name.empty())
		return (callDefaultConstructorAlloc());
	return (callConstructorAlloc(name));
}

static Zombie	*callDefaultConstructorAlloc () {
	return (new Zombie);
}

static Zombie	*callConstructorAlloc (const std::string name) {
	return (new Zombie(name));
}
