#include "Eyes.h"
#include "Config.h"
#include "utils.h"

#include <cmath>  // for cos, sin, acos and sqrt

Eyes::Eyes(ICreature *c): CreatureDecorator(c) {
    // we will have to set the next variable from the config file
    Config* config_singleton = Config::get_instance();
    float max_r = config_singleton->get_config_float("max_range_eyes");
    float min_r = config_singleton->get_config_float("min_range_eyes");
    this->max_range = rand_range(min_r,max_r, 10000);

    float max_a = config_singleton->get_config_float("max_angle_eyes");
    float min_a = config_singleton->get_config_float("min_angle_eyes");
    this->max_angle =  rand_range(min_a,max_a, 10000);

    float max_q = config_singleton->get_config_float("ears_quality_max");
    float min_q = config_singleton->get_config_float("ears_quality_min");
    this->detection_capacity_eyes =  rand_range(min_q,max_q, 10000);
}

ICreature *Eyes::clone(){
    ICreature* c = CreatureDecorator::clone();
    ICreature* creature_decorated = new Eyes(c);
    return creature_decorated;
}

bool Eyes::is_detected(const ICreature &c) const {
    // Alredy detected ?
    if (CreatureDecorator::is_detected(c))
        return true;
    // Not too much camouflage ?
    if (c.get_camouflage()>this->detection_capacity_eyes)
        return false;

    int x_pos = c.get_x();
    int y_pos = c.get_y();

    int self_x = this->get_x();
    int self_y = this->get_y();

    float vx = this->get_vx();
    float vy = this->get_vx();

    float diff_x = float(x_pos - self_x);
    float diff_y = float(y_pos - self_y);

    float norm_speed = sqrt(vx*vx+vy*vy);
    float norm_distance = sqrt(diff_x * diff_x + diff_y * diff_y);

    float cos_angle = (vx*diff_x + vy*diff_x)/norm_speed*norm_distance;

    if (cos_angle > cos(this->max_angle))
        return true;
    else
        return false;
}


void Eyes::draw(UImg &support) const{
    CreatureDecorator::draw(support);

    float vx = this->get_vx();
    float vy = this->get_vy();
    float size = this->get_size();
    float norm_v = sqrt(vx*vx+vy*vy);

    float dir_x = vx/norm_v;
    float dir_y = vy/norm_v;

    double xt = this->get_x() + dir_x * size/2;
    double yt = this->get_y() + dir_y * size/2;

    int x1 = xt+dir_y*size/5;
    int y1 = yt-dir_x*size/5;

    int x2 = xt-dir_y*size/5;
    int y2 = yt+dir_x*size/5;

    T white[3] = {255,255,255};
    T black[3] = {0,0,0};

    support.draw_circle(x1, y1, size/6., white);
    support.draw_circle(x2, y2, size/6., white);
    support.draw_circle(x1, y1, size/8., black);
    support.draw_circle(x2, y2, size/8., black);
}