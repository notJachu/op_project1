#include "world.h"
#include "types.h"
#include "Windows.h"

void World::init_array() {
	creatures = new Creature*[20];
	array_size = 20;
	for (int i = 0; i < array_size; i++) {
		creatures[i] = nullptr;
	}
	creatureCount = 0;

	width = 20;
	height = 20;
	world_map = new Creature * [width * height];
	for (int i = 0; i < width * height; i++) {
		world_map[i] = nullptr;
	}
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

		creatures = new Creature*[20];
		array_size = 20;
		for (int i = 0; i < array_size; i++) {
			creatures[i] = nullptr;
		}

		width = 20;
		height = 20;
		world_map = new Creature * [width * height];
		for (int i = 0; i < width * height; i++) {
			world_map[i] = nullptr;
		}

		int x = creature->getX();
		int y = creature->getY();
		world_map[(width * y) + x] = creature;
		creatures[0] = creature;
		creatureCount = 1;
	}
	else if (creatureCount == array_size){
		  Creature** temp = new Creature*[array_size * 2];
		  for (int i = 0; i < creatureCount; i++) {
			  temp[i] = creatures[i];
		  }
		  delete[] creatures;
		  creatures = temp;
		  creatures[creatureCount] = creature;
		  int x = creature->getX();
		  int y = creature->getY();
		  world_map[(width * y) + x] = creature;
		  creatureCount++;
		  array_size *= 2;
	}
	else {
		int x = creature->getX();
		int y = creature->getY();
		world_map[(width * y) + x] = creature;
		creatures[creatureCount] = creature;
		creatureCount++;
	}
}

void World::removeCreature(Creature* creature) {
	if (creature == nullptr) {
		return;
	}
	int index = creature->getX() + (creature->getY() - 1) * width - 1;
	delete world_map[index];
	world_map[index] = nullptr;
	for (int i = 0; i < creatureCount; i++) {
		if (creatures[i] == creature) {
			delete creatures[i];
			creatures[i] = nullptr;
			creatures[i] = creatures[creatureCount - 1];
			creatureCount--;
			break;
		}
	}
	//delete creature;
	creature = nullptr;
}

void World::updateCreaturePosition(Point position, Point target) {
	int index_now = position.x + (position.y * width);
	int index_target = target.x + (target.y * width);
	world_map[index_target] = world_map[index_now];
	world_map[index_now] = nullptr;
	std::cout << *(world_map[index_target]) << std::endl;
}

Creature* World::getCreature(int x, int y) {
	int index = x + (y * width);
	if (index < 0 || index >= width * height) {
		return nullptr;
	}
	return world_map[index];
}

int World::getWidth() const
{
	return this->width;
}

int World::getHeight() const
{
	return this->height;
}

void World::print(std::ostream& os) const {
	for (int i = 0; i < creatureCount; i++) {
		if (creatures[i] != nullptr) {
			os << *creatures[i] << std::endl;
		}
	}
}

void World::playTurn() {
	int c = creatureCount;

	// flag most likely obsolete
	//has_added_animal = false;
	sort_creatures();

	for (int i = 0; i < c; i++) {
		if (creatures[i] != nullptr) {
			creatures[i]->action();
		}
	}
	// loop twice so age increments at the same time
	for (int i = 0; i < c; i++) {
		if (creatures[i] != nullptr) {
			creatures[i]->increment_age();
		}
	}
}

Point* World::get_free_neighbours(Point position) {
	static Point res[4]{};
	for (int i = 0; i < 4; i++) {
		res[i] = { -1 , -1 };	// not a valid position
	}
	int index = position.x - 1 + (position.y * width);
	if (position.x > 0 && world_map[index] == nullptr) {
		res[0] = { position.x - 1, position.y };
	}

	index = position.x + 1 + (position.y * width);
	if (position.x < width - 1 && world_map[index] == nullptr) {
		res[1] = { position.x + 1, position.y };
	}

	index = position.x + ((position.y - 1) * width);
	if (position.y > 0 && world_map[index] == nullptr) {
		res[2] = { position.x, position.y - 1 };
	}

	index = position.x + ((position.y + 1) * width);
	if (position.y < height - 1 && world_map[index] == nullptr) {
		res[3] = { position.x, position.y + 1 };
	}
	return res;
}

void World::set_added_flag(int type, bool value) {
	if (type == 0) {
		has_added_animal = value;
	}
	else {
		has_added_animal = value;
	}
}

void World::sort_creatures() {
	int i, key, j;
	Creature* keyed;
	for (int i = 1; i < creatureCount; i++) {
		key = creatures[i]->getInitiative();
		keyed = creatures[i];
		j = i - 1;
		while (j >= 0 && creatures[j]->getInitiative() < key) {
			creatures[j + 1] = creatures[j];
			j -= 1;
		}
		creatures[j + 1] = keyed;
	}
}

void World::draw() const {
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			if (world_map[(width * i) + j] == nullptr) {
				std::cout << "*";
			}
			else {
				creature_type type = world_map[(width * i) + j]->getType();
				std::cout << get_symbol(type);
			}
		}
		std::cout << std::endl;
		
	}
}


