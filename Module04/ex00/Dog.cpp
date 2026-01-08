#include "Dog.hpp"
#include "Console.hpp"

Dog::Dog() : Animal() {
	type = "Dog";
	Console::log(Console::green(), "Dog", "trots in, tail online.");
}

Dog::Dog(const Dog& other) : Animal(other) {
	Console::log(Console::green(), "Dog", "clone bounds in.");
}

Dog& Dog::operator=(const Dog& other) {
	Console::log(Console::green(), "Dog", "swaps tricks.");
	if (this != &other) {
		Animal::operator=(other);
	}
	return *this;
}

Dog::~Dog() {
	Console::log(Console::green(), "Dog", "curls up for the last nap.");
}

void Dog::makeSound() const {
	Console::log(Console::green(), "Dog", "says: W00f W00f!");
}
