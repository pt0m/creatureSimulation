#include <cmath>        // sqrt
#include <list>
#include <memory>       // std::unique_ptr

#include "Kamikaze.h"
#include "ICreature.h"
#include "Medium.h"


std::unique_ptr<IBehaviour> Kamikaze::clone_behaviour(){
    return std::make_unique<Kamikaze>();
}


void Kamikaze::next_step(ICreature* creature, Medium* my_medium){

    std::unique_ptr<std::list<ICreature*>> neighbours = my_medium->list_neighbours(*creature);
    unsigned int nb_neighbours = neighbours->size();

    int new_x = creature->get_x();
    int new_y = creature->get_y();

    // Find the closest neighbour
    if (nb_neighbours != 0){
        int max_dx = my_medium->get_width();
        int max_dy = my_medium->get_height();

        double curr_sq_dist, min_sq_dist = max_dx*max_dx+max_dy*max_dy;
        int target_x, target_y, curr_x, curr_y, rel_x, rel_y ;

        // Go trough the neighbours list to find the closest
        std::list<ICreature*>::iterator iter;
        ICreature* it;
        for (iter=neighbours->begin(); iter!=neighbours->end(); ++iter){
            it = *iter;
            curr_x = it->get_x();
            curr_y = it->get_y();
            rel_x = curr_x-new_x;
            rel_y = curr_y-new_y;
            curr_sq_dist = rel_x*rel_x+rel_y*rel_y;

            if (curr_sq_dist<min_sq_dist){
                target_x = curr_x;
                target_y = curr_y;
                min_sq_dist = curr_sq_dist;
            }
        }

        double dir_x = target_x-new_x;
        double dir_y = target_y-new_y;
        double dir_norm = sqrt(dir_x*dir_x+dir_y*dir_y);
        if (dir_norm>0.01){
            double speed_norm = creature->get_speed();

            double new_vx = dir_x*speed_norm/dir_norm;
            double new_vy = dir_y*speed_norm/dir_norm;
            creature->set_vx_vy(new_vx,new_vy);

            new_x += new_vx;
            new_y += new_vy;
        }
        else{
            new_x += creature->get_vx();
            new_y += creature->get_vy();
        }
    }
    // Continue toward the same direction if there is no neighours
    else{
        new_x += creature->get_vx();
        new_y += creature->get_vy();
    }

    this->handle_border(creature, my_medium, new_x, new_y);
}