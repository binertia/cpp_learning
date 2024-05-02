#include "Contact.hpp"

Contact::Contact(void)
{
}

Contact::~Contact(void)
{
}

const	std::string	Contact::FillData(std::string form) {
	bool checker = false;
	std::string	input = "";
	std::string error_in_message = "Not sure it was input issue or skill issue. However, please try again.";

	std::cout << form << std::flush;
	while (!checker) {
		std::getline(std::cin, input);
		if (!std::cin.good() || input.empty())
			std::cout << error_in_message << std::endl;
		else
			checker = !checker;
	}
	return (input);
}

void	Contact::MakeData(size_t index) {
	Contact::SetIndex_(index);
	Contact::SetFirstName_();
	Contact::SetLastName_();
	Contact::SetNickName_();
	Contact::SetPhoneNumber_();
	Contact::SetDarkestSecret_();
}

bool	Contact::ValidIndex(size_t index) {
	if (index == this->GetIndex_())
		return (true);
	return (false);
}

void	Contact::DisplaySampleContact(void) {
	std::cout << "|" << std::setw(10) << Contact::GetIndex_() << std::flush;
	std::cout << "|" << std::setw(10) << Contact::GetFirstName_() << std::flush;
	std::cout << "|" << std::setw(10) << Contact::GetLastName_() << std::flush;
	std::cout << "|" << std::setw(10) << Contact::GetNickName_() << "|" <<std::endl;
};

void	Contact::DisplayFullContact(void) {
	std::string id_mes = "Contact no. ";
	std::string fn_mes = "First name : ";
	std::string ln_mes = "Last name : ";
	std::string nn_mes = "Nick name : ";
	std::string pn_mes = "Phone number : ";
	std::string ds_mes = "Darkest secret : ";

	std::cout << id_mes << Contact::GetIndex_() << "\n";
	std::cout << fn_mes << Contact::GetFirstName_() << "\n";
	std::cout << ln_mes << Contact::GetLastName_() << "\n";
	std::cout << nn_mes << Contact::GetNickName_() << "\n";
	std::cout << pn_mes << Contact::GetPhoneNumber_() << "\n";
	std::cout << ds_mes << Contact::GetDarkestSecret_() << std::endl;
}

//setter
void	Contact::SetIndex_(size_t index) {
	this->index_ = index;
}

void	Contact::SetFirstName_(void) {
	const std::string fn_form = "please fill first name :";
	this->first_name_ = this->FillData(fn_form);
}

void	Contact::SetLastName_(void) {
	const std::string ln_form= "please fill last name :";
	this->last_name_ = this->FillData(ln_form);
}

void	Contact::SetNickName_(void) {
	const std::string nn_form = "please fill nick name :";
	this->nick_name_ = this->FillData(nn_form);
}

void	Contact::SetPhoneNumber_(void) {
	const std::string pn_form = "please fill phone number :";
	this->phone_number_ = this->FillData(pn_form);
}

void	Contact::SetDarkestSecret_(void) {
	const std::string ds_form = "please fill darkest secret :";
	this->darkest_secret_ = this->FillData(ds_form);
}

//getter
size_t	Contact::GetIndex_(void) {
	return (this->index_);
}
const std::string Contact::GetFirstName_(void) {
	return (this->first_name_);
}

const std::string Contact::GetLastName_(void) {
	return (this->last_name_);
}

const std::string Contact::GetNickName_(void) {
	return (this->nick_name_);
}

const std::string Contact::GetPhoneNumber_(void) {
	return (this->phone_number_);
}

const std::string Contact::GetDarkestSecret_(void) {
	return (this->darkest_secret_);
}
