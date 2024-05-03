#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.hpp"

class PhoneBook {
	public:
		PhoneBook();
		~PhoneBook();

		void addContact();
		void searchContact() const;
	private:
		Contact contact_[8];
		size_t	contact_count_;

		bool validNumeric_(const std::string input) const;
		void cleanInput_();
};

#endif
