#include "AAnimal.hpp"
#include "Console.hpp"

AAnimal::AAnimal() : type("AAnimal") {
	Console::log(Console::cyan(), "AAnimal", "boots a silent shell.");
}

AAnimal::AAnimal(const AAnimal& other) : type(other.type) {
	Console::log(Console::cyan(), "AAnimal", "copy echoes the shell.");
}

AAnimal& AAnimal::operator=(const AAnimal& other) {
	Console::log(Console::cyan(), "AAnimal", "syncs its type.");
	if (this != &other) {
		type = other.type;
	}
	return *this;
}

AAnimal::~AAnimal() {
	Console::log(Console::cyan(), "AAnimal", "leaves the stage.");
}

std::string AAnimal::getType() const {
	return type;
}
