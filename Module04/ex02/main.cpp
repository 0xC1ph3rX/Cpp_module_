#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#include <iostream>
#include <sstream>

static void section(const std::string& title) {
	std::cout << "\n=== " << title << " ===" << std::endl;
}

static std::string ideaFor(const std::string& prefix, int idx) {
	std::ostringstream oss;
	oss << prefix << idx;
	return oss.str();
}

static void setIdeaOnAnimal(AAnimal* animal, int idx, const std::string& idea) {
	Dog* dog = dynamic_cast<Dog*>(animal);
	if (dog) {
		dog->setIdea(idx, idea);
		return;
	}
	Cat* cat = dynamic_cast<Cat*>(animal);
	if (cat) {
		cat->setIdea(idx, idea);
	}
}

static std::string getIdeaFromAnimal(const AAnimal* animal, int idx) {
	const Dog* dog = dynamic_cast<const Dog*>(animal);
	if (dog) {
		return dog->getIdea(idx);
	}
	const Cat* cat = dynamic_cast<const Cat*>(animal);
	if (cat) {
		return cat->getIdea(idx);
	}
	return "";
}

int main() {
	section("Abstract base via AAnimal");
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();
	std::cout << j->getType() << " created." << std::endl;
	std::cout << i->getType() << " created." << std::endl;
	i->makeSound();
	j->makeSound();
	delete j;
	delete i;

	section("Animal array with brains");
	const int count = 6;
	AAnimal* zoo[count];
	for (int idx = 0; idx < count; ++idx) {
		if (idx < count / 2) {
			zoo[idx] = new Dog();
		} else {
			zoo[idx] = new Cat();
		}
		setIdeaOnAnimal(zoo[idx], 0, ideaFor("Idea-", idx));
	}
	for (int idx = 0; idx < count; ++idx) {
		std::cout << "zoo[" << idx << "] " << zoo[idx]->getType();
		std::cout << " idea0: " << getIdeaFromAnimal(zoo[idx], 0) << std::endl;
		zoo[idx]->makeSound();
	}
	for (int idx = 0; idx < count; ++idx) {
		delete zoo[idx];
	}

	section("Deep copy test: Dog");
	Dog originalDog;
	originalDog.setIdea(0, "Guard the yard");
	Dog copiedDog(originalDog);
	std::cout << "original brain: " << originalDog.getBrain() << std::endl;
	std::cout << "copied brain:   " << copiedDog.getBrain() << std::endl;
	originalDog.setIdea(0, "Chase birds");
	std::cout << "original idea: " << originalDog.getIdea(0) << std::endl;
	std::cout << "copied idea:   " << copiedDog.getIdea(0) << std::endl;

	section("Deep copy test: Cat assignment");
	Cat firstCat;
	firstCat.setIdea(1, "Nap in the sun");
	Cat secondCat;
	secondCat = firstCat;
	std::cout << "first brain:  " << firstCat.getBrain() << std::endl;
	std::cout << "second brain: " << secondCat.getBrain() << std::endl;
	firstCat.setIdea(1, "Climb curtains");
	std::cout << "first idea:  " << firstCat.getIdea(1) << std::endl;
	std::cout << "second idea: " << secondCat.getIdea(1) << std::endl;

	section("Wrong animal demo");
	WrongAnimal* wmeta = new WrongAnimal();
	WrongCat* wrongCat = new WrongCat();
	WrongAnimal* wcat = wrongCat;
	wmeta->makeSound();
	wcat->makeSound();
	wrongCat->makeSound();
	delete wmeta;
	delete wrongCat;

	return 0;
}
