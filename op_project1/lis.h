#pragma once

#include "animal.h"

class Lis : public Animal {

	public:
	Lis(int power, int initiative, int age, Point position, World* world);
	Lis(World* world, Point pos);
	void draw() override;
	Point move() const override;
	void print(std::ostream& os) const override;
	~Lis() override;
};
