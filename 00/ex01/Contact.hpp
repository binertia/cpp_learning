#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <cctype>
#include <iomanip>


class	Contact
{
	public:
		Contact();
		~Contact();

		const std::string	FillData(std::string form);
		void	MakeData(size_t index);
		bool	ValidIndex(size_t index);
		void	DisplaySampleContact();
		void	DisplayFullContact();

	private:
		void	SetIndex_(size_t index);
		void	SetFirstName_();
		void	SetLastName_();
		void	SetNickName_();
		void	SetPhoneNumber_();
		void	SetDarkestSecret_();

		size_t	GetIndex_();
		const std::string	GetFirstName_();
		const std::string	GetLastName_();
		const std::string	GetNickName_();
		const std::string	GetPhoneNumber_();
		const std::string	GetDarkestSecret_();

		size_t	index_;
		std::string	first_name_;
		std::string	last_name_;
		std::string nick_name_;
		std::string phone_number_;
		std::string darkest_secret_;
};

#endif
