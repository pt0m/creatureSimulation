#include "Shell.h"
#include <cstdlib>

Shell::Shell(ICreature *c) : CreatureDecorator(c){
}

bool Shell::is_collision_deadly() const{
  bool was_callision_deadly = CreatureDecorator::is_collision_deadly();
  float random_number = float(std::rand()) / float(RAND_MAX);
  // we will have to set the next variable from the config file
  float chance_to_survive_with_shell = 0.5;
  if(random_number < 1 - chance_to_survive_with_shell){
    return false;
  }
  return true;
}

void Shell::draw(UImg &support) const{
  CreatureDecorator::draw(UImg &support);
  //we will have to draw something more after that to plot the shell
  /*
   * add here the code to draw the shell (creature is already drawn)
   */
  
}

