#include "Creature.h"

#include <vector>
#include <cmath>
#include <iostream>

const double      Creature::AFF_SIZE = 8.;
const double      Creature::LIMIT_VIEW = 30.;
const double      Creature::MAX_SPEED = 10.;

Creature::Creature() {
  std::cout << "Init creature from empty";
}

Creature::Creature(const Creature &c) {
  this->camouflage = c.camouflage;
  this->lifetime = c.lifetime;
  this->size = c.size;
  this->speed = c.speed;
  this->vx = c.vx;
  this->vy = c.vy;
  this->x = c.x;
  this->y = c.y;
}

void Creature::action(const Medium &myMedium) {
  std::cout << "Empty implementation";
}

void Creature::draw(UImg &support) {

  std::cout << "Empty implementation";
}

const double Creature::get_camouflage() { return camouflage; }

const int Creature::get_lifetime() { return lifetime; }

const double Creature::get_speed() { return speed; }

const int Creature::get_x() { return x; }

const int Creature::get_y() { return y; }

const double Creature::get_vx() { return vx; }

const double Creature::get_vy() { return vy; }

void Creature::init_coords(const int x, const int y) {
  this->x = 0;
  this->y = 0;
}

const bool Creature::is_collision_deadly() { return true; }

const bool Creature::is_detected(const ICreature &) { return false; }

void Creature::set_camouflage(const int new_val) { this->camouflage = new_val; }

void Creature::set_lifetime(const int new_val) { this->lifetime = new_val; }

void Creature::set_speed(const double new_val) { this->speed = new_val; }



