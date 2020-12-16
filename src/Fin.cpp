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
    //we will have to draw something more after that to plot the shell
    // TODO:add here the code to draw the fin here (creature is already drawn)

}
