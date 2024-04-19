#pragma once

#include "animal.h"

class Cz這wiek : public Animal {

	public:
	Cz這wiek(int power, int initiative, int age, Point position, World* world);
	Cz這wiek(World* world, Point pos);
	Creature* create(World* world, Point pos) override;
	void draw() override;
	Point move() const override;
	void action() override;
	bool collision(Creature* creature) override;
	void print(std::ostream& os) const override;
	~Cz這wiek() override;
};
