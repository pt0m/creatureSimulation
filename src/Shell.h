#ifndef SHELL_H
#define SHELL_H

#include "CreatureDecorator.h"
#include "ICreature.h"
#include "UImg.h"

class Shell : public CreatureDecorator{
  private:
  float chance_to_survive;
  float speed_mult_coef;
  public:
  Shell(ICreature* c); 
  bool is_collision_deadly() const override;
  float get_speed() const override;
  void draw(UImg &support) const override;
  ICreature *clone() override;
};


#endif


