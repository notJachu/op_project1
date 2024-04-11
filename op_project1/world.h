#pragma once
#include "creature.h"
#include "types.h"

class World {
private:
	Creature** creatures;
	Creature** world_map;
	int creatureCount;
	int array_size;
	int width;
	int height;
	void init_array();

public:
	World();
	~World();
	void addCreature(Creature* creature);
	void removeCreature(Creature* creature);
	Creature* getCreature(int x, int y);
	void print(std::ostream& os) const;
	void playTurn();
	Point* get_free_neighbours(Point position);
	void draw() const;
};