#pragma once

#include "plant.h"

class Guarana : public Plant {

	public:
	Guarana(Point pos);
	Guarana(World* world, Point pos);
	void action() override;
	void collision(Creature* creature) override;
	void draw() override;
	~Guarana() override;
};