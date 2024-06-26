#include "Animal.hpp"
#include "WrongCat.hpp"

int main() {
	const Animal* meta = new Animal();
	std::cout << "--------------" << std::endl;
	const Animal* j = new Dog();
	std::cout << "--------------" << std::endl;
	const Animal* i = new Cat();
	std::cout << "--------------" << std::endl;

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound! j->makeSound();
	meta->makeSound();

	std::cout << "--------------" << std::endl;
	delete meta;
	std::cout << "--------------" << std::endl;
	delete j;
	std::cout << "--------------" << std::endl;
	delete i;

	std::cout << "--------------" << std::endl;
	const WrongAnimal *not_meta = new WrongAnimal();
	std::cout << "--------------" << std::endl;
	const WrongCat *not_cat = new WrongCat();
	std::cout << "--------------" << std::endl;
	not_cat->makeSound();
	std::cout << "--------------" << std::endl;
	not_meta->makeSound();
	std::cout << "--------------" << std::endl;
	delete not_cat;
	std::cout << "--------------" << std::endl;
	delete not_meta;
	return 0;
}
