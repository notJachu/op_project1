#include "antylopa.h"
#include "antylopa.h"
#include "antylopa.h"

bool Antylopa::run() {
	int will_run = rand() % 2;
	if (will_run == 0) return false;
	
	Point* free = world->get_free_neighbours(this->position);

	int pos = rand() % 4;
	if (free[pos].x != -1) {
		world->updateCreaturePosition(this->position, free[pos]);
		return true;
	}
	else {
		for (int i = 0; i < 4; i++) {
			if (free[i].x != -1) {
				world->updateCreaturePosition(this->position, free[i]);
				return true;
			}
		}
	}
	return false;
}

Antylopa::Antylopa(int power, int initiative, int age, Point position, World* world) {
	this->power = power;
	this->initiative = initiative;
	this->age = age;
	this->position = position;
	this->world = world;
	this->type = ANTYLOPA;
}

Antylopa::Antylopa(World* world, Point pos) {
	this->power = 4;
	this->initiative = 4;
	this->age = 0;
	this->position = pos;
	this->type = ANTYLOPA;
	this->world = world;
}

void Antylopa::draw()
{
}

Point Antylopa::move() const {
	Point positions[12]{};
	int count_positions = 0;

	for (int i = 0; i < 12; i++) positions[i] = { -1, -1 };

	if (position.x - 1 >= 0) {
		positions[count_positions] = { position.x - 1, position.y };
		count_positions++;

		if (position.y - 1 >= 0) {
			positions[count_positions] = { position.x - 1, position.y - 1 };
			count_positions++;
		}

		if (position.y + 1 < world->getHeight()) {
			positions[count_positions] = { position.x - 1, position.y + 1 };
			count_positions++;
		}

	}

	if (position.x - 2 >= 0) {
		positions[count_positions] = { position.x - 2, position.y };
		count_positions++;
	}

	if (position.x + 1 < world->getWidth()) {
		positions[count_positions] = { position.x + 1, position.y };
		count_positions++;

		if (position.y - 1 >= 0) {
			positions[count_positions] = { position.x + 1, position.y - 1 };
			count_positions++;
		}

		if (position.y + 1 < world->getHeight()) {
			positions[count_positions] = { position.x + 1, position.y + 1 };
			count_positions++;
		}
	}

	if (position.x + 2 < world->getWidth()) {
		positions[count_positions] = { position.x + 2, position.y };
		count_positions++;
	}

	if (position.y - 1 >= 0) {
		positions[count_positions] = { position.x, position.y - 1 };
		count_positions++;
	}

	if (position.y - 2 >= 0) {
		positions[count_positions] = { position.x, position.y - 2 };
		count_positions++;
	}

	if (position.y + 1 < world->getHeight()) {
		positions[count_positions] = { position.x, position.y + 1 };
		count_positions++;
	}

	if (position.y + 2 < world->getHeight()) {
		positions[count_positions] = { position.x, position.y + 1 };
		count_positions++;
	}


	if (count_positions == 0) return position;

	int direction = rand() % count_positions;


	return positions[direction];

}

bool Antylopa::collision(Creature* creature) {
	bool will_run = run();
	if (will_run) return true;

	int pow = creature->getPower();

	if (pow < this->power) {
		creature->kill();
	}
	else {
		kill();
		return true;
	}
	return false;
}

void Antylopa::print(std::ostream& os) const {
	os << "Antylopa: power=" << power << " initiative=" << initiative << " age=" << age << " position=(" << position.x << "," << position.y << ")";
}

Antylopa::~Antylopa()
{
}
