#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
	public:
		WrongCat();
		virtual ~WrongCat();
		using Dog::makeSound;
		void makeSound() const;
};
