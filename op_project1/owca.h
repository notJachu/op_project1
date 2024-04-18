#pragma once

#include "animal.h"

class Owca : public Animal {
public:
	Owca(int power, int initiative, int age, Point position, World* world);
	Owca(World* world, Point pos);
	void draw() override;
	void print(std::ostream& os) const override;
	~Owca() override;
};