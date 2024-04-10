#include "plant.h"
#include "types.h"
#include "ctime"

void Plant::print(std::ostream& os) const {
	os << "Plant: power=" << power << " initiative=" << initiative << " age=" << age << " position=(" << position.x << "," << position.y << ")";
}

void Plant::plant_new(World* world, Point* positions) {
	srand(time(NULL));

	// 50% chance to plant
	int will_plant = rand() % 100;
	if (will_plant < 50) {
		return;
	}


	// tries to plant in rolled position
	// if it can't plant there it picks first free position
	int pos = rand() % 4;
	if (positions[pos].x != -1) {
		world->addCreature(new Plant(power, initiative, 0, positions[pos], world));
	}
	else {
		for (int i = 0; i < 4; i++) {
			if (positions[i].x != -1) {
				world->addCreature(new Plant(power, initiative, 0, positions[i], world));
				break;
			}
		}
	}
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
	this->world = nullptr;
}

Plant::Plant(World* world) {
	this->power = 0;
	this->initiative = 0;
	this->age = 0;
	this->position = { 0, 0 };
	this->world = world;
}

void Plant::action() {
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

void Plant::kill()
{
}

Plant::~Plant()
{
}
