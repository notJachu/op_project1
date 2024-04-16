#include "wilk.h"

Wilk::Wilk(int power, int initiative, int age, Point position, World* world) {
	this->power = power;
	this->initiative = initiative;
	this->age = age;
	this->position = position;
	this->type = WILK;
	this->world = world;
}

Wilk::Wilk(World* world, Point pos) {
	this->power = 9;
	this->initiative = 5;
	this->age = 0;
	this->position = pos;
	this->type = WILK;
	this->world = world;
}

void Wilk::draw()
{
}


Wilk::~Wilk()
{
}
