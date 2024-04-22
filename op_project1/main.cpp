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
#include "creatures/animals/Człowiek.h"
#include "creatures/plants/wilcze_jagody.h"




int main() {
	/*World world(30, 30);
	world.addCreature(new Trawa(&world, {3 , 3}));
	world.addCreature(new Wilk(&world, { 1, 1 }));
	world.addCreature(new Wilk(&world, { 1, 2 }));
	world.addCreature(new Trawa(&world, { 3 , 5 }));
	world.addCreature(new Antylopa(&world, { 5 , 5 }));
	world.addCreature(new Guarana(&world, { 1, 4 }));
	world.addCreature(new Człowiek(&world, { 10, 10 }));
	world.addCreature(new Tutel(&world, { 15, 11 }));
	world.addCreature(new Mlecz(&world, { 15, 12 }));
	world.addCreature(new BarszczSosnowskiego(&world, { 15, 20 }));
	world.addCreature(new WilczeJagody(&world, { 20, 20 }));

	world.print(std::cout);
	world.draw();

	world.save();*/


	std::fstream file;
	file.open("save2.txt", std::ios::in);
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