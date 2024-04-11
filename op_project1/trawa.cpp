#include "trawa.h"

Trawa::Trawa(Point pos) {
	this->power = 0;
	this->initiative = 0;
	this->age = 0;
	this->position = pos;
	this->type = TRAWA;
}

Trawa::Trawa(World* world, Point pos) {
	this->power = 0;
	this->initiative = 0;
	this->age = 0;
	this->position = pos;
	this->type = TRAWA;
	this->world = world;
}

void Trawa::action() {
	Point* positions = world->get_free_neighbours(this->position);
	plant_new(world, positions);
	for (int i = 0; i < 4; i++) {
		std::cout<< positions[i].x << " " << positions[i].y << std::endl;
	}
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
