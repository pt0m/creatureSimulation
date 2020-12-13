#include "Creature.h"
#include "Config.h"
#include "utils.h"

#include <vector>
#include <cmath>
#include <iostream>
#include <cstdlib>

Creature::Creature() {

  Config *config_singleton = Config::get_instance();

  float max_speed = config_singleton->get_config_float("max_speed");
  float min_speed = config_singleton->get_config_float("min_speed");
  this->speed = rand_range(min_speed, max_speed, 10000)

  float max_size = config_singleton->get_config_int("max_size");
  float min_size = config_singleton->get_config_int("min_size");
  this->size = rand_range(min_size, max_size, 10000)

  // set the first position
  int width = config_singleton->get_config_int("width");
  int height = config_singleton->get_config_int("height");
  this->x = rand() % width;
  this->y = rand() % height;

  this->orientation = rand_range(0, 2 * M_PI, 10000)

  int max_lifetime = config_singleton->get_config_int("max_lifetime");
  int min_lifetime = config_singleton->get_config_int("min_lifetime");
  this->lifetime = rand_range(min_lifetime, max_lifetime, 10000)

  this->vx = (this->speed) * cos(this->orientation);
  this->vy = (this->speed) * sin(this->orientation);

  float max_camouflage = config_singleton->get_config_float("max_camouflage");
  this->camouflage = rand_range(0.0, max_camouflage, 10000)

  this->identity = Creature::NEXT_IDENTITY;
  Creature::NEXT_IDENTITY = Creature::NEXT_IDENTITY + 1;

//   TODO : set new color based on behavior
//  color = new T[3];
//  color[0] = static_cast<int>( static_cast<double>( rand()) / RAND_MAX * 230. );
//  color[1] = static_cast<int>( static_cast<double>( rand()) / RAND_MAX * 230. );
//  color[2] = static_cast<int>( static_cast<double>( rand()) / RAND_MAX * 230. );

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
  this->color = c.color;
  this->identity = Creature::NEXT_IDENTITY;
  this->behaviour = c.behaviour
  Creature::NEXT_IDENTITY = Creature::NEXT_IDENTITY + 1;
}

Creature::~Creature() {};

void Creature::action(Medium &myMedium) {
  std::cout << "Empty implementation";
  this->lifetime = this->lifetime - 1;
}

void Creature::draw(UImg &support) const {
  double xt = x + cos(orientation) * this->size / 2.1;
  double yt = y - sin(orientation) * this->size / 2.1;

  support.draw_ellipse(x, y, this->size, this->size / 5., -orientation / M_PI * 180., color);
  support.draw_circle(xt, yt, this->size / 2., color);
}

float Creature::get_camouflage() const { return camouflage; };

int Creature::get_lifetime() const { return lifetime; };

float Creature::get_speed() const { return speed; };

int Creature::get_x() const { return x; };

int Creature::get_y() const { return y; };

float Creature::get_vx() const { return vx; };

float Creature::get_vy() const { return vy; };

bool Creature::is_collision_deadly() const { return true; };

bool Creature::is_detected(const ICreature &) const { return false; }

void Creature::set_coords(const int x, const int y) {
  this->x = x;
  this->y = y;
}

void Creature::set_vx_vy(const int new_vx, const int new_vy) {
  this->vx = new_vx;
  this->vy = new_vy;
}

void Creature::set_lifetime(const int new_val) { this->lifetime = new_val; }


