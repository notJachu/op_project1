#include "lis.h"

Lis::Lis(int power, int initiative, int age, Point position, World* world) {
	this->power = power;
	this->initiative = initiative;
	this->age = age;
	this->position = position;
	this->type = LIS;
	this->world = world;
}

Lis::Lis(World* world, Point pos) {
	this->power = 3;
	this->initiative = 7;
	this->age = 0;
	this->position = pos;
	this->type = LIS;
	this->world = world;
}

void Lis::draw()
{
}

Point Lis::move() const {
	Point positions[4]{};
	int count_positions = 0;

	for (int i = 0; i < 4; i++) positions[i] = { -1, -1 };

	Creature* creature = nullptr;

	if (position.x - 1 >= 0) {
		creature = world->getCreature(position.x - 1, position.y);
		if (creature != nullptr && creature->getPower() <= power) {
			positions[count_positions] = { position.x - 1, position.y };
			count_positions++;
		}
	}
	if (position.x + 1 < world->getWidth()) {
		creature = world->getCreature(position.x + 1, position.y);
		if (creature != nullptr && creature->getPower() <= power) {
			positions[count_positions] = { position.x + 1, position.y };
			count_positions++;
		}
	}
	if (position.y - 1 >= 0) {
		creature = world->getCreature(position.x, position.y - 1);
		if (creature != nullptr && creature->getPower() <= power) {
			positions[count_positions] = { position.x, position.y - 1 };
			count_positions++;
		}
	}
	if (position.y + 1 < world->getHeight()) {
		creature = world->getCreature(position.x, position.y + 1);
		if (creature != nullptr && creature->getPower() <= power) {
			positions[count_positions] = { position.x, position.y + 1 };
			count_positions++;
		}
	}

	if (count_positions == 0) return position;

	int direction = rand() % count_positions;


	return positions[direction];
}


Lis::~Lis()
{
}
