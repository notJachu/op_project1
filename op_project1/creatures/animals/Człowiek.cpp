#include "Człowiek.h"
#include "stdio.h"
#include <iostream>
#include "../../world.h"


Człowiek::Człowiek(int power, int initiative, int age, Point position, World* world) {
	this->power = power;
	this->initiative = initiative;
	this->age = age;
	this->position = position;
	this->type = STUDENT;
	this->world = world;
}

Człowiek::Człowiek(World* world, Point pos) {
	this->power = 5;
	this->initiative = 4;
	this->age = 0;
	this->position = pos;
	this->type = STUDENT;
	this->world = world;
}

Creature* Człowiek::create(World* world, Point pos) {
	return new Człowiek(world, pos);
}

void Człowiek::draw()
{
}

Point Człowiek::move() const {
	return Point();
}

void Człowiek::action() {
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

bool Człowiek::collision(Creature* creature) {
	return false;
}

void Człowiek::print(std::ostream& os) const {
	os << "Człowiek: power=" << power << " initiative=" << initiative << " age=" << age << " position=(" << position.x << "," << position.y << ")";
}

Człowiek::~Człowiek()
{
}
