#include "mlecz.h"

Mlecz::Mlecz(Point pos) {
	this->power = 0;
	this->initiative = 0;
	this->age = 0;
	this->position = pos;
}

Mlecz::Mlecz(World* world, Point pos) {
	this->power = 0;
	this->initiative = 0;
	this->age = 0;
	this->position = pos;
	this->world = world;
}

void Mlecz::action() {
	// 3 attempts to plant new Mlecz	
	for (int i = 0; i < 3; i++) {
		Point* positions = world->get_free_neighbours(this->position);
		plant_new(world, positions);
	}
}

void Mlecz::collision(Creature* creature)
{
}

void Mlecz::draw()
{
}

Mlecz::~Mlecz()
{
}
