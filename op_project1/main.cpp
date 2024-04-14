#include <iostream>
#include "world.h"
#include "creature.h"
#include "animal.h"
#include "plant.h"
#include "trawa.h"
#include "wilk.h"


int main() {
	World world;
	world.addCreature(new Trawa(&world, {3 , 3}));
	world.print(std::cout);
	world.playTurn();
	world.print(std::cout);
	Creature* creature = world.getCreature(3, 3);
	//world.removeCreature(creature);
	creature->kill();
	return 0;
}