#pragma once
#include "plant.h"

class Trawa : public Plant {

	public:
	Trawa(Point pos);
	Trawa(World* world, Point pos);
	Creature* create(World* world, Point pos) override;
	void action() override;
	bool collision(Creature* creature) override;
	void draw() override;
	~Trawa() override;
};
