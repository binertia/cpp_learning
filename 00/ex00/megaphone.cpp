#include <cctype>
#include <iostream>

class  MegaPhone {

	public:
	void  dialing(const int size, char **arr) {
		shouting(size, (const char **)arr);
	}
	private:
	void shouting(const int size, const char **arr) {
		if (size == 1) {
			std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
		} else {
			int	i = 1;
			while (i < size) {
				std::string arg = arr[i];
				for (std::string::iterator iter = arg.begin(); iter != arg.end(); ++iter) {
					*iter = std::toupper(*iter);
				}
				std::cout << arg;
				if (i < size - 1)
					std::cout << " ";
				i++;
			}
		}
		std::cout << std::endl;
	}
};

int	main(int ac, char *av[])
{
	MegaPhone phone;

	phone.dialing(ac, av);
	return (0);
}
