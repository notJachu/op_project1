#include "wilcze_jagody.h"

WilczeJagody::WilczeJagody(Point pos) {
	this->power = 99;
	this->initiative = 0;
	this->age = 0;
	this->position = pos;
}

WilczeJagody::WilczeJagody(World* world, Point pos) {
	this->power = 99;
	this->initiative = 0;
	this->age = 0;
	this->position = pos;
	this->world = world;
}

void WilczeJagody::action()
{
}

void WilczeJagody::collision(Creature* creature) {
	creature->kill();
}

void WilczeJagody::draw()
{
}

WilczeJagody::~WilczeJagody()
{
}
