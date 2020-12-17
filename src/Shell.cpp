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
  float shell_max_speed_mult_coef = 
          config_singleton->get_config_float("shell_max_speed_mult_coef");
  float shell_min_speed_mult_coef = 
          config_singleton->get_config_float("shell_min_speed_mult_coef");
  rnd = float(std::rand()) / float(RAND_MAX);
  this->speed_mult_coef = rnd *(shell_max_speed_mult_coef - shell_min_speed_mult_coef) + shell_min_speed_mult_coef;
}


ICreature *Shell::clone(){
    ICreature* c = CreatureDecorator::clone();
    ICreature* CreatureDecorated = new Shell(c);
    return CreatureDecorated;
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


float Shell::get_speed() const {
  // we will have to set the next variable from the config file
  float old_speed = CreatureDecorator::get_speed();
  return old_speed * this->speed_mult_coef;
}

void Shell::draw(UImg &support) const{
  CreatureDecorator::draw(support);

  float size =  this->get_size();
  int x0 = int(size/10);
  int y0 = int(size/10);

  T* black = new T[ 3 ];
  black[ 0 ] = 0;
  black[ 1 ] = 0;
  black[ 2 ] = 0;

  int x1 = this->get_x() + x0;
  int y1 = this->get_y() + y0;

  int x2 = this->get_x() - x0;
  int y2 = this->get_y() - y0;

  support.draw_rectangle(x1,y1,x2,y2,black,1,2);

}

