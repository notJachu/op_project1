#include "creature.h"

std::ostream& operator<<(std::ostream& os, const Creature& creature) {
	creature.print(os);
	return os;
}


int Creature::getX() {
	return this->position.x;
}

int Creature::getY() {
	return this->position.y;
}

Creature::~Creature() {
}