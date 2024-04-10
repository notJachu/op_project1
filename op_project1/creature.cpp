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

int Creature::getPower() {
	return this->power;
}

int Creature::getInitiative() {
	return this->initiative;
}

int Creature::getAge() {
	return this->age;
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

Creature::~Creature() {
}