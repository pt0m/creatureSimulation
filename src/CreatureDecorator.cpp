#include "CreatureDecorator.h"

#include <iostream>

#include "Medium.h"

CreatureDecorator::CreatureDecorator(ICreature *c) : decoree(c) {};

CreatureDecorator::~CreatureDecorator() {
  delete decoree;
}

// Default implementations of methods that can be decorated

void CreatureDecorator::action(Medium &myMedium) {
  this->decoree->action(myMedium);
}

ICreature *CreatureDecorator::clone() {
  return this->decoree->clone();
}

void CreatureDecorator::draw(UImg &support) const {
  this->decoree->draw(support);
}

float CreatureDecorator::get_camouflage() const {
  return this->decoree->get_camouflage();
}

int CreatureDecorator::get_identity() const {
  return this->decoree->get_identity();
}

int CreatureDecorator::get_lifetime() const {
  return this->decoree->get_lifetime();
}

float CreatureDecorator::get_size() const { return this->decoree->get_size(); }

float CreatureDecorator::get_speed() const {
  return this->decoree->get_speed();
}

int CreatureDecorator::get_x() const { return this->decoree->get_x(); }

int CreatureDecorator::get_y() const { return this->decoree->get_y(); }

float CreatureDecorator::get_vx() const { return this->decoree->get_vx(); }

float CreatureDecorator::get_vy() const { return this->decoree->get_vy(); }

bool CreatureDecorator::is_collision_deadly() const {
  return this->decoree->is_collision_deadly();
}

bool CreatureDecorator::is_detected(const ICreature &c) const {
  return this->decoree->is_detected(c);
}

void CreatureDecorator::set_coords(const int x, const int y) {
  this->decoree->set_coords(x, y);
}

void CreatureDecorator::set_lifetime(const int new_val) {
  this->decoree->set_lifetime(new_val);
}

void CreatureDecorator::set_vx_vy(const float vx, const float vy) {
  this->decoree->set_vx_vy(vx, vy);
}


