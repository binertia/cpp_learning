#pragma once
#include <string>
#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class	Zombie {
	public:
		Zombie();
		Zombie(const std::string name, size_t N);
		~Zombie();
		
		void announce(void);
		void setName(const std::string name);
		void setIndex(const size_t index);
	private:
		std::string name_;
		size_t	index_;
};

Zombie *zombieHorde(int N, std::string name);

#endif
