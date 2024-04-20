#pragma once

#include "plant.h"

class Guarana : public Plant {

	public:
	Guarana(Point pos);
	Guarana(World* world, Point pos);
	Guarana(int power, int initiative, int age, Point position, World* world);
	Creature* create(World* world, Point pos) override;
	void action() override;
	bool collision(Creature* creature) override;
	void draw() override;
	~Guarana() override;
};