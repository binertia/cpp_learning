#include "Dog.hpp"
#include "Cat.hpp"

class WrongAnimal : public Dog, public Cat {
	public:
		WrongAnimal();
		virtual ~WrongAnimal();
		void makeSound() const;
};
