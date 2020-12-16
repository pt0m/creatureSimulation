#include "Fin.h"
#include <cstdlib> // for rand  and RAND_MAX
#include "Config.h"

Fin::Fin(ICreature *c): CreatureDecorator(c) {
	Config* config_singleton = Config::get_instance();
	float max_mult_coef = config_singleton->get_config_float("fin_max_mult_coef");
	float rnd = float(std::rand()) / float(RAND_MAX);
    this->fin_mult_coef = 1.0 + (max_mult_coef-1.0)*rnd;
}

float Fin::get_speed() const {
    // we will have to set the next variable from the config file
    float old_speed = CreatureDecorator::get_speed();
    return old_speed* this->fin_mult_coef;
}

void Fin::draw(UImg &support) const {
    CreatureDecorator::draw(support);

    float size =  this->get_size();
    int x0 = int(size/10);
    int y0 = int(size/10);

    int x1 = this->get_x() - x0;
    int y1 = this->get_y() - y0;

    int x2 = this->get_x() - x0;
    int y2 = this->get_y() - y0;

    int x3 = this->get_x();
    int y3 = this->get_y() + y0;

    T* black = new T[ 3 ];
    black[ 0 ] = 0;
    black[ 1 ] = 0;
    black[ 2 ] = 0;

    support.draw_triangle(x1,y1,x2,y2,x3,y3,black,1,2);

}
