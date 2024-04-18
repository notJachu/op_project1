#include "Cz�owiek.h"
#include "World.h"
#include "stdio.h"
#include <iostream>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_PRE 224

Cz�owiek::Cz�owiek(int power, int initiative, int age, Point position, World* world) {
	this->power = power;
	this->initiative = initiative;
	this->age = age;
	this->position = position;
	this->type = STUDENT;
	this->world = world;
	this->cooldown = 0;
	this->superpower = false;
}

Cz�owiek::Cz�owiek(World* world, Point pos) {
	this->power = 5;
	this->initiative = 4;
	this->age = 0;
	this->position = pos;
	this->type = STUDENT;
	this->world = world;
	this->cooldown = 0;
	this->superpower = false;
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
	int c = 0;

	switch (c = _getwch()) {
	case KEY_UP:
		//std::cout << std::endl << "Up" << std::endl;	//key up
		if (position.x - 1 >= 0) {
			world->updateCreaturePosition(this->position, { position.x - 1, position.y });
			position.x--;
		}
		break;
	case KEY_DOWN:
		//std::cout << std::endl << "Down" << std::endl;   // key down
		if (position.x + 1 < world->getHeight()) {
			world->updateCreaturePosition(this->position, { position.x + 1, position.y });
			position.x++;
		}
		break;
	case KEY_LEFT:
		//std::cout << std::endl << "Left" << std::endl;  // key left
		if (position.y - 1 >= 0) {
			world->updateCreaturePosition(this->position, { position.x, position.y - 1 });
			position.y--;
		}
		break;
	case KEY_RIGHT:
		//std::cout << std::endl << "Right" << std::endl;  // key right
		if (position.y + 1 < world->getWidth()) {
			world->updateCreaturePosition(this->position, { position.x, position.y + 1 });
			position.y++;
		}
		break;
	default:
		//std::cout << std::endl << "null" << std::endl;  // not arrow
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
