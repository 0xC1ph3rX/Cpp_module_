#include "Dog.hpp"
#include "Console.hpp"

Dog::Dog() : Animal(), brain(new Brain()) {
	type = "Dog";
	Console::log(Console::green(), "Dog", "trots in, tail online.");
}

Dog::Dog(const Dog& other) : Animal(other), brain(new Brain(*other.brain)) {
	Console::log(Console::green(), "Dog", "clone bounds in.");
}

Dog& Dog::operator=(const Dog& other) {
	Console::log(Console::green(), "Dog", "swaps tricks.");
	if (this != &other) {
		Animal::operator=(other);
		if (!brain) {
			brain = new Brain();
		}
		*brain = *other.brain;
	}
	return *this;
}

Dog::~Dog() {
	delete brain;
	Console::log(Console::green(), "Dog", "curls up for the last nap.");
}

void Dog::makeSound() const {
	Console::log(Console::green(), "Dog", "says: W00f W00f!");
}

void Dog::setIdea(int index, const std::string& idea) {
	if (brain) {
		brain->setIdea(index, idea);
	}
}

std::string Dog::getIdea(int index) const {
	if (brain) {
		return brain->getIdea(index);
	}
	return "";
}

const Brain* Dog::getBrain() const {
	return brain;
}
