#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#include <iostream>

static void section(const std::string& title) {
		std::cout << "\n=== " << title << " ===" << std::endl;
}

int main() {
	section("Polymorphism basics");
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << "j type: " << j->getType() << std::endl;
	std::cout << "i type: " << i->getType() << std::endl;

	i->makeSound();
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;

	section("Stack objects and copy");
	Dog dog;
	Dog dogCopy(dog);
	Cat cat;
	cat = Cat();
	std::cout << "dogCopy type: " << dogCopy.getType() << std::endl;
	dogCopy.makeSound();
	cat.makeSound();

	section("Wrong animal demo");
	WrongAnimal* wmeta = new WrongAnimal();
	WrongCat* wrongCat = new WrongCat();
	WrongAnimal* wcat = wrongCat;

	std::cout << "wmeta type: " << wmeta->getType() << std::endl;
	std::cout << "wcat type: " << wcat->getType() << std::endl;

	wmeta->makeSound();
	wcat->makeSound();
	wrongCat->makeSound();

	delete wmeta;
	delete wrongCat;

	return 0;
}
