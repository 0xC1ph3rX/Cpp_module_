#include "WrongAnimal.hpp"
#include "Console.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
	Console::log(Console::red(), "WrongAnimal", "boots the wrong script.");
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type) {
	Console::log(Console::red(), "WrongAnimal", "clone repeats the glitch.");
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
	Console::log(Console::red(), "WrongAnimal", "copies the mistake.");
	if (this != &other) {
		type = other.type;
	}
	return *this;
}

WrongAnimal::~WrongAnimal() {
	Console::log(Console::red(), "WrongAnimal", "powers down.");
}

std::string WrongAnimal::getType() const {
	return type;
}

void WrongAnimal::makeSound() const {
	Console::log(Console::red(), "WrongAnimal", "emits a flat beep.");
}
