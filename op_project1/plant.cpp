#include "plant.h"

Plant::Plant(int power, int initiative, int age, Point position){
	this->power = power;
	this->initiative = initiative;
	this->age = age;
	this->position = position;
}

Plant::Plant() {
	this->power = 0;
	this->initiative = 0;
	this->age = 0;
	this->position = { 0, 0 };
}

void Plant::action()
{
}

void Plant::collision(Creature* creature)
{
}

void Plant::draw()
{
}

Plant::~Plant()
{
}
