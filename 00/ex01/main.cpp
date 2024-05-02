#include "PhoneBook.hpp"
#include <cstdlib>

void	InitMessage(void) {
	std::cout << "|=======  NeoPhoneBook (beta)  =======|\n";
	std::cout << "|                                     |\n";
	std::cout << "|								Manual  |\n";
	std::cout << "|                                     |\n";
	std::cout << "|  ADD    :: add contact              |\n";
	std::cout << "|  SEARCH :: search contact           |\n";
	std::cout << "|  EXIT   :: quit phone book          |\n";
	std::cout << "|                                     |\n";
	std::cout << "|=====================================|" << std::endl;
}

void	ManageCommand(const std::string input, PhoneBook phone_book) {
	std::string discard_message = "Command is not support. Please try again.";
	if (input.compare("ADD") == 0)
		phone_book.Process(0);
	else if (input.compare("SEARCH") == 0)
		phone_book.Process(1);
	else if (input.compare("EXIT") == 0)
		exit(EXIT_SUCCESS);
	else
		std::cout << discard_message << std::endl;
}

int	main(void) {
	PhoneBook	phone_book;
	std::string	input;
	std::string	prompt_message = "Command : ";

	InitMessage();
	std::cout << prompt_message;
	while (std::getline(std::cin, input)) {
		if (std::cin.eof())
			(exit(1));
		ManageCommand(input, phone_book);
		input.clear();
		std::cout << prompt_message;
	}
	std::cout << std::endl;
}
