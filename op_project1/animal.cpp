#include "animal.h"
#include "ctime"

void Animal::move() {
	Point newPosition = position;
	int direction = rand() % 4;
	switch (direction) {
	case 0:
		newPosition.y++;
		break;
	case 1:
		newPosition.y--;
		break;
	case 2:
		newPosition.x++;
		break;
	case 3:
		newPosition.x--;
		break;
	}

	Creature* creature = world->getCreature(newPosition.x, newPosition.y);
	if (creature == nullptr) {
		position = newPosition;
		world->updateCreaturePosition(this->position, newPosition);
	} else if (creature->getType() == this->type) {
		if (!reproduce()) {
			dynamic_cast<Animal*>(creature)->reproduce();
		}
	} else {
		creature->collision(this);
	}

}

bool Animal::reproduce() {
	Point* positions = world->get_free_neighbours(position);
	if (positions == nullptr) {
		return false;
	}

	for (int i = 0; i < 4; i++) {
		if (positions[i].x != -1) {
			world->addCreature(new Animal(power, initiative, 0, positions[i], world));
			return true;
		}
	}
	return false;	
}

void Animal::print(std::ostream& os) const {
	os << "Animal: power=" << power << " initiative=" << initiative << " age=" << age << " position=(" << position.x << "," << position.y << ")";
}

Animal::Animal(int power, int initiative, int age, Point position, World* world){
	this->power = power;
	this->initiative = initiative;
	this->age = age;
	this->position = position;
	this->world = world;
}

Animal::Animal(Point pos, World* world) {
	this->position = pos;
	this->world = world;
	this->power = 0;
	this->initiative = 0;
	this->age = 0;
}

void Animal::action()
{
}

void Animal::collision(Creature* creature) {
	int pow = creature->getPower();

	if (pow < this->power){
		creature->kill();
	}
	else {
		kill();
	}
}

void Animal::draw()
{
}

void Animal::kill(){
	world->removeCreature(this);
}

Animal::~Animal()
{
}
