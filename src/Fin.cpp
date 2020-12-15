//
// Created by Ménard Luc on 15/12/2020.
//

#include "Fin.h"
#include <cstdlib>


Fin::Fin(ICreature *c): CreatureDecorator(c) {}

float Fin::get_speed() const {
    // we will have to set the next variable from the config file
    float factor_speed = 0.7;
    float old_speed = CreatureDecorator::get_speed();
    return old_speed*factor_speed;
}

void Fin::draw(UImg &support) const {
    CreatureDecorator::draw(UImg &support);
    //we will have to draw something more after that to plot the shell
    /*
     * add here the code to draw the shell (creature is already drawn)
     */

}