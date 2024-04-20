#pragma once
#include "creature.h"
#include "types.h"
#include <iostream>
#include <fstream>

class World;

class World {
private:
	Creature** creatures;
	Creature** world_map;
	int creatureCount;
	int array_size;
	int width;
	int height;
	bool has_added_animal;
	bool has_added_plant;
	void init_array(int width, int height, int size);
	direction player_input;
	int player_ability;
	std::fstream file;

public:
	World();
	World(int width, int height);
	World(std::fstream& in);
	void save();
	~World();
	void addCreature(Creature* creature);
	void removeCreature(Creature* creature);
	void updateCreaturePosition(Point position, Point target);
	Creature* getCreature(int x, int y);
	int getWidth() const;
	int getHeight() const;
	int getPlayerAbility() const;
	void setPlayerAbility(int value);
	void print(std::ostream& os) const;
	void playTurn();
	void read_player_input();
	direction get_player_input();
	Point* get_free_neighbours(Point position);
	void set_added_flag(int type, bool value); // 1 - animal	0 - plant
	void sort_creatures();
	void draw() const;
};