#include "Animal.hpp"

class Dog : public virtual Animal {
public:
	Dog();
	virtual ~Dog();

	void makeSound() const;
};
