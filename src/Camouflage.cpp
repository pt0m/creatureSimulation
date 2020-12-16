#include "Camouflage.h"
#include <cstdlib>
#include <algorithm> // for min(float , float) function 


Camouflage::Camouflage(ICreature *c) : CreatureDecorator(c){
  Config* config_singleton = Config::get_instance();
  this->max_camouflage = config_singleton->get_config_float("max_camouflage");

  float max_camouflage_efficency = 
          config_singleton->get_config_float("max_camouflage_efficency");
  float min_camouflage_efficency = 
          config_singleton->get_config_float("min_camouflage_efficency");
  float rnd = float(std::rand()) / float(RAND_MAX);
  this->camouflage_efficiency = rnd * (max_camouflage_efficency - min_camouflage_efficency) + min_camouflage_efficency;
}


float Camouflage::get_camouflage() const{
  float original_camouflage = CreatureDecorator::get_camouflage();
  // those two variable should be imported from the config file 
  float new_camouflage = original_camouflage + this->camouflage_efficiency;
  return std::min(new_camouflage, this->max_camouflage);
}


void Camouflage::draw(UImg &support) const{
  CreatureDecorator::draw(support);
  //we will have to draw something more after that to plot the shell
  /*
   * add here the code to draw the shell (creature is already drawn)
   */
  
}
