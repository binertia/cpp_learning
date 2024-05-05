#pragma once
#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanA {
	public:
		HumanA(const std::string name, Weapon &weapon);
		~HumanA();

		void attack();

	private:
		Weapon &weapon_;
		std::string name_;
};

#endif
