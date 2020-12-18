#include "Fin.h"
#include "Config.h"
#include "utils.h"

#include <cmath>  // for cos, sin, acos and sqrt

Fin::Fin(ICreature *c): CreatureDecorator(c) {
	Config* config_singleton = Config::get_instance();
    float max_mult_coef = config_singleton->get_config_float("fin_max_mult_coef");
    float min_mult_coef = config_singleton->get_config_float("fin_min_mult_coef");
    this->fin_mult_coef = rand_range(min_mult_coef, max_mult_coef, 10000);
}

ICreature *Fin::clone(){
    ICreature* c = CreatureDecorator::clone();
    ICreature* creature_decorated = new Fin(c);
    return creature_decorated;
}

float Fin::get_speed() const {
    // we will have to set the next variable from the config file
    float old_speed = CreatureDecorator::get_speed();
    return old_speed* this->fin_mult_coef;
}

void Fin::draw(UImg &support) const {
    CreatureDecorator::draw(support);

    int x = this->get_x();
    int y = this->get_y();
    float vx = this->get_vx();
    float vy = this->get_vy();
    float size = this->get_size();
    float norm_v = sqrt(vx*vx+vy*vy);
    float orientation;

    if (vy <= 0)
        orientation = acos(vx / norm_v);
    else
        orientation = 2 * M_PI - acos(vx / norm_v);

    float dir_x = vx/norm_v;
    float dir_y = vy/norm_v;

    int x1 = x+dir_y*size/3;
    int y1 = y-dir_x*size/3;

    int x2 = x-dir_y*size/3;
    int y2 = y+dir_x*size/3;

    T black[3] = {0,0,0};

    support.draw_ellipse(x1,y1,size/6,size/3,
        -orientation/M_PI*180.,black);
    support.draw_ellipse(x2,y2,size/6,size/3,
        -orientation/M_PI*180.,black);
}
