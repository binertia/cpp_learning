#include "PhoneBook.hpp"

int	main(void) {
	PhoneBook phone_book;
	std::string input = "";

	phone_book.initMessage();
	while (true) {
		std::cout << "cmd :: " << std::flush;

		std::getline(std::cin, input);
		if (!input.compare("ADD")) {
			phone_book.addContact();
		} else if (!input.compare("SEARCH")) {
			phone_book.searchContact();
		} else if (!input.compare("EXIT")) {
			std::cout << std::endl;
			break ;
		} else if (std::cin.eof()) {
			exit(130);
		} else if (!std::cin.good() ||input.empty()) {
			std::cout << "dota 2" << std::endl;
		}
		else {
			std::cout << "Command not found" << std::endl;
		}
	}
	return (0);
}
