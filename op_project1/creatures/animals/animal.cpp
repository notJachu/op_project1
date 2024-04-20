#include "animal.h"
#include "ctime"
#include "../../world.h"
#include "../creature.h"

Point Animal::move() const {
	Point positions[4]{};
	int count_positions = 0;

	for (int i = 0; i < 4; i++) positions[i] = { -1, -1 };

	if (position.x - 1 >= 0) {
		positions[count_positions] = { position.x - 1, position.y };
		count_positions++;
	}
	if (position.x + 1 < world->getWidth()) {
		positions[count_positions] = { position.x + 1, position.y };
		count_positions++;
	}
	if (position.y - 1 >= 0) {
		positions[count_positions] = { position.x, position.y - 1 };
		count_positions++;
	}
	if (position.y + 1 < world->getHeight()) {
		positions[count_positions] = { position.x, position.y + 1 };
		count_positions++;
	}

	if (count_positions == 0) return position;

	int direction = rand() % count_positions;
	

	return positions[direction];
}

bool Animal::reproduce() {
	Point* positions = world->get_free_neighbours(position);
	if (positions == nullptr) {
		return false;
	}

	for (int i = 0; i < 4; i++) {
		if (positions[i].x != -1) {
			world->addCreature(this->create(world, positions[i]));
			
			log_event(std::cout, type, type, REPRODUCE);
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

Animal::Animal() {
	this->power = 0;
	this->initiative = 0;
	this->age = 0;
	this->position = { 0,0 };
	this->world = nullptr;
}

Creature* Animal::create(World* world, Point pos) {
	return nullptr;
}

void Animal::action() {
	Point newPosition = move();

	if 	(newPosition.x == position.x && newPosition.y == position.y) return; // no move 

	Creature* creature = world->getCreature(newPosition.x, newPosition.y);
	if (creature == nullptr) {
		world->updateCreaturePosition(this->position, newPosition);
		position = newPosition;
	}
	else if (creature->getType() == this->type) {
		if (!reproduce()) {
			dynamic_cast<Animal*>(creature)->reproduce();
		}
	}
	else {
		bool res = creature->collision(this);
		if (res) {
			world->updateCreaturePosition(this->position, newPosition);
			position = newPosition;
		}
	}
}

bool Animal::collision(Creature* creature) {
	int pow = creature->getPower();

	if (pow < this->power){
		log_event(std::cout, this->type, creature->getType(), DEFEND);
		creature->kill();
	}
	else {
		log_event(std::cout, creature->getType(), type, KILL);
		kill();
		return true;
	}
	return false;
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
