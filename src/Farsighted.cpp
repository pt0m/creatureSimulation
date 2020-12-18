#include <cmath>        // sqrt
#include <list>
#include <memory>       // std::unique_ptr

#include "Config.h"
#include "Farsighted.h"
#include "ICreature.h"
#include "Medium.h"


Farsighted::Farsighted(){
    Config* cfg = Config::get_instance();
    this->nb_dt_forecast = cfg->get_config_int("nb_dt_forecast");
}


std::unique_ptr<IBehaviour> Farsighted::clone_behaviour(){
    return std::make_unique<Farsighted>();
}


void Farsighted::next_step(ICreature* creature, Medium* my_medium){

    std::unique_ptr<std::list<ICreature*>> neighbours = my_medium->list_neighbours(*creature);

    int new_x = creature->get_x();
    int new_y = creature->get_y();

    int pred_self_x, pred_self_y;
    int pred_rela_x, pred_rela_y;
    float self_size = creature->get_size();
    float sum_sizes;
    float sq_sizes;
    float sq_dist;
    float new_vx, new_vy, real_norm, expect_norm;
    std::list<ICreature*>::iterator iter;
    ICreature* it;

    // Predict positions of neighbours at t+dt, t+2dt ..., t+nb_dt_forecast*dt.
    // The creature will avoid the closest (in time) collision risk.
    for (unsigned int dt = 1; dt <= this->nb_dt_forecast; dt++){

        // Predict the creature position.
        pred_self_x = new_x + creature->get_vx()*dt;
        pred_self_y = new_y + creature->get_vy()*dt;

        // Go trough the neighbours list to check is there is no colision risk.
        for (iter=neighbours->begin(); iter!=neighbours->end(); ++iter){
            it = *iter;

            // Predict relative position of the 2 creatures.
            pred_rela_x = it->get_x() + it->get_vx()*dt - pred_self_x;
            pred_rela_y = it->get_y() + it->get_vy()*dt - pred_self_y;

            sq_dist = pred_rela_x*pred_rela_x+pred_rela_y*pred_rela_y;
            sum_sizes = it->get_size()+self_size;
            sq_sizes = sum_sizes*sum_sizes;

            // Collision
            if (sq_sizes>=sq_dist){
                // Reverse the normal speed component to the neighbour
                // trajectory.

                // Define the unit vector of the neighbour trajectory.
                float neigh_vx = it->get_vx();
                float neigh_vy = it->get_vy();
                float norm_v_neigh = sqrt(neigh_vx*neigh_vx+neigh_vy*neigh_vy);
                float u_dir_x=neigh_vx/norm_v_neigh;
                float u_dir_y=neigh_vy/norm_v_neigh;

                // Compute the reflection (Vt+Vn -> Vt-Vn)
                float self_vx = creature->get_x();
                float self_vy = creature->get_y();
                float v_t_norm = self_vx*u_dir_x+self_vy*u_dir_y;
                float v_n_norm = self_vx*u_dir_y-self_vy*u_dir_x;
                new_vx = u_dir_x*v_t_norm-u_dir_y*v_n_norm;
                new_vy = u_dir_y*v_t_norm+u_dir_x*v_n_norm;
                
                // Prevend rounding from changing the speed norm
                real_norm = sqrt(new_vx*new_vx+new_vy*new_vy);
                expect_norm = creature->get_speed();
                new_vx *= expect_norm/real_norm;
                new_vy *= expect_norm/real_norm;

                creature->set_vx_vy(new_vx,new_vy);

                goto compute_new_xy;
            }
        }
    }

    new_vx = creature->get_vx();
    new_vy = creature->get_vy();
    real_norm = sqrt(new_vx*new_vx+new_vy*new_vy);
    expect_norm = creature->get_speed();
    new_vx *= expect_norm/real_norm;
    new_vy *= expect_norm/real_norm;

    //label goto
    compute_new_xy:

    new_x += new_vx;
    new_y += new_vy;

    this->handle_border(creature, my_medium, new_x, new_y);
}