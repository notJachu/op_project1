#include "Cz這wiek.h"
#include "stdio.h"
#include <iostream>
#include "../../world.h"


Cz這wiek::Cz這wiek(int power, int initiative, int age, Point position, World* world) {
	this->power = power;
	this->initiative = initiative;
	this->age = age;
	this->position = position;
	this->type = STUDENT;
	this->world = world;
}

Cz這wiek::Cz這wiek(World* world, Point pos) {
	this->power = 5;
	this->initiative = 4;
	this->age = 0;
	this->position = pos;
	this->type = STUDENT;
	this->world = world;
}

Creature* Cz這wiek::create(World* world, Point pos) {
	return new Cz這wiek(world, pos);
}

void Cz這wiek::draw()
{
}

Point Cz這wiek::move() const {
	return Point();
}

void Cz這wiek::action() {
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

bool Cz這wiek::collision(Creature* creature) {
	return false;
}

void Cz這wiek::print(std::ostream& os) const {
	os << "Cz這wiek: power=" << power << " initiative=" << initiative << " age=" << age << " position=(" << position.x << "," << position.y << ")";
}

Cz這wiek::~Cz這wiek()
{
}
