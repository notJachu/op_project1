#pragma once

#include "animal.h"

class Tutel : public Animal {

	public:
	Tutel(int power, int initiative, int age, Point position, World* world);
	Tutel(World* world, Point pos);
	Creature* create(World* world, Point pos) override;
	void draw() override;
	Point move() const override;
	bool collision(Creature* creature) override;
	void print(std::ostream& os) const override;
	~Tutel() override;
};
