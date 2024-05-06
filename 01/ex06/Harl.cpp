#include "Harl.hpp"

Harl::Harl() {
	function_ptr_[0] = &Harl::debug_;
	function_ptr_[1] = &Harl::info_;
	function_ptr_[2] = &Harl::warning_;
	function_ptr_[3] = &Harl::error_;
	function_ptr_[4] = &Harl::etc_;
}

Harl::~Harl() {

}

void	Harl::complain(std::string level) {
	std::string level_arr[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	size_t	i = 0;

	while (i < 4 && level.compare(level_arr[i])) {
		i++;
	}
	/* if (i < 4) */
	/* 	(this->*function_ptr_[i])(); */
	switch (i) {
		case 0:
			(this->*function_ptr_[0])();
			break;
		case 1:
			(this->*function_ptr_[1])();
			break;
		case 2:
			(this->*function_ptr_[2])();
			break;
		case 3:
			(this->*function_ptr_[3])();
			break;
		default:
			(this->*function_ptr_[4])();
			break;
	}
}

void	Harl::debug_() {
	std::cout << "[ DEBUG ]\n";
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger.\nI really do!\n" << std::endl;
	info_();
}

void	Harl::info_() {
	std::cout << "[ INFO ]\n";
	std::cout << "I cannot believe adding extra bacon costs more money.\nYou didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n" << std::endl;
	warning_();
}

void	Harl::warning_() {
	std::cout << "[ WARNING ]\n";
	std::cout << "I think I deserve to have some extra bacon for free.\nI’ve been coming for years whereas you started working here since last month.\n" << std::endl;
	error_();
}

void	Harl::error_() {
	std::cout << "[ ERROR ]\n";
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::etc_() {
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}

// syntax call function by ptr : 
//		inside  " use : '->*' with 'this' key word" eg. "this->*ptr()" :: "(this->*ptr[i])()"
//		outside : "<obj>.*ptr()" :: "(<obj>.*ptr[i])()";
