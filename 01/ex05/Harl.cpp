#include "Harl.hpp"

Harl::Harl() {
	function_ptr_[0] = &Harl::debug_;
	function_ptr_[1] = &Harl::info_;
	function_ptr_[2] = &Harl::warning_;
	function_ptr_[3] = &Harl::error_;
}

Harl::~Harl() {

}

void	Harl::complain(std::string level) {
	std::string level_arr[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	size_t	i = 0;

	while (i < 4 && level.compare(level_arr[i])) {
		i++;
	}
	if (i < 4)
		(this->*function_ptr_[i])();
}

void	Harl::debug_() {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!" << std::endl;
}

void	Harl::info_() {
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning_() {
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error_() {
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

// syntax call function by ptr : 
//		inside  " use : '->*' with 'this' key word" eg. "this->*ptr()" :: "(this->*ptr[i])()"
//		outside : "<obj>.*ptr()" :: "(<obj>.*ptr[i])()";

