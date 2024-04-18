#pragma once

#include "plant.h"

class Mlecz : public Plant {

	public:
	Mlecz(Point pos);
	Mlecz(World* world, Point pos);
	Creature* create(World* world, Point pos) override;
	void action() override;
	bool collision(Creature* creature) override;
	void draw() override;
	~Mlecz() override;
};
