#pragma once

#include "plant.h"

class Guarana : public Plant {

	public:
	Guarana(Point pos);
	Guarana(World* world, Point pos);
	Creature* create(World* world, Point pos) override;
	void action() override;
	bool collision(Creature* creature) override;
	void draw() override;
	~Guarana() override;
};