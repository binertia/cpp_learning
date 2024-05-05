#pragma once
#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <iostream>

class Zombie {
	public:
		Zombie(); // default construct
		Zombie(const std::string name_);
		~Zombie();

		void	announce(void);

	private:
		std::string name_;
};

Zombie	*newZombie(std::string name);

void	randomChump(std::string name);
#endif
