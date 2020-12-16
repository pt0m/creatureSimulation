#include "Ears.h"
#include "Config.h"

#include <cstdlib>

Ears::Ears(ICreature *c): CreatureDecorator(c) {
    this->detection_capacity_ears = float(std::rand())/float(RAND_MAX);
    // we will have to set the next variable from the config file
    Config* config_singleton = Config::get_instance();
    this->max_range = config_singleton->get_config_float("max_range_detection_ears") * (float(std::rand())/float(RAND_MAX));
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
    //we will have to draw something more after that to plot the shell
    /*
     * add here the code to draw the shell (creature is already drawn)
     */

}