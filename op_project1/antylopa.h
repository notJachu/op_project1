#pragma once

#include "animal.h"

class Antylopa : public Animal {
protected:
	bool run();

public:
	Antylopa(int power, int initiative, int age, Point position, World* world);
	Antylopa(World* world, Point pos);
	Creature* create(World* world, Point pos) override;
	void draw() override;
	Point move() const override;
	bool collision(Creature* creature) override;
	void print(std::ostream& os) const override;
	~Antylopa() override;
};