#pragma once
#include "creature.h"

class Animal : public Creature {
private:

public:
	Animal(int power, int initiative, int age, Point position);
	void action() override;
	void collision(Creature* creature) override;
	void draw() override;
	~Animal() override;
};