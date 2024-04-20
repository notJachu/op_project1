#pragma once

#include "plant.h"

class BarszczSosnowskiego : public Plant {
public:
	BarszczSosnowskiego(Point pos);
	BarszczSosnowskiego(World* world, Point pos);
	BarszczSosnowskiego(int power, int initiative, int age, Point position, World* world);
	Creature* create(World* world, Point pos) override;
	void action() override;
	bool collision(Creature* creature) override;
	void draw() override;
	~BarszczSosnowskiego() override;
};