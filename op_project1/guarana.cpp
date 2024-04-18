#include "guarana.h"

Guarana::Guarana(Point pos) {
	this->power = 0;
	this->initiative = 0;
	this->age = 0;
	this->position = pos;
	this->type = GUARANA;
}

Guarana::Guarana(World* world, Point pos) {
	this->power = 0;
	this->initiative = 0;
	this->age = 0;
	this->position = pos;
	this->type = GUARANA;
	this->world = world;
}

Creature* Guarana::create(World* world, Point pos) {
	return new Guarana(world, pos);
}

void Guarana::action() {
	Point* positions = world->get_free_neighbours(this->position);
	plant_new(world, positions);
}

bool Guarana::collision(Creature* creature) {
	int power = creature->getPower();
	creature->setPower(power + 3);
	log_event(std::cout, creature->getType(), type, EAT);
	return true;
}

void Guarana::draw()
{
}

Guarana::~Guarana()
{
}
