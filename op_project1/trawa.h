#pragma once
#include "plant.h"

class Trawa : public Plant {

	public:
	Trawa();
	void action() override;
	void collision(Creature* creature) override;
	void draw() override;
	~Trawa() override;
};
