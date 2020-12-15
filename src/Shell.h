#ifndef SHELL_H
#define SHELL_H

#include "CreatureDecorator.h"
#include "ICreature.h"
#include "UImg.h"

Class Shell : public CreatureDecorator{
  public:
  Shell(ICreature* c); 
  bool is_collision_deadly() const override;
  void draw(UImg &support) const override;
};


#endif


