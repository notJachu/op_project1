#include "trawa.h"

Trawa::Trawa() {
	this->power = 0;
	this->initiative = 0;
	this->age = 0;
	this->position = { 0, 0 };
}

Trawa::Trawa(World* world) {
	this->power = 0;
	this->initiative = 0;
	this->age = 0;
	this->position = { 0, 0 };
	this->world = world;
}

void Trawa::action() {
	plant_new(world);
}

void Trawa::collision(Creature* creature)
{
}

void Trawa::draw()
{
}

Trawa::~Trawa() {
	std::cout << "Trawa destruktor" << std::endl;
}
