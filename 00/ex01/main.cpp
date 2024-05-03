#include "PhoneBook.hpp"

int	main(void) {
	PhoneBook phone_book;
	std::string input = "";

	while (true) {
		std::cout << "command : " << std::flush;
		std::cin >> input;

		if (!input.compare("ADD")) {
			phone_book.addContact();
		} else if (!input.compare("SEARCH")) {
			phone_book.searchContact();
		} else if (!input.compare("EXIT")) {
			std::cout << std::endl;
			break ;
		} else if (std::cin.eof()) {
			exit(130);
		} else {
			std::cout << "Command not found" << std::endl;
		}
	}
	return (0);
}
