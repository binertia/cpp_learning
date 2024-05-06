#include "Harl.hpp"

int	main(int ac, char **av) {
	(void) av;
	if (ac != 1) {
		std::cerr << "Usage :: only \"harl\" without any option";
		return (0);
	}

	Harl the_harl;
	while (true) {
		std::string input;
		std::cout << ":: > " << std::flush;
		std::getline(std::cin, input);
		if (std::cin.good() && !input.empty()) {
			the_harl.complain(input);
		} else if (std::cin.eof()) {
			std::cout << std::endl;
			return (130);
		}
		std::cin.clear();
	}
}
