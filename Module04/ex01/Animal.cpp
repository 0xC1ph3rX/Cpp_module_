#include "Animal.hpp"
#include "Console.hpp"

Animal::Animal() : type("Animal") {
	Console::log(Console::cyan(), "Animal", "wakes to a quiet baseline.");
}

Animal::Animal(const Animal& other) : type(other.type) {
	Console::log(Console::cyan(), "Animal", "copy steps in softly.");
}

Animal& Animal::operator=(const Animal& other) {
	Console::log(Console::cyan(), "Animal", "copies its silhouette.");
	if (this != &other) {
		type = other.type;
	}
	return *this;
}

Animal::~Animal() {
	Console::log(Console::cyan(), "Animal", "fades into stillness.");
}

std::string Animal::getType() const {
	return type;
}

void Animal::makeSound() const {
	Console::log(Console::cyan(), "Animal", "hums an undefined tone.");
}
