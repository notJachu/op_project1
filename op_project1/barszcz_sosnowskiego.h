#pragma once

#include "plant.h"

class BarszczSosnowskiego : public Plant {
public:
	BarszczSosnowskiego(Point pos);
	BarszczSosnowskiego(World* world, Point pos);
	void action() override;
	void collision(Creature* creature) override;
	void draw() override;
	~BarszczSosnowskiego() override;
};