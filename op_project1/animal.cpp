#include "animal.h"

Animal::Animal(int power, int initiative, int age, Point position){
	this->power = power;
	this->initiative = initiative;
	this->age = age;
	this->position = position;
}

void Animal::action()
{
}

void Animal::collision(Creature* creature)
{
}

void Animal::draw()
{
}

Animal::~Animal()
{
}
