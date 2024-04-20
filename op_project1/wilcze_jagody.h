#pragma once

#include "plant.h"

class WilczeJagody : public Plant {
public:
	WilczeJagody(Point pos);
	WilczeJagody(World* world, Point pos);
	WilczeJagody(int power, int initiative, int age, Point position, World* world);
	Creature* create(World* world, Point pos) override;
	void action() override;
	bool collision(Creature* creature) override;
	void draw() override;
	~WilczeJagody() override;
};