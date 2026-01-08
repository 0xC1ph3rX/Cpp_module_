#include "Cat.hpp"
#include "Console.hpp"

Cat::Cat() : Animal() {
	type = "Cat";
	Console::log(Console::yellow(), "Cat", "slips in, whiskers first.");
}

Cat::Cat(const Cat& other) : Animal(other) {
	Console::log(Console::yellow(), "Cat", "shadow doubles.");
}

Cat& Cat::operator=(const Cat& other) {
	Console::log(Console::yellow(), "Cat", "swaps moods.");
	if (this != &other) {
		Animal::operator=(other);
	}
	return *this;
}

Cat::~Cat() {
	Console::log(Console::yellow(), "Cat", "vanishes into a box.");
}

void Cat::makeSound() const {
	Console::log(Console::yellow(), "Cat", "says: M3e0w.");
}
