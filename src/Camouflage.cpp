#include "Camouflage.h"
#include <cstdlib>
#include <algorithm> // for min(float , float) function 


Camouflage::Camouflage(ICreature *c) : CreatureDecorator(c){
}


float Camouflage::get_camouflage() const{
  float original_camouflage = CreatureDecorator::get_camouflage();
  // those two variable should be imported from the config file 
  float camouflage_efficiency = 0.3;
  float max_camouflage = 0.9;
  float new_camouflage = original_camouflage + camouflage_efficiency;
  return std::min(new_camouflage, max_camouflage);
}


void Camouflage::draw(UImg &support) const{
  CreatureDecorator::draw(support);
  //we will have to draw something more after that to plot the shell
  /*
   * add here the code to draw the shell (creature is already drawn)
   */
  
}
