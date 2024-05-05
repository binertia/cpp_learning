#pragma once
#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class	Weapon {
	public:
		Weapon(const std::string type);
		~Weapon();
		
		void	setType(const std::string new_type);
		const std::string getType();

	private:
		std::string type_;
};

#endif
