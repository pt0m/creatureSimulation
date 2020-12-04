#ifndef CREATURE_H
#define CREATURE_H

#include "ICreature.h"
#include "Medium.hpp"

#include <vector>

class Creature: public ICreature {

private:
    static const double     AFF_SIZE;
    static const double     MAX_SPEED;
    static const double     LIMIT_VIEW;


private:

    int identity;
    int x;
    int y;
    double vx;
    double vy;
    float orientation
    double speed;
    T* color:
    float size;
    int lifetime;
    IBehaviour behaviour;
    double camouflage

public:

    Creature();

    Creature(const Creature& c);

    void action(const Medium &myMedium);

    void draw(UImg &support);

    const bool is_detected(const ICreature &);

    void init_coords(const int x, const int y) ;

    const void get_speed();

    void set_speed(const double new_val);

    const double get_camouflage();

    void set_camouflage(const int new_val);

    const int get_lifetime();

    int set_lifetime(const int new_val);

    const bool is_collision_deadly();

};


#endif //CREATURE_H

