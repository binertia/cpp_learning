#include <iostream>

int	main(void) {
	int i = 1;

	int	j = 23;
	while (j > 0) {
		i = i << 1;
		i++;
		j--;
	}
	std::cout << i << " " << j << " " << j << std::endl;
	j = 7;
	while (j > 0) {
		i = i << 1;
		i++;
		j--;
	}
	std::cout << i << " " << j << " " << (i >> 8) << std::endl;
}
