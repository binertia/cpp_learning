#include "Zombie.hpp"

int	main(void) {
	std::cout << "Create horder with size -10 and 0" << std::endl;
	Zombie *horde_err = zombieHorde(-10, "error");
	std::cout << "---------------------" << std::endl;
	if (horde_err)
		delete [] horde_err;
	Zombie *horde_errtwo = zombieHorde(0, "papa");
	std::cout << "---------------------" << std::endl;
	if (horde_errtwo)
		delete [] horde_errtwo;

	std::cout << "---------------------" << std::endl;
	std::cout << "Create horde size 5 without name." << std::endl;
	Zombie *horde_one = zombieHorde(5, "");
	std::cout << "---------------------" << std::endl;
	if (horde_one)
		delete [] horde_one;
	std::cout << "---------------------" << std::endl;
	std::cout << "Create horde size 10 : called Papaya zomby" << std::endl;
	Zombie *horde_two = zombieHorde(10, "Papapya zomby");
	std::cout << "---------------------" << std::endl;
	if (horde_two)
		delete [] horde_two;
	return (0);
}
