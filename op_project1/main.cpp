#include <iostream>
#include "world.h"
#include "creature.h"
#include "animal.h"
#include "plant.h"
#include "trawa.h"
#include "wilk.h"
#include "antylopa.h"
#include "guarana.h"
#include "mlecz.h"
#include "barszcz_sosnowskiego.h"
#include "tutel.h"
#include "Cz³owiek.h"




int main() {
	World world;
	world.addCreature(new Trawa(&world, {3 , 3}));
	world.addCreature(new Wilk(&world, { 1, 1 }));
	world.addCreature(new Trawa(&world, { 3 , 5 }));
	world.addCreature(new Antylopa(&world, { 5 , 5 }));
	world.addCreature(new Guarana(&world, { 1, 2 }));
	world.addCreature(new Cz³owiek(&world, { 10, 10 }));
	world.print(std::cout);
	world.draw();


	for (int i = 0; i < 10; i++) {
		world.playTurn();
		world.draw();
		world.print(std::cout);
	}

	//world.playTurn();
	//world.sort_creatures();
	//world.print(std::cout);
	/*Creature* creature = world.getCreature(3, 3);
	world.removeCreature(creature);*/
	//creature->kill();
	//world.draw();
	return 0;
}