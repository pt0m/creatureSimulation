#ifndef CREATUREDECORATOR_H
#define CREATUREDECORATOR_H

#include "ICreature.h"

class CreatureDecorator {
 public:
  CreatureDecorator(ICreature *c);

  // Methods whose behavior can be modified by concrete decorators

  virtual const bool is_detected(const ICreature *c);

  virtual const double get_camouflage();

  virtual const double get_speed();

  virtual const bool is_collision_deadly();

 private:
  ICreature *decoree;
};

#endif //CREATUREDECORATOR_H
