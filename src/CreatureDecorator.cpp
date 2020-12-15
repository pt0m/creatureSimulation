#include "CreatureDecorator.h"
#include <iostream>
#include "Medium.h"

CreatureDecorator::CreatureDecorator(ICreature *c) : decoree(c) {};

// Default implementations of methods that can be decorated

void CreatureDecorator::action(Medium &myMedium){ 
  this->decoree->action(myMedium);
}







