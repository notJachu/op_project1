#pragma once
#include "../creature.h"
#include "../../types.h"
#include "../../world.h"

class Plant : public Creature {
protected:
	 void print(std::ostream& os) const override;
	 void plant_new(World* world, Point* positions);
	 World* world;
public:
	Plant(int power, int initiative, int age, Point position, World* world);
	Plant();
	Plant(World* world);
	void action() override;
	bool collision(Creature* creature) override;
	virtual Creature* create(World* world, Point pos);
	void draw() override;
	void setWorld(World* world);
	void kill() override;
	~Plant() override;
};