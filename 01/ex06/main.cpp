#include "Harl.hpp"

int	main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << "Usage:: /harlFilter [complain stuff]" << std::endl;
		return (1);
	}
	Harl harl_filter;
	std::string input = av[1];

	if (input.empty()) {
		std::cout <<"Quiet today ..."<< std::endl;
	} else {
		harl_filter.complain(input);
	}
	return (0);
}
