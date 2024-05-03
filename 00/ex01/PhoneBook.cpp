#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : contact_count_(0) {
}

PhoneBook::~PhoneBook() {
}

void	PhoneBook::addContact() {
	this->contact_[contact_count_ % 8].setContact(contact_count_ % 8);
	contact_count_++;
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

	if (contact_count_ == 0) {
		std::cout << "Sorry, No available contact for now"<< std::endl;
		return ;
	}

	while (index < 8) {
		this->contact_[index].DisplayContact(less);
		index++;
	}

	std::string input = "";
	while(true) {
		std::cout << "Select which Contact you want to view" << std::endl;
		std::cout << "Contact : " << std::flush;
		std::getline(std::cin, input);
		if (!std::cin.good() || input.empty() || !validNumeric_(input) || input.size() > 7 || std::cin.eof()) {
			if (std::cin.eof())
				exit(130);
			std::cin.clear();
			std::cout << "Look like it is bad input , try again <3" << std::endl;
		} else {
			if (std::stoul(input) <= this->contact_count_) {
				std::cin.clear();
				std::cout << "The contact that you choose is not avaiable yet" << std::endl;
				return ;
			} else if (std::stoul(input) > 7 && std::stoul(input) < 0) {
				std::cin.clear();
				std::cout << "Sorry, This crappy phonebook only avaiable from 0 to 7" << std::endl;
			} else {
				this->contact_[std::stoul(input)].DisplayContact(full);
				return ;
			}
		}
	}
}
