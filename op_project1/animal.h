#pragma once
#include "creature.h"
#include "types.h"
#include "world.h"


class Animal : public Creature {
protected:
	 World* world;
	 virtual Point move() const;
	 bool reproduce();
	 void print(std::ostream& os) const override;
public:
	Animal(int power, int initiative, int age, Point position, World* world);
	Animal(Point pos, World* world);
	Animal();
	void action() override;
	bool collision(Creature* creature) override;
	void draw() override;
	void kill() override;
	~Animal() override;
};