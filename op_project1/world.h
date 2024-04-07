#pragma once
#include "creature.h"
#include "types.h"

class World {
private:
	Creature** creatures;
	int creatureCount;
	int array_size;

public:
	World();
	~World();
	void addCreature(Creature* creature);
	void print(std::ostream& os) const;
	void playTurn();
	void draw() const;
};