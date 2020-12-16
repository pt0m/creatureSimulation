#include <cmath>        // sqrt
#include <list>
#include <memory>       // std::unique_ptr

#include "Config.h"
#include "Fearful.h"
#include "ICreature.h"
#include "Medium.h"


Fearful::Fearful(){
    Config* cfg = Config::get_instance();
    this->too_crowded_limit = cfg->get_config_int("too_crowded_limit");
    this->scared_speed_boost = cfg->get_config_float("scared_speed_boost");
    this->scared_remain_duration = 0;
    this->scared_total_duration=cfg->get_config_int("scared_total_duration");
}


std::unique_ptr<IBehaviour> Fearful::clone_behaviour(){
    return std::make_unique<Fearful>();
}


void Fearful::next_step(ICreature* creature, Medium* my_medium){

    std::unique_ptr<std::list<ICreature*>> neighbours = my_medium->list_neighbours(*creature);
    int nb_neighbours = neighbours->size();

    int new_x = creature->get_x();
    int new_y = creature->get_y();

    if (nb_neighbours>this->too_crowded_limit){
        this->scared_remain_duration = this->scared_total_duration;
    }

    // Scared creature: goes toward the opposit direction of the mean position
    // of the neighbours with a speed boost.
    if (this->scared_remain_duration > 0){
        this->scared_remain_duration--;
        if (nb_neighbours != 0){
            // Mean position of neighbours computation.
            double sum_x = 0;
            double sum_y = 0;
            std::list<ICreature*>::iterator iter;
            ICreature* it;
            for (iter=neighbours->begin(); iter!=neighbours->end(); ++iter){
                it = *iter;
                sum_x += it->get_x();
                sum_y += it->get_y();
            }
            double mean_x = sum_x/nb_neighbours;
            double mean_y = sum_y/nb_neighbours;

            // Speed direction: opposit to the mean positon of neighbours.
            double dir_x = new_x-mean_x;
            double dir_y = new_y-mean_y;
            double dir_norm = sqrt(dir_x*dir_x+dir_y*dir_y);

            double speed_norm = this->scared_speed_boost*creature->get_speed();

            double new_vx = dir_x/dir_norm*speed_norm;
            double new_vy = dir_y/dir_norm*speed_norm;
            creature->set_vx_vy(new_vx,new_vy);

            new_x += new_vx;
            new_y += new_vy;
        }
        else{
            new_x += creature->get_vx();
            new_y += creature->get_vy();
        }
    }
    // Not scared creature: continue toward the same direction with basic speed.
    else{
        double new_vx = creature->get_vx();
        double new_vy = creature->get_vy();

        double old_speed_norm = sqrt(new_vx*new_vx+new_vy*new_vy);
        double new_speed_norm = creature->get_speed();

        new_vx *= new_speed_norm/old_speed_norm;
        new_vy *= new_speed_norm/old_speed_norm;

        creature->set_vx_vy(new_vx,new_vy);

        new_x += new_vx;
        new_y += new_vy;
    }

    this->handle_border(creature, my_medium, new_x, new_y);
}