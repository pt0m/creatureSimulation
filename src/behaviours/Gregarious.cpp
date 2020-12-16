#include <cmath>        // sqrt
#include <list>
#include <memory>       // std::unique_ptr

#include "Gregarious.h"
#include "ICreature.h"
#include "Medium.h"


std::unique_ptr<IBehaviour> Gregarious::clone_behaviour(){
    return std::make_unique<Gregarious>();
}


void Gregarious::next_step(ICreature* creature, Medium* my_medium){

    std::unique_ptr<std::list<ICreature*>> neighbours = my_medium->list_neighbours(*creature);
    unsigned int nb_neighbours = neighbours->size();

    int new_x = creature->get_x();
    int new_y = creature->get_y();

    // No neighbours: keep the same velocity
    if (nb_neighbours==0){
        new_x += creature->get_vx();
        new_y += creature->get_vy();
    }
    // Neighbours detected: follow their mean direction
    else{
        double sum_vx = 0;
        double sum_vy = 0;
        std::list<ICreature*>::iterator iter;
        ICreature* it;
        for (iter=neighbours->begin(); iter!=neighbours->end(); ++iter){
            it = *iter;
            sum_vx += it->get_vx();
            sum_vy += it->get_vy();
        }

        double dir_vx = sum_vx/nb_neighbours;
        double dir_vy = sum_vy/nb_neighbours;

        double norm_unit = 1/sqrt(dir_vx*dir_vx+dir_vy*dir_vy);
        double norm_v    = creature->get_speed()*norm_unit;

        double new_vx = norm_v*dir_vx;
        double new_vy = norm_v*dir_vy;
        creature->set_vx_vy(new_vx,new_vy);

        new_x += new_vx;
        new_y += new_vy;
    }

    this->handle_border(creature, my_medium, new_x, new_y);
}