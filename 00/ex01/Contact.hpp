#ifndef CONTACT_H
# define CONTACT_H

# include <iostream>
# include <iomanip>

enum Display{
	full,
	less
};

class Contact {
	public:

		Contact();
		~Contact();

		void setContact(size_t index);
		void DisplayContact(Display type) const;

	private:
		size_t	index_;
		std::string first_name_;
		std::string last_name_;
		std::string nick_name_;
		std::string phone_number_;
		std::string darkest_secret_;

		void getStringInput_(std::string& str, std::string message);
		void getNumberInput_(std::string& str, std::string message);

		void LessOutput_(const std::string source) const;
		void cleanInput_();
};

#endif
