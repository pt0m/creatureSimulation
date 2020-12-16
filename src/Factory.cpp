#include "Config.h"
#include "Creature.h"
#include "Fearful.h"
#include "Factory.h"
#include "Farsighted.h"
#include "Gregarious.h"
#include "IBehaviour.h"
#include "ICreature.h"
#include "Kamikaze.h"
#include "Schizophrenic.h"
#include "UImg.h"
#include "utils.h"

#include <cstdlib>      // std::rand()


Factory::Factory(){
    Config* cfg = Config::get_instance();

    //Behaviours population
    this->pop_farsighted      = cfg->get_config_int("pop_farsighted");
    this->pop_fearful         = cfg->get_config_int("pop_fearful");
    this->pop_gregarious      = cfg->get_config_int("pop_gregarious");
    this->pop_kamikaze        = cfg->get_config_int("pop_kamikaze");
    this->pop_schizophrenic   = cfg->get_config_int("pop_schizophrenic");
    this->pop_total           = pop_farsighted+pop_fearful+pop_gregarious+pop_kamikaze+pop_schizophrenic;

    //Accessories probabilities
    this->proba_camouflage  = cfg->get_config_float("proba_camouflage");
    this->proba_ears        = cfg->get_config_float("proba_ears");
    this->proba_eyes        = cfg->get_config_float("proba_eyes");
    this->proba_fin         = cfg->get_config_float("proba_fin");
    this->proba_shell       = cfg->get_config_float("proba_shell");

    //Accessories
    //Camouflage
    this->camouflage_min = cfg->get_config_float("camouflage_min");
    this->camouflage_max = cfg->get_config_float("camouflage_max");
    //Ears properties
    this->ears_distance_min = cfg->get_config_float("ears_distance_min");
    this->ears_distance_max = cfg->get_config_float("ears_distance_max");
    this->ears_quality_min  = cfg->get_config_float("ears_quality_min");
    this->ears_quality_max  = cfg->get_config_float("ears_quality_max");
    //Eyes properties
    this->eyes_angle_min    = cfg->get_config_float("eyes_angle_min");
    this->eyes_angle_max    = cfg->get_config_float("eyes_angle_max");
    this->eyes_distance_min = cfg->get_config_float("eyes_distance_min");
    this->eyes_distance_max = cfg->get_config_float("eyes_distance_max");
    this->eyes_quality_min  = cfg->get_config_float("eyes_quality_min");
    this->eyes_quality_max  = cfg->get_config_float("eyes_quality_max");
    //Fin
    this->fin_speed_boost_max = cfg->get_config_float("fin_speed_boost_max");
    //Shell
    this->shell_protect_max = cfg->get_config_float("shell_protect_max");
    this->shell_speed_reduc = cfg->get_config_float("shell_speed_reduc");

    //Initial x,y
    this->medium_width = cfg->get_config_int("width");
    this->medium_hight = cfg->get_config_int("hight");

    //Speed
    this->speed_min = cfg->get_config_float("speed_min");
    this->speed_max = cfg->get_config_float("speed_max");

    //Size
    this->size_min = cfg->get_config_float("size_min");
    this->size_max = cfg->get_config_float("size_max");

    //Lifetime
    this->lifetime_min = cfg->get_config_float("lifetime_min");
    this->lifetime_max = cfg->get_config_float("lifetime_max");
}


ICreature* Factory::create_creature(){

    // Select a behaviour and the associated color
    std::unique_ptr<IBehaviour> behaviour;
    T* color;
    int n = std::rand()%this->pop_total;

    // Find the behaviour of n with a cumulative sum of behaviours population.
    if (n<pop_farsighted){
        behaviour = std::make_unique<Farsighted>();
        color = this->color_farsighted;
    }
    else if (n-=pop_farsighted;n<pop_fearful){
        behaviour = std::make_unique<Fearful>();
        color = this->color_fearful;
    }
    else if (n-=pop_fearful;n<pop_gregarious){
        behaviour = std::make_unique<Gregarious>();
        color = this->color_gregarious;
    }
    else if (n-=pop_gregarious;n<pop_kamikaze){
        behaviour = std::make_unique<Kamikaze>();
        color = this->color_kamikaze;
    }
    else {
        behaviour = std::make_unique<Schizophrenic>();
        color = this->color_schizophrenic;
    }

    int x        = rand() % this->medium_width;
    int y        = rand() % this->medium_hight;
    int lifetime = rand_range(lifetime_min, lifetime_max, 1000);
    float speed  = rand_range(this->speed_min, this->speed_max, 1000);
    float size   = rand_range(this->size_min, this->size_max, 1000);

    ICreature* creature = new Creature(std::move(behaviour),color,lifetime,speed,size,x,y);

    return creature;
}