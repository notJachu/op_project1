#include "trawa.h"
#include "../creature.h"
#include "../../world.h"

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

Trawa::Trawa(int power, int initiative, int age, Point position, World* world) {
	this->power = power;
	this->initiative = initiative;
	this->age = age;
	this->position = position;
	this->type = TRAWA;
	this->world = world;
}

Creature* Trawa::create(World* world, Point pos) {
	return new Trawa(world, pos);
}

void Trawa::action() {
	Point* positions = world->get_free_neighbours(this->position);
	plant_new(world, positions);
	/*for (int i = 0; i < 4; i++) {
		std::cout<< positions[i].x << " " << positions[i].y << std::endl;
	}*/
}

bool Trawa::collision(Creature* creature) {
	log_event(std::cout, creature->getType(), type, EAT);
	return true;
}

void Trawa::draw()
{
}

Trawa::~Trawa() {
	std::cout << "Trawa destruktor" << std::endl;
}
