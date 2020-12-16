#include "Ears.h"
#include "Config.h"

#include <cstdlib>

Ears::Ears(ICreature *c): CreatureDecorator(c) {
    this->detection_capacity_ears = float(std::rand())/float(RAND_MAX);
    // we will have to set the next variable from the config file
    Config* config_singleton = Config::get_instance();
    float max = config_singleton->get_config_float("max_range_detection_ears");
    float min = config_singleton->get_config_float("min_range_detection_ears");
    this->max_range = min + (max-min)* (float(std::rand())/float(RAND_MAX));
}

bool Ears::is_detected(const ICreature &c) const {
    bool already_detected = CreatureDecorator::is_detected(c);
    bool detected = false;
    if (!already_detected){
        float camouflage_capacity = c.get_camouflage();

        if (camouflage_capacity < this->detection_capacity_ears) {

            int x_pos = c->get_x();
            int y_pos = c->get_y();

            int self_x = this->get_x();
            int self_y = this->get_y();

            float diff_x = float(self_x - x_pos);
            float diff_y = float(self_y - y_pos);

            float distance = sqrt(diff_x * diff_x + diff_y * diff_y);

            if (distance < this->max_range) {
                detected = true;
            }
        }
    }
    return already_detected || detected;
}

void Ears::draw(UImg &support) const{
    CreatureDecorator::draw(support);

    float size =  this->get_size();
    int x0 = int(size/10);
    int y0 = int(size/10);

    int x1 = this->get_x() + x0;
    int y1 = this->get_y() + y0;

    int x2 = this->get_x() - x0;
    int y2 = this->get_y() + y0;

    int x3 = this->get_x();
    int y3 = this->get_y() - y0;

    T* black = new T[ 3 ];
    black[ 0 ] = 0;
    black[ 1 ] = 0;
    black[ 2 ] = 0;

    support.draw_triangle(x1,y1,x2,y2,x3,y3,black,1,2);




}