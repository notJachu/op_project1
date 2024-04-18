#pragma once

#include "animal.h"


class Wilk : public Animal {

	public:
	Wilk(int power, int initiative, int age, Point position, World* world);
	Wilk(World* world, Point pos);
	void draw() override;
	void print(std::ostream& os) const override;
	~Wilk() override;
};