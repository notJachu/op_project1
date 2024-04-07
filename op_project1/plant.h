#pragma once
#include "creature.h"
#include "types.h"

class Plant : public Creature {
private:

public:
	Plant(int power, int initiative, int age, Point position);
	Plant();
	void action() override;
	void collision(Creature* creature) override;
	void draw() override;
	~Plant() override;
};