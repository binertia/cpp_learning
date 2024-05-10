#pragma once
#ifndef ANIMAL_HPP

#include <iostream>

class Animal {
public:
	Animal();
	virtual ~Animal();
	Animal(const Animal &other);
	Animal &operator=(const Animal &other);

	std::string getType() const;
	virtual void makeSound() const;
protected:
	std::string type_;
};

#endif // !ANIMAL_HPP
