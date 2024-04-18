#include "plant.h"
#include "types.h"
#include "ctime"

void Plant::print(std::ostream& os) const {
	os << "Plant: power=" << power << " initiative=" << initiative << " age=" << age << " position=(" << position.x << "," << position.y << ")";
}

 void Plant::plant_new(World* world, Point* positions) {
	srand(time(NULL));

	// 25% chance to plant
	int will_plant = rand() % 100;
	if (will_plant < 25) {
		return;
	}


	// tries to plant in rolled position
	// if it can't plant there it picks first free position
	int pos = rand() % 4;
	if (positions[pos].x != -1) {
		//std::cout << this->type << std::endl;
		Creature* creature = this->create(world, positions[pos]);
		world->addCreature(creature);
		log_event(std::cout, type, type, PLANT);
	}
	else {
		for (int i = 0; i < 4; i++) {
			if (positions[i].x != -1) {
				//std::cout << this->type << std::endl;
				Creature* creature = this->create(world, positions[i]);
				world->addCreature(creature);
				log_event(std::cout, type, type, PLANT);
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

bool Plant::collision(Creature* creature) {
	log_event(std::cout, creature->getType(), type, EAT);
	return true;
}

Creature* Plant::create(World* world, Point pos) {
	return nullptr;
}

void Plant::draw()
{
}

void Plant::setWorld(World* world) {
	this->world = world;
}

void Plant::kill() {
	world->removeCreature(this);
}

Plant::~Plant()
{
}
