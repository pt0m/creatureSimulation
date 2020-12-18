#include <cstdlib>      // std::rand()
#include <memory>       // std::unique_ptr
#include <iostream>

#include "Config.h"
#include "ICreature.h"
#include "Medium.h"
#include "Fearful.h"
#include "Farsighted.h"
#include "Gregarious.h"
#include "Kamikaze.h"
#include "Schizophrenic.h"
#include "UImg.h"


Schizophrenic::Schizophrenic(){
    this->list_behaviours[0] = std::make_unique<Farsighted>();
    this->list_behaviours[1] = std::make_unique<Fearful>();
    this->list_behaviours[2] = std::make_unique<Gregarious>();
    this->list_behaviours[3] = std::make_unique<Kamikaze>();
    this->current_behaviour  = 0;
    this->phase_remain_duration = 0;
    Config* cfg = Config::get_instance();
    this->phase_total_duration = cfg->get_config_int("phase_total_duration");
}


std::unique_ptr<IBehaviour> Schizophrenic::clone_behaviour(){
    return std::make_unique<Schizophrenic>();
}


void Schizophrenic::next_step(ICreature* creature, Medium* my_medium){

    // Change the behaviour if needed
    if (this->phase_remain_duration==0){
        this->phase_remain_duration = this->phase_total_duration;
        this->current_behaviour = std::rand() % 4;
        T* new_color = list_color[this->current_behaviour];
        creature->set_color(new_color);
    }

    this->phase_remain_duration--;
    
    //Apply current behaviour
    this->list_behaviours[this->current_behaviour]->next_step(creature,my_medium);
}