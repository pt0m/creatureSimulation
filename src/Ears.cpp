#include "Ears.h"
#include "Config.h"
#include "utils.h"

Ears::Ears(ICreature *c): CreatureDecorator(c) {
    // we will have to set the next variable from the config file
    Config* config_singleton = Config::get_instance();
    float max_r = config_singleton->get_config_float("max_range_ears");
    float min_r = config_singleton->get_config_float("min_range_ears");
    this->max_range = rand_range(min_r,max_r, 10000);
    float max_q = config_singleton->get_config_float("ears_quality_max");
    float min_q = config_singleton->get_config_float("ears_quality_min");
    this->detection_capacity_ears = rand_range(min_q,max_q, 10000);

}

bool Ears::is_detected(const ICreature &c) const {
    bool already_detected = CreatureDecorator::is_detected(c);
    bool detected = false;
    if (!already_detected){
        float camouflage_capacity = c.get_camouflage();

        if (camouflage_capacity < this->detection_capacity_ears) {

            int x_pos = c.get_x();
            int y_pos = c.get_y();

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

ICreature *Ears::clone(){
    ICreature* c = CreatureDecorator::clone();
    ICreature* creature_decorated = new Ears(c);
    return creature_decorated;
}

void Ears::draw(UImg &support) const{
    CreatureDecorator::draw(support);

    float vx = this->get_vx();
    float vy = this->get_vy();
    float size = this->get_size();
    float norm_v = sqrt(vx*vx+vy*vy);

    float dir_x = vx/norm_v;
    float dir_y = vy/norm_v;

    double xt = this->get_x() + dir_x*size/2;
    double yt = this->get_y() + dir_y*size/2;

    float dir_ear_x1 = (dir_x-dir_y)*sqrt(2);
    float dir_ear_y1 = (dir_y+dir_x)*sqrt(2);
    float dir_ear_x2 = (dir_x+dir_y)*sqrt(2);
    float dir_ear_y2 = (dir_y-dir_x)*sqrt(2);

    int x1 = xt+dir_ear_x1*size/4;
    int y1 = yt+dir_ear_y1*size/4;
    int xx1 = xt+dir_ear_x1*size/2;
    int yy1 = yt+dir_ear_y1*size/2;

    int x2 = xt+dir_ear_x2*size/4;
    int y2 = yt+dir_ear_y2*size/4;
    int xx2 = xt+dir_ear_x2*size/2;
    int yy2 = yt+dir_ear_y2*size/2;

    T black[3] = {0,0,0};

    support.draw_line(x1,y1,xx1,yy1,black,1);
    support.draw_line(x2,y2,xx2,yy2,black,1);
    support.draw_circle(xx1, yy1, size/16, black);
    support.draw_circle(xx2, yy2, size/16, black);
}