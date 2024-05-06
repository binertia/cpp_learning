#include "Contact.hpp"
#include <string>

Contact::Contact() {
}

Contact::~Contact() {
}

void	Contact::setContact(size_t index) {
	this->index_ = index;
	getStringInput_(first_name_, "first name");
	getStringInput_(last_name_, "last name");
	getStringInput_(nick_name_, "nick name");
	getNumberInput_(phone_number_, "phone number");
	getStringInput_(darkest_secret_, "darkest secret");
}

void	Contact::LessOutput_(const std::string source) const {
	if (source.size() > 10) {
		std::cout << "|" << std::setw(9) << source.substr(0, 9) << ".";
	} else {
		std::cout << "|" << std::setw(10) << source;
	}
}

void	Contact::DisplayContact(Display type) const {
	if (this->first_name_.empty() || this->last_name_.empty() || this->nick_name_.empty())
        return ;
	if (type == less) {
		LessOutput_(std::to_string(this->index_));
		LessOutput_(this->first_name_);
		LessOutput_(this->last_name_);
		LessOutput_(this->nick_name_);
		std::cout << "|" << std::endl;
	} else {
		std::cout << "Contact no. " << this->index_ << "\n";
		std::cout << "First name      : " << this->first_name_ << "\n";
		std::cout << "Last name       : " << this->last_name_ << "\n";
		std::cout << "Nick name       : " << this->nick_name_ << "\n";
		std::cout << "Phone number    : " << this->phone_number_ << "\n";
		std::cout << "Darkest secret  : " << this->darkest_secret_ << std::endl;
	}
}

void	Contact::getStringInput_(std::string& str, std::string message) {
	while (true) {
		std::cout << "Fill " << message << " : " << std::flush;
		std::getline(std::cin, str);
		if (std::cin.eof()) {
			std::exit(130);
		} else if (str.empty() || !std::cin.good()) {
			std::cin.clear();
			std::cout << "Sorry, We can't take empty input. try again" << std::endl;
		} else {
			bool valid_str = true;
			for (size_t i = 0; i < str.size(); ++i) {
				if (!isalpha(static_cast<unsigned char>(str[i])) && static_cast<unsigned char>(str[i]) != '.') {
					str.clear();
					valid_str = false;
					break;
				}
			}
			if (valid_str == false) {
				std::cin.clear();
				std::cout << "This form only takes alphabet, try again" << std::endl;
			} else {
				break;
			}
		}
	}
}

void Contact::getNumberInput_(std::string& str, std::string message) {
    while (true) {
        std::cout << "Fill " << message << " : " << std::flush;
		std::getline(std::cin, str);
        if (str.empty()) {
			std::cin.clear();
            std::cout << "Sorry, We can't take empty input. try again" << std::endl;
        } else {
            bool valid_str = true;
            for (size_t i = 0; i < str.size(); ++i) {
                if (!isdigit(static_cast<unsigned char>(str[i])) && static_cast<unsigned char>(str[i]) != '+') {
                    str.clear();
                    valid_str = false;
                    break;
                }
            }
            if (valid_str == false) {
				std::cin.clear();
                std::cout << "This form only takes number, try again" << std::endl;
            } else if (str.size() > 19) {
				std::cin.clear();
				std::cout << "Your number is too long for this crapy process, try again" << std::endl;
			} else {
                break;
            }
        }
    }
}

void	Contact::cleanInput_() {
	char c;
	while ((c = std::cin.get()) != '\n' && c != EOF);
}
