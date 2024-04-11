#include "barszcz_sosnowskiego.h"
#include "types.h"

BarszczSosnowskiego::BarszczSosnowskiego(Point pos) {
	this->power = 0;
	this->initiative = 0;
	this->age = 0;
	this->position = pos;
	this->type = BARSZCZ_SOSNOWSKIEGO;
}

BarszczSosnowskiego::BarszczSosnowskiego(World* world, Point pos) {
this->power = 0;
	this->initiative = 0;
	this->age = 0;
	this->position = pos;
	this->type = BARSZCZ_SOSNOWSKIEGO;
	this->world = world;
}

void BarszczSosnowskiego::action() {

	Creature* creature = world->getCreature(position.x - 1, position.y);
	if (creature != nullptr && creature->getType() != CYBER_OWCA) {
		creature->kill();
	}

	creature = world->getCreature(position.x + 1, position.y);
	if (creature != nullptr && creature->getType() != CYBER_OWCA) {
		creature->kill();
	}

	creature = world->getCreature(position.x, position.y - 1);
	if (creature != nullptr && creature->getType() != CYBER_OWCA) {
		creature->kill();
	}

	creature = world->getCreature(position.x, position.y + 1);
	if (creature != nullptr && creature->getType() != CYBER_OWCA) {
		creature->kill();
	}

}

void BarszczSosnowskiego::collision(Creature* creature) {
	if (creature->getType() != CYBER_OWCA) {
		creature->kill();
	}
}

void BarszczSosnowskiego::draw()
{
}

BarszczSosnowskiego::~BarszczSosnowskiego()
{
}
