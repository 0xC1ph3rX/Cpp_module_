#include "WrongCat.hpp"
#include "Console.hpp"

WrongCat::WrongCat() : WrongAnimal() {
	type = "WrongCat";
	Console::log(Console::magenta(), "WrongCat", "loads a broken meow.");
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
	Console::log(Console::magenta(), "WrongCat", "clone misfires.");
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
	Console::log(Console::magenta(), "WrongCat", "copies the wrong meow.");
	if (this != &other) {
		WrongAnimal::operator=(other);
	}
	return *this;
}

WrongCat::~WrongCat() {
	Console::log(Console::magenta(), "WrongCat", "unplugs.");
}

void WrongCat::makeSound() const {
	Console::log(Console::magenta(), "WrongCat", "says: ???");
}
