#pragma once
#include <iostream>
#include "types.h"

class Creature {
protected:
	int power;
	int initiative;
	int age;
	Point position;
	virtual void print(std::ostream& os) const = 0;
	friend std::ostream& operator<<(std::ostream& os, const Creature& creature);
	
public:
  virtual void action() = 0;
  virtual void collision(Creature* creature) = 0;
  virtual void draw() = 0;
  virtual ~Creature();
};