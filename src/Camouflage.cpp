#include <algorithm> // for min(float , float) function 

#include "Camouflage.h"
#include "Config.h"
#include "utils.h"


Camouflage::Camouflage(ICreature *c) : CreatureDecorator(c){
  Config* config_singleton = Config::get_instance();
  this->max_camouflage = config_singleton->get_config_float("max_camouflage");
  float max_cam_effi = 
          config_singleton->get_config_float("max_camouflage_efficency");
  float min_cam_effi = 
          config_singleton->get_config_float("min_camouflage_efficency");
  this->camouflage_efficiency = rand_range(min_cam_effi,max_cam_effi, 10000);
}

ICreature *Camouflage::clone(){
    ICreature* c = CreatureDecorator::clone();
    ICreature* creature_decorated = new Camouflage(c);
    return creature_decorated;
}

float Camouflage::get_camouflage() const{
  float original_camouflage = CreatureDecorator::get_camouflage();
  // those two variable should be imported from the config file 
  float new_camouflage = original_camouflage + this->camouflage_efficiency;
  return std::min(new_camouflage, this->max_camouflage);
}


void Camouflage::draw(UImg &support) const{
  CreatureDecorator::draw(support);

    T black[3] = {0,0,0};

    support.draw_circle(this->get_x(),this->get_y(), this->get_size()*1.3, black,1,~0);
}
