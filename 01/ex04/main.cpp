#include "NeoSed.hpp"

int	main(int ac, char **av) {
	if (ac != 4) {
		std::cerr << "::: Usage ::: nsed [file-name] <to-replace> <for-replace> " << std::endl;
		return (1);
	}
	NeoSed nsed(av[1]);
	nsed.setData(av[2], av[3]);
	return (nsed.searchAndReplace());
}
