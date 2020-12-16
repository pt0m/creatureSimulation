#include "Eyes.h"
#include "Config.h"

#include <cmath>  // for cos, sin, acos and sqrt

Eyes::Eyes(ICreature *c): CreatureDecorator(c) {
    this->detection_capacity_eyes = float(std::rand())/float(RAND_MAX);
    // we will have to set the next variable from the config file
    Config* config_singleton = Config::get_instance();
    float max_r = config_singleton->get_config_float("max_range_detection_eyes");
    float min_r = config_singleton->get_config_float("min_range_detection_eyes");
    this->max_range = min_r + (max_r-min_r)* (float(std::rand())/float(RAND_MAX));

    float max_a = config_singleton->get_config_float("max_angle_detection_eyes");
    float min_a = config_singleton->get_config_float("min_angle_detection_eyes");
    this->max_angle = min_a + (max_a-min_a)* (float(std::rand())/float(RAND_MAX));
}

ICreature* Eyes::clone(){
    ICreature* c = CreatureDecorator::clone();
    ICreature* CreatureDecorated = new Eyes(c);
    return CreatureDecorated;
}

bool Eyes::is_detected(const ICreature &c) const {
    bool already_detected = CreatureDecorator::is_detected(c);
    bool detected = false;
    if (!already_detected){
        float camouflage_capacity = c.get_camouflage();

        int x_pos = c.get_x();
        int y_pos = c.get_y();

        int self_x = this->get_x();
        int self_y = this->get_y();

        int xv = this->get_vx();
        int yv = this->get_vx();

        float diff_x = float(x_pos - self_x);
        float diff_y = float(y_pos - self_y);

        float norm_speed = this->get_speed();
        float norm_distance = sqrt(diff_x * diff_x + diff_y * diff_y);

        float angle = acos((xv*diff_x + yv*diff_x)/norm_speed*norm_distance);

        if (angle < this->max_angle && camouflage_capacity < this->detection_capacity_eyes) {
            detected = norm_distance < this->max_range;
        }
    }
    return already_detected || detected;
}


void Eyes::draw(UImg &support) const{
    CreatureDecorator::draw(support);

    float size =  this->get_size();
    int r = int(size/20);

    int x0 = this->get_x();
    int y0 = this->get_y();

    T* black = new T[ 3 ];
    black[ 0 ] = 0;
    black[ 1 ] = 0;
    black[ 2 ] = 0;

    support.draw_ellipse(x0,y0,r,r,0,black,1,2);

}