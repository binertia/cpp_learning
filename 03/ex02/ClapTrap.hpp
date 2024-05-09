#pragma once
#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {
public:
	ClapTrap();
	ClapTrap(const std::string &name);
	ClapTrap(const ClapTrap& obj);
	ClapTrap &operator=(const ClapTrap& obj);
	virtual ~ClapTrap();

	virtual void attack(const std::string &target);
	virtual void takeDamage(unsigned int amount);
	virtual void beRepaired(unsigned int amount);

protected:
	std::string name_;
	size_t hp_;
	size_t ep_;
	size_t atk_;
};

#endif
