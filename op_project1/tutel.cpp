#include "tutel.h"

Tutel::Tutel(int power, int initiative, int age, Point position, World* world) {
	this->power = power;
	this->initiative = initiative;
	this->age = age;
	this->position = position;
	this->type = TUTEL;
	this->world = world;
}

Tutel::Tutel(World* world, Point pos) {
	this->power = 2;
	this->initiative = 1;
	this->age = 0;
	this->position = pos;
	this->type = TUTEL;
	this->world = world;
}

void Tutel::draw()
{
}

Point Tutel::move() const {

	int will_move = rand() % 4;
	if (will_move < 3) return position;
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

bool Tutel::collision(Creature* creature) {
	if (creature->getPower() < 5) {
		log_event(std::cout, type, creature->getType(), DEFEND);
		return false;
	}
	else {
		kill();
		log_event(std::cout, creature->getType(), type, KILL);
		return true;
	}
}

void Tutel::print(std::ostream& os) const {
	os << "Tutel: power=" << power << " initiative=" << initiative << " age=" << age << " position=(" << position.x << "," << position.y << ")";
}

Tutel::~Tutel()
{
}
