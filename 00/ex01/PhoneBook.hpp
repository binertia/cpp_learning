#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#include "Contact.hpp"

enum action {
	Add,
	Search,
};

class PhoneBook {
	public:
		PhoneBook();
		~PhoneBook();
		void Process(size_t act);

	private:
		Contact contact_[8];
		void	AddContact_();
		void	SearchContact_(); 
		size_t	MatchContact_() const;
};
#endif
