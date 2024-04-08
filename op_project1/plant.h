#pragma once
#include "creature.h"
#include "types.h"
#include "world.h"

class Plant : public Creature {
protected:
	 void print(std::ostream& os) const override;
	 void plant_new(World* world);
	 World* world;
public:
	Plant(int power, int initiative, int age, Point position, World* world);
	Plant();
	Plant(World* world);
	void action() override;
	void collision(Creature* creature) override;
	void draw() override;
	void setWorld(World* world);
	~Plant() override;
};