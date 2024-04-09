#include <iostream>
#include "world.h"
#include "creature.h"
#include "animal.h"
#include "plants/plant.h"
#include "plants/trawa.h"


int main() {
	World world;
	world.addCreature(new Trawa(&world));
	world.print(std::cout);
	world.playTurn();
	world.print(std::cout);
	return 0;
}