#include "creature.h"

std::ostream& operator<<(std::ostream& os, const Creature& creature) {
	creature.print(os);
	return os;
}


void Creature::log_event(std::ostream& os, creature_type first, creature_type second, event_type event) {
	const char* a1 = get_name(first);
	const char* a2 = get_name(second);

	switch (event) {
	case FLEE:
		os << a1 << " has fled from " << a2 << std::endl;
		break;
	case KILL:
		os << a1 << " has killed " << a2 << std::endl;
		break;
	case REPRODUCE:
		os << a1 << " has reproduced" << std::endl;
		break;
	case EAT:
		os << a1 << " has eaten " << a2 << std::endl;
		break;
	case DEFEND:
		os << a1 << " has defended from " << a2 << std::endl;
		break;
	case PLANT:
		os << a1 << " has replanted" << std::endl;
		break;
	case MOVE:
		os << a1 << " has moved" << std::endl;
		break;
	default:
		os << "Unknown event\n";
		break;
	}
}

int Creature::getX() {
	return this->position.x;
}

int Creature::getY() {
	return this->position.y;
}

int Creature::getPower() {
	return this->power;
}

int Creature::getInitiative() {
	return this->initiative;
}

int Creature::getAge() {
	return this->age;
}

creature_type Creature::getType(){
	return this->type;
}

void Creature::setX(int x) {
	this->position.x = x;
}

void Creature::setY(int y) {
	this->position.y = y;
}

void Creature::setPower(int power) {
	this->power = power;
}

void Creature::setInitiative(int initiative) {
	this->initiative = initiative;
}

void Creature::setAge(int age) {
	this->age = age;
}

void Creature::increment_age() {
	this->age++;
}

Creature::~Creature() {
}