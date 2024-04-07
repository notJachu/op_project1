#include "creature.h"

std::ostream& operator<<(std::ostream& os, const Creature& creature) {
	creature.print(os);
	return os;
}

Creature::~Creature() {
}