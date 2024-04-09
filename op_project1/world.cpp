#include "world.h"
#include "types.h"

void World::init_array() {
	creatures = new Creature*[20*20];
	array_size = 20*20;
	for (int i = 0; i < 20 * 20; i++) {
		creatures[i] = nullptr;
	}
	width = 20;
	height = 20;
}

World::World() {
	this->creatures = nullptr;
	this->creatureCount = 0;
	this->array_size = 0;
	this->width = 0;
	this->height = 0;
	init_array();
}

World::~World() {
	if (creatures != nullptr) {
		delete[] creatures;
	}
	creatureCount = 0;
	array_size = 0;
}

void World::addCreature(Creature* creature) {
	if (creatures == nullptr) {
		creatures = new Creature*[20*20];
		array_size = 20*20;
		int x = creature->getX();
		int y = creature->getY();
		creatures[(width * (y - 1)) + x - 1] = creature;
		creatureCount = 1;
		width = 20;
		height = 20;
	}
	else if (creatureCount == array_size){
		  Creature** temp = new Creature*[array_size * 2];
		  for (int i = 0; i < creatureCount; i++) {
			  temp[i] = creatures[i];
		  }
		  delete[] creatures;
		  creatures = temp;
		  creatures[creatureCount] = creature;
		  creatureCount++;
		  array_size *= 2;
	}
	else {
		int x = creature->getX();
		int y = creature->getY();
		creatures[(width * (y - 1)) + x - 1] = creature;
		creatureCount++;
	}
}

void World::print(std::ostream& os) const {
	for (int i = 0; i < array_size; i++) {
		if (creatures[i] != nullptr) {
			os << *creatures[i] << std::endl;
		}
	}
}

void World::playTurn() {
	int c = array_size;
	for (int i = 0; i < c; i++) {
		if (creatures[i] != nullptr) {
			creatures[i]->action();
		}
	}
}

Point* World::get_free_neighbours(Point position) {
	static Point res[4]{};
	for (int i = 0; i < 4; i++) {
		res[i] = { -1 , -1 };	// not a valid position
	}
	if (position.x > 0 && creatures[((width * (position.y - 1)) + position.x - 1) - 1] == nullptr) {
		res[0] = { position.x - 1, position.y };
	}
	if (position.x < width - 1 && creatures[((width * (position.y - 1)) + position.x - 1) + 1] == nullptr) {
		res[1] = { position.x + 1, position.y };
	}
	if (position.y > 0 && creatures[((width * (position.y - 1)) + position.x - 1) - width] == nullptr) {
		res[2] = { position.x, position.y - 1 };
	}
	if (position.y < height - 1 && creatures[((width * (position.y - 1)) + position.x - 1) + width] == nullptr) {
		res[3] = { position.x, position.y + 1 };
	}
	return res;
}

void World::draw() const
{
}
