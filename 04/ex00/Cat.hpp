#include "Animal.hpp"

class Cat : public virtual Animal{
	public:
		Cat();
		virtual ~Cat();

		void makeSound() const;
};
