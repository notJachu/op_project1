#include <iostream>
#include "world.h"
#include "creature.h"
#include "animal.h"
#include "plant.h"
#include "trawa.h"


int main() {
	World world;
	world.addCreature(new Trawa(&world, {3 , 3}));
	world.print(std::cout);
	world.playTurn();
	world.print(std::cout);
	return 0;
}