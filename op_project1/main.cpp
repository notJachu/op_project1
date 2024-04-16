#include <iostream>
#include "world.h"
#include "creature.h"
#include "animal.h"
#include "plant.h"
#include "trawa.h"
#include "wilk.h"
#include "antylopa.h"


int main() {
	World world;
	world.addCreature(new Trawa(&world, {3 , 3}));
	world.addCreature(new Wilk(&world, { 1, 1 }));
	world.addCreature(new Trawa(&world, { 3 , 5 }));
	world.print(std::cout);
	//world.playTurn();
	world.sort_creatures();
	world.print(std::cout);
	//Creature* creature = world.getCreature(3, 3);
	//world.removeCreature(creature);
	//creature->kill();
	return 0;
}