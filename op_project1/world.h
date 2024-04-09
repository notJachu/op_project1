#pragma once
#include "creature.h"
#include "types.h"

class World {
private:
	Creature** creatures;
	int creatureCount;
	int array_size;
	int width;
	int height;
	void init_array();

public:
	World();
	~World();
	void addCreature(Creature* creature);
	void print(std::ostream& os) const;
	void playTurn();
	Point* get_free_neighbours(Point position);
	void draw() const;
};