#include "mlecz.h"

Mlecz::Mlecz(Point pos) {
	this->power = 0;
	this->initiative = 0;
	this->age = 0;
	this->position = pos;
	this->type = MLECZ;
}

Mlecz::Mlecz(World* world, Point pos) {
	this->power = 0;
	this->initiative = 0;
	this->age = 0;
	this->position = pos;
	this->type = MLECZ;
	this->world = world;
}

Creature* Mlecz::create(World* world, Point pos) {
	return new Mlecz(world, pos);
}

void Mlecz::action() {
	// 3 attempts to plant new Mlecz	
	for (int i = 0; i < 3; i++) {
		Point* positions = world->get_free_neighbours(this->position);
		plant_new(world, positions);
	}
}

bool Mlecz::collision(Creature* creature) {
	log_event(std::cout, creature->getType(), type, EAT);
	return true;
}

void Mlecz::draw()
{
}

Mlecz::~Mlecz()
{
}
