#include <iostream>
#include <fstream>
#include "world.h"
#include "creatures/creature.h"
#include "creatures/animals/animal.h"
#include "creatures/plants/plant.h"
#include "creatures/plants/trawa.h"
#include "creatures/animals/wilk.h"
#include "creatures/animals/antylopa.h"
#include "creatures/plants/guarana.h"
#include "creatures/plants/mlecz.h"
#include "creatures/plants/barszcz_sosnowskiego.h"
#include "creatures/animals/tutel.h"
#include "creatures/animals/Cz³owiek.h"




int main() {
	//World world;
	//world.addCreature(new Trawa(&world, {3 , 3}));
	//world.addCreature(new Wilk(&world, { 1, 1 }));
	//world.addCreature(new Wilk(&world, { 1, 2 }));
	//world.addCreature(new Trawa(&world, { 3 , 5 }));
	//world.addCreature(new Antylopa(&world, { 5 , 5 }));
	//world.addCreature(new Guarana(&world, { 1, 4 }));
	//world.addCreature(new Cz³owiek(&world, { 10, 10 }));
	//world.print(std::cout);
	//world.draw();

	std::fstream file;
	file.open("save.txt", std::ios::in);
	World world(file);
	file.close();

	for (int i = 0; i < 10; i++) {
		world.playTurn();
		std::cout << std::endl;
		world.draw();
		//world.print(std::cout);
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