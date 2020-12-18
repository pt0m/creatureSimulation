#include "Config.h"
#include "Shell.h"
#include "utils.h"

Shell::Shell(ICreature *c) : CreatureDecorator(c){
  Config* config_singleton = Config::get_instance();
  float shell_max_p_to_survive = 
      config_singleton->get_config_float("shell_max_proba_survive");
  float shell_min_p_to_survive = 
      config_singleton->get_config_float("shell_min_proba_survive");
  this->chance_to_survive = 
      rand_range(shell_min_p_to_survive,shell_max_p_to_survive, 10000);
  float shell_max_speed_mult_coef = 
      config_singleton->get_config_float("shell_max_speed_mult_coef");
  float shell_min_speed_mult_coef = 
      config_singleton->get_config_float("shell_min_speed_mult_coef");
  this->speed_mult_coef =
      rand_range(shell_min_speed_mult_coef,shell_max_speed_mult_coef, 10000);
}


ICreature *Shell::clone(){
    ICreature* c = CreatureDecorator::clone();
    ICreature* creature_decorated = new Shell(c);
    return creature_decorated;
}

bool Shell::is_collision_deadly() const{
  // if the collision isn't deadly, then the shell do nothing
  if(!CreatureDecorator::is_collision_deadly())
    return false;

  // we will have to set the next variable from the config file
  if(rand_range(0, 1, 10000) < this->chance_to_survive)
    return false;

  return true;
}


float Shell::get_speed() const {
  // we will have to set the next variable from the config file
  float old_speed = CreatureDecorator::get_speed();
  return old_speed * this->speed_mult_coef;
}

void Shell::draw(UImg &support) const{
  CreatureDecorator::draw(support);

  int x = this->get_x();
  int y = this->get_y();
  float vx = this->get_vx();
  float vy = this->get_vy();
  float size = this->get_size();
  float norm_v = sqrt(vx*vx+vy*vy);
  float orientation;

  if (vy <= 0)
    orientation = acos(vx / norm_v);
  else
    orientation = 2 * M_PI - acos(vx / norm_v);

  float dir_x = vx/norm_v;
  float dir_y = vy/norm_v;

  double xt = x - dir_x * size/2;
  double yt = y - dir_y * size/2;

  T grey[3] = {100,100,100};

    support.draw_ellipse(xt,yt,size/2,size/3,
        -orientation/M_PI*180.,grey);

}

