#include "Shell.h"
#include <cstdlib>
#include "Config.h"
Shell::Shell(ICreature *c) : CreatureDecorator(c){
  Config* config_singleton = Config::get_instance();
  float shell_max_p_to_survive = 
          config_singleton->get_config_float("shell_max_proba_to_survive");
  float shell_min_p_to_survive = 
          config_singleton->get_config_float("shell_min_proba_to_survive");
  float rnd = float(std::rand()) / float(RAND_MAX);
  this->chance_to_survive_with_the_shell = rnd * (shell_max_p_to_survive - shell_min_p_to_survive) + shell_min_p_to_survive;
}

bool Shell::is_collision_deadly() const{
  if(!CreatureDecorator::is_collision_deadly()){
    return false; // if the collision isn't deadly, then the shell do nothing
  }
  float random_number = float(std::rand()) / float(RAND_MAX);
  // we will have to set the next variable from the config file
  if(random_number < 1 - this->chance_to_survive_with_the_shell){
    return false;
  }
  return true;
}

void Shell::draw(UImg &support) const{
  CreatureDecorator::draw(support);
  //we will have to draw something more after that to plot the shell
  //TODO : add here the code to draw the shell (creature is already drawn)
}

