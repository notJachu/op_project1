#include "barszcz_sosnowskiego.h"
#include "types.h"

BarszczSosnowskiego::BarszczSosnowskiego(Point pos) {
	this->power = 10;
	this->initiative = 0;
	this->age = 0;
	this->position = pos;
	this->type = BARSZCZ_SOSNOWSKIEGO;
}

BarszczSosnowskiego::BarszczSosnowskiego(World* world, Point pos) {
	this->power = 10;
	this->initiative = 0;
	this->age = 0;
	this->position = pos;
	this->type = BARSZCZ_SOSNOWSKIEGO;
	this->world = world;
}

Creature* BarszczSosnowskiego::create(World* world, Point pos) { 
	return new BarszczSosnowskiego(world, pos);
}

void BarszczSosnowskiego::action() {

	Creature* creature = world->getCreature(position.x - 1, position.y);
	if (creature != nullptr && creature->getType() != CYBER_OWCA) {
		log_event(std::cout, BARSZCZ_SOSNOWSKIEGO, creature->getType(), KILL);
		creature->kill();
	}

	creature = world->getCreature(position.x + 1, position.y);
	if (creature != nullptr && creature->getType() != CYBER_OWCA) {
		log_event(std::cout, BARSZCZ_SOSNOWSKIEGO, creature->getType(), KILL);
		creature->kill();
	}

	creature = world->getCreature(position.x, position.y - 1);
	if (creature != nullptr && creature->getType() != CYBER_OWCA) {
		log_event(std::cout, BARSZCZ_SOSNOWSKIEGO, creature->getType(), KILL);
		creature->kill();
	}

	creature = world->getCreature(position.x, position.y + 1);
	if (creature != nullptr && creature->getType() != CYBER_OWCA) {
		log_event(std::cout, BARSZCZ_SOSNOWSKIEGO, creature->getType(), KILL);
		creature->kill();
	}

}

bool BarszczSosnowskiego::collision(Creature* creature) {
	if (creature->getType() != CYBER_OWCA) {
		log_event(std::cout, BARSZCZ_SOSNOWSKIEGO, creature->getType(), KILL);
		creature->kill();
		return false;
	}
	return false;
}

void BarszczSosnowskiego::draw()
{
}

BarszczSosnowskiego::~BarszczSosnowskiego()
{
}
