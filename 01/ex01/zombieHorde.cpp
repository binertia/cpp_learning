#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name) {
	if (N <= 0) {
		std::cout << "Zombie horde is confuse about zero and minus" << std::endl;
		return (NULL);
	}

	Zombie	*horde = new Zombie[N];
	if (horde == NULL) {
		std::cout << "It look like no space for lovely zombie" << std::endl;
		return (NULL);
	}
	for (int i = 0; i < N; i++) {
		if (!name.empty())
			horde[i].setName(name);
		horde[i].setIndex(i + 1);
		horde[i].announce();
	}
	return (horde);
}
