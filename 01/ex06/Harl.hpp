#pragma once
#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>

class Harl {
	public:
		Harl();
		~Harl();


		void complain(std::string level);

	private:
		typedef void (Harl::*function_ptr)(void);

		void debug_();
		void info_();
		void warning_();
		void error_();
		void etc_();
		
		function_ptr function_ptr_[5];
};

#endif
