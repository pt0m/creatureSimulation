#include "IBehaviour.h"
#include "ICreature.h"
#include "Medium.h"

#include <iostream>


/* This function handle the borders of the medium: if a creature hit a border,
// its normal speed components is changed into its opposit. */
void IBehaviour::handle_border(ICreature* creature,Medium* my_medium,int new_x,int new_y){
    int limit_x = my_medium->get_width()-1;
    if (new_x<0 || new_x>limit_x){
        new_x = (new_x<0)?0:limit_x;
        creature->set_vx_vy(-creature->get_vx(),creature->get_vy());
    }
    int limit_y = my_medium->get_height()-1;
    if (new_y<0 || new_y>limit_y){
        new_y = (new_y<0)?0:limit_y;
        creature->set_vx_vy(creature->get_vx(),-creature->get_vy());
    }
    creature->set_coords(new_x,new_y);
}