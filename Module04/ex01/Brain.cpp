#include "Brain.hpp"
#include "Console.hpp"

Brain::Brain() {
	Console::log(Console::blue(), "Brain", "spins up 100 slots.");
	for (int i = 0; i < 100; ++i) {
		ideas[i] = "";
	}
}

Brain::Brain(const Brain& other) {
	Console::log(Console::blue(), "Brain", "copy syncs memories.");
	for (int i = 0; i < 100; ++i) {
		ideas[i] = other.ideas[i];
	}
}

Brain& Brain::operator=(const Brain& other) {
	Console::log(Console::blue(), "Brain", "rewrites its stack.");
	if (this != &other) {
		for (int i = 0; i < 100; ++i) {
			ideas[i] = other.ideas[i];
		}
	}
	return *this;
}

Brain::~Brain() {
	Console::log(Console::blue(), "Brain", "shuts down.");
}

void Brain::setIdea(int index, const std::string& idea) {
	if (index < 0 || index >= 100) {
		return;
	}
	ideas[index] = Console::leetify(idea);
}

std::string Brain::getIdea(int index) const {
	if (index < 0 || index >= 100) {
		return "";
	}
	return ideas[index];
}
