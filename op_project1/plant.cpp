#include "plant.h"

void Plant::print(std::ostream& os) const {
	os << "Plant: power=" << power << " initiative=" << initiative << " age=" << age << " position=(" << position.x << "," << position.y << ")";
}

void Plant::plant_new(World* world) {
	world->addCreature(new Plant(power, initiative, 0, {position.x + 1, position.y}, world));
}

Plant::Plant(int power, int initiative, int age, Point position, World* world) {
	this->power = power;
	this->initiative = initiative;
	this->age = age;
	this->position = position;
	this->world = world;
}

Plant::Plant() {
	this->power = 0;
	this->initiative = 0;
	this->age = 0;
	this->position = { 0, 0 };
}

Plant::Plant(World* world) {
	this->power = 0;
	this->initiative = 0;
	this->age = 0;
	this->position = { 0, 0 };
	this->world = world;
}

void Plant::action() {
	plant_new(world);
}

void Plant::collision(Creature* creature)
{
}

void Plant::draw()
{
}

void Plant::setWorld(World* world) {
	this->world = world;
}

Plant::~Plant()
{
}
