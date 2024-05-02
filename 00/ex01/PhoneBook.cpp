#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
}

PhoneBook::~PhoneBook() {
}

void	PhoneBook::Process(size_t act) {
	if (act == Add)
		AddContact_();
	else
		SearchContact_();
}

void	PhoneBook::AddContact_(void) {
	static size_t	i = 0;

	this->contact_[i % 8].MakeData(i);
	i++;
}

void	PhoneBook::SearchContact_(void) {
	size_t	index = PhoneBook::MatchContact_();

	this->contact_[index].DisplayFullContact();
}

size_t	PhoneBook::MatchContact_(void) const {
	std::string	info_message = "Which contact number? :";
	bool	checker = false;
	size_t	index = 9;

	while (!checker) {
		std::cout << info_message << std::flush;
		std::cin >> index;
		if (!std::cin.fail() && (index >= 0 && index <= 8 )) {
			checker = !checker;
		} else {
			std::cout << std::flush << "Your input is out-of-range. Please try again." << std::endl;
			std::cin.clear();
			while (std::cin.get() != '\n');
		}
	}
	return (index);
}
