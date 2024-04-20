#include "Cz�owiek.h"
#include "stdio.h"
#include <iostream>
#include "../../world.h"


Cz�owiek::Cz�owiek(int power, int initiative, int age, Point position, World* world) {
	this->power = power;
	this->initiative = initiative;
	this->age = age;
	this->position = position;
	this->type = STUDENT;
	this->world = world;
}

Cz�owiek::Cz�owiek(World* world, Point pos) {
	this->power = 5;
	this->initiative = 4;
	this->age = 0;
	this->position = pos;
	this->type = STUDENT;
	this->world = world;
}

Creature* Cz�owiek::create(World* world, Point pos) {
	return new Cz�owiek(world, pos);
}

void Cz�owiek::draw()
{
}

Point Cz�owiek::move() const {
	return Point();
}

void Cz�owiek::action() {
	int ability = world->getPlayerAbility();
	if (ability == 0) {
		power += 5;
	}
	if (ability < 0 && ability >= -5 ) {
		power -= 1;	
	}
	if (ability > -10) {
		world->setPlayerAbility(ability - 1);
	}

	direction dir = world->get_player_input();

	switch (dir)
	{
	case LEFT: if (position.x - 1 >= 0) {
		world->updateCreaturePosition(this->position, { position.x - 1, position.y });
		position.x--;
	}
		break;
	case RIGHT:
		if (position.x + 1 < world->getHeight()) {
			world->updateCreaturePosition(this->position, { position.x + 1, position.y });
			position.x++;
		}
		break;
	case UP:
		if (position.y - 1 >= 0) {
			world->updateCreaturePosition(this->position, { position.x, position.y - 1 });
			position.y--;
		}
		break;
	case DOWN:
		if (position.y + 1 < world->getWidth()) {
			world->updateCreaturePosition(this->position, { position.x, position.y + 1 });
			position.y++;
		}
		break;
	default:
		break;
	}
	
}

bool Cz�owiek::collision(Creature* creature) {
	return false;
}

void Cz�owiek::print(std::ostream& os) const {
	os << "Cz�owiek: power=" << power << " initiative=" << initiative << " age=" << age << " position=(" << position.x << "," << position.y << ")";
}

Cz�owiek::~Cz�owiek()
{
}
