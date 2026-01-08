#include "Cat.hpp"
#include "Console.hpp"

Cat::Cat() : Animal(), brain(new Brain()) {
	type = "Cat";
	Console::log(Console::yellow(), "Cat", "slips in, whiskers first.");
}

Cat::Cat(const Cat& other) : Animal(other), brain(new Brain(*other.brain)) {
	Console::log(Console::yellow(), "Cat", "shadow doubles.");
}

Cat& Cat::operator=(const Cat& other) {
	Console::log(Console::yellow(), "Cat", "swaps moods.");
	if (this != &other) {
		Animal::operator=(other);
		if (!brain) {
			brain = new Brain();
		}
		*brain = *other.brain;
	}
	return *this;
}

Cat::~Cat() {
	delete brain;
	Console::log(Console::yellow(), "Cat", "vanishes into a box.");
}

void Cat::makeSound() const {
	Console::log(Console::yellow(), "Cat", "says: M3e0w.");
}

void Cat::setIdea(int index, const std::string& idea) {
	if (brain) {
		brain->setIdea(index, idea);
	}
}

std::string Cat::getIdea(int index) const {
	if (brain) {
		return brain->getIdea(index);
	}
	return "";
}

const Brain* Cat::getBrain() const {
	return brain;
}
