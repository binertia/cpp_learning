#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : contact_count_(0) {
}

PhoneBook::~PhoneBook() {
}

void	PhoneBook::initMessage() {
    std::cout << "\033[2J\033[1;1H" <<std::endl; // ascii for clear screen
	std::cout << "====== NeoPhonebook ======\n";
	std::cout << "|                manual  |\n";
	std::cout << "|                        |\n";
	std::cout << "|  ADD : add a contact.  |\n";
	std::cout << "|  SEARCH : find contac. |\n";
	std::cout << "|  EXIT : close program. |\n";
	std::cout << "==========================" << std::endl;
}

void	PhoneBook::addContact() {
	this->contact_[contact_count_ % 8].setContact(this->contact_count_ % 8);
	this->contact_count_++;
}

void	PhoneBook::cleanInput_() {
	char c;
	while ((c = std::cin.get()) != '\n' && c != EOF);
}

bool	PhoneBook::validNumeric_(const std::string input) const {
	for (size_t i = 0; i < input.size(); i++) {
		if (!isdigit(input[i]))
			return (false);
	}
	return (true);
}

void	PhoneBook::searchContact() const {
	size_t	index = 0;

	if (this->contact_count_ == 0) {
		std::cout << "Sorry, No available contact for now"<< std::endl;
		return ;
	}

	std::cout << std::endl;
	while (index < 8) {
		this->contact_[index].DisplayContact(less);
		index++;
	}
	std::cout << std::endl;

	std::string input = "";

	std::cout << "Select which Contact you want to view" << std::endl;
	while(true) {
		std::cout << "Contact : " << std::flush;
		std::getline(std::cin, input);
		if (std::cin.eof()) {
			std::exit(130);
		} else if (!std::cin.good() || input.empty() || !validNumeric_(input) || input.size() > 7 ) {
			std::cin.clear();
			std::cout << "Look like it is bad input , try again <3" << std::endl;
		} else {
			if (std::stoul(input) >= this->contact_count_) {
				std::cin.clear();
				std::cout << "The contact that you choose is not avaiable yet" << std::endl;
				return ;
			} else if (std::stoul(input) > 7 && std::stoul(input) < 0) {
				std::cin.clear();
				std::cout << "Sorry, This crappy phonebook only avaiable from 0 to 7" << std::endl;
			} else {
				std::cout << std::endl;
				this->contact_[std::stoul(input)].DisplayContact(full);
				std::cout << std::endl;
				return ;
			}
		}
	}
}
