#include "plant.h"

Plant::Plant(int power, int initiative, int age, Point position){
	this->power = power;
	this->initiative = initiative;
	this->age = age;
	this->position = position;
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
