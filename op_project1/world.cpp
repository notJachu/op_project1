#include "world.h"
#include "types.h"

World::World() {
	this->creatures = nullptr;
	this->creatureCount = 0;
	this->array_size = 0;
}

World::~World() {
	if (creatures != nullptr) {
		delete[] creatures;
	}
	creatureCount = 0;
	array_size = 0;
}

void World::addCreature(Creature* creature) {
	if (creatures == nullptr) {
		creatures = new Creature*[4];
		array_size = 4;
		creatures[0] = creature;
		creatureCount = 1;
	}
	else if (creatureCount == array_size){
		  Creature** temp = new Creature*[array_size * 2];
		  for (int i = 0; i < creatureCount; i++) {
			  temp[i] = creatures[i];
		  }
		  delete[] creatures;
		  creatures = temp;
		  creatures[creatureCount] = creature;
		  creatureCount++;
		  array_size *= 2;
	}
	else {
		creatures[creatureCount] = creature;
		creatureCount++;
	}
}

void World::print(std::ostream& os) const {
}

void World::playTurn() {
	for (int i = 0; i < creatureCount; i++) {
		creatures[i]->action();
	}
}

void World::draw() const
{
}
