#include "wilcze_jagody.h"

WilczeJagody::WilczeJagody(Point pos) {
	this->power = 99;
	this->initiative = 0;
	this->age = 0;
	this->position = pos;
	this->type = WILCZE_JAGODY;
}

WilczeJagody::WilczeJagody(World* world, Point pos) {
	this->power = 99;
	this->initiative = 0;
	this->age = 0;
	this->position = pos;
	this->type = WILCZE_JAGODY;
	this->world = world;
}

void WilczeJagody::action()
{
}

bool WilczeJagody::collision(Creature* creature) {
	log_event(std::cout, creature->getType(), type, KILL);
	creature->kill();
	return false;
}

void WilczeJagody::draw()
{
}

WilczeJagody::~WilczeJagody()
{
}
