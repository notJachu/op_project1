#include "owca.h"
#include "../../world.h"

Owca::Owca(int power, int initiative, int age, Point position, World* world) {
	this->power = power;
	this->initiative = initiative;
	this->age = age;
	this->position = position;
	this->type = OWCA;
	this->world = world;
}

Owca::Owca(World* world, Point pos) {
	this->power = 4;
	this->initiative = 4;
	this->age = 0;
	this->position = pos;
	this->type = OWCA;
	this->world = world;
}

Creature* Owca::create(World* world, Point pos) {
	return new Owca(world, pos);
}

void Owca::draw()
{
}

void Owca::print(std::ostream& os) const {
	os << "Owca: power=" << power << " initiative=" << initiative << " age=" << age << " position=(" << position.x << "," << position.y << ")";
}


Owca::~Owca()
{
}
