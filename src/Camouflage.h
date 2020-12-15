#ifndef CAMOUFLAGE_H
#define CAMOUFLAGE_H

#include "CreatureDecorator.h"
#include "ICreature.h"
#include "UImg.h"

class Camouflage : public CreatureDecorator{
  public:
  Camouflage(ICreature* c); 
  float get_camouflage() const override;
  void draw(UImg &support) const override;
};


#endif


