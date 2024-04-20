#pragma once

#include "animal.h"

class Cz�owiek : public Animal {

	public:
	Cz�owiek(int power, int initiative, int age, Point position, World* world);
	Cz�owiek(World* world, Point pos);
	Creature* create(World* world, Point pos) override;
	void draw() override;
	Point move() const override;
	void action() override;
	bool collision(Creature* creature) override;
	void print(std::ostream& os) const override;
	~Cz�owiek() override;
};
