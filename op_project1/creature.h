#pragma once
#include <iostream>
#include "types.h"


class Creature {
protected:
	int power;
	int initiative;
	int age;
	Point position;
	creature_type type;
	virtual void print(std::ostream& os) const = 0;
	friend std::ostream& operator<<(std::ostream& os, const Creature& creature);
	
public:
  virtual void action() = 0;
  virtual bool collision(Creature* creature) = 0;
  virtual void draw() = 0;
  virtual void kill() = 0;
  void log_event(std::ostream& os, creature_type first, creature_type second, event_type event);
  // getters
  int getX();
  int getY();
  int getPower();
  int getInitiative();
  int getAge();
  creature_type getType();
	
  // setters
  void setX(int x);
  void setY(int y);
  void setPower(int power);
  void setInitiative(int initiative);
  void setAge(int age);
  void increment_age();
  virtual ~Creature();
};