#include "Medium.h"
#include "Config.h"
#include "utils.h"
#include "Creature.h"

#include <ctime>
#include <iostream>

const T    Medium::white[] = {(T) 255, (T) 255, (T) 255};

Medium::Medium(int width, int height) :
    UImg(width, height, 1, 3), width(width), height(height) {
  Config *config_singleton = Config::get_instance();
  max_birth = config_singleton->get_config_int("max_birth");
  proba_clone = config_singleton->get_config_float("proba_clone");
  creature_factory = new Factory();
  std::cout << "const Medium" << std::endl;
  add_creature();
  add_creature();
  add_creature();
//  add_creature();
//  add_creature();
//  add_creature();
  std::srand(time(NULL));
}

Medium::~Medium(void) {
  std::cout << "dest Medium" << std::endl;
  for (auto c : list_creatures) {
    delete c;
  }
  list_creatures.clear();
  creature_factory->~Factory();
}

void Medium::add_creature() {
  auto *c = creature_factory->create_creature();
  list_creatures.push_back(c);
}

void Medium::add_creature_clone(ICreature &c) {
  auto *creature = c.clone();
  list_creatures.push_back(creature);
}

bool Medium::are_colliding(const ICreature &c1, const ICreature &c2) const {
  int dx = c1.get_x() - c2.get_x();
  int dy = c1.get_y() - c2.get_y();
  int sum_size = c1.get_size() + c2.get_size();
  int dist_squared = dx * dx + dy * dy;
  int size_squared = sum_size * sum_size;
  return dist_squared <= size_squared;
}

bool Medium::collide(ICreature &c1, ICreature &c2) {
  int vx, vy;
  bool is_c1_dead = c1.is_collision_deadly();
  if (is_c1_dead) {
    std::cout << "kill c1 collide" << std::endl;
    kill_creature(c1);
  } else {
    vx = c1.get_vx();
    vy = c1.get_vy();
    c1.set_vx_vy(-vx, -vy);
  }
  bool is_c2_dead = c2.is_collision_deadly();
  if (is_c2_dead) {
    std::cout << "kill c2 collide" << std::endl;
    kill_creature(c2);
    std::cout << "killed c2 collide" << std::endl;
  } else {
    vx = c2.get_vx();
    vy = c2.get_vy();
    c2.set_vx_vy(-vx, -vy);
  }
  return is_c1_dead;
}

int Medium::get_height(void) const { return height; };

int Medium::get_width(void) const { return width; };

void Medium::kill_creature(ICreature &c) { list_creatures.remove(&c); }

int Medium::nb_neighbours(const ICreature &c) const {
  int nb = 0;
  for (const ICreature *other : list_creatures) {
    if (c.get_identity() != other->get_identity()) {
      if (c.is_detected(*other)) {
        nb++;
      }
    }
  }
  return nb;
}

std::unique_ptr<std::list<ICreature *>>
Medium::list_neighbours(const ICreature &c) const {
  std::unique_ptr<std::list<ICreature *>> neighbours = std::make_unique < std::list < ICreature * >> ();
  for (ICreature *other : list_creatures) {
    if (c.get_identity() != other->get_identity()) {
//      if (c.is_detected(*other)) {
      neighbours->push_back(other);
//      }
    }
  }
  return neighbours;
};

void Medium::step(void) {
  // macro from CImg, x and y are just variable names
  cimg_forXY(*this, x, y) fillC(x, y, 0, white[0], white[1], white[2]);
  bool is_dead;

  std::cout << "step medium" << std::endl;
  for (ICreature *c : list_creatures) {
    // Move
    std::cout << "action" << std::endl;
    c->action(*this);
    // Check for collisions
    for (ICreature *other : list_creatures) {
      if (c->get_identity() != other->get_identity()) {
        if (are_colliding(*c, *other)) {
          std::cout << "are colliding" << std::endl;
          is_dead = collide(*c, *other);
          if (is_dead) {
            break;
          }
        }
      }
    }
    if (is_dead) {
      continue;
    }
    // The creature is too old
    if ((c->get_lifetime() <= 0) && (!is_dead)) {
      std::cout << "creature too old" << std::endl;
      is_dead = true;
      kill_creature(*c);
    }
    if (!is_dead) {

      c->draw(*this);
//      if (rand_range(0, 1, 1000) < proba_clone) {
//        add_creature_clone(*c);
//      }
    }
  }
  std::cout << "step medium" << std::endl;
}

std::list<ICreature *> &Medium::get_creatures_list() {
  return list_creatures;
}
