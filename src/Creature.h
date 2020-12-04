#ifndef CREATURE_H
#define CREATURE_H

#include "ICreature.h"
#include "Medium.h"


class Creature : public ICreature {

private:
    static const double AFF_SIZE;
    static const double LIMIT_VIEW;
    static const double MAX_SPEED;


private:
    double camouflage
    int identity;
    int lifetime;
    float orientation;
    float size;
    double speed;
    double vx;
    double vy;
    int x;
    int y;

public:

    Creature();

    Creature(const Creature &c);

    void action(const Medium &myMedium);

    void draw(UImg &support);

    void init_coords(const int x, const int y);

    const bool is_collision_deadly();

    const bool is_detected(const ICreature &);

    const double get_camouflage();

    const int get_lifetime();

    const void get_speed();

    void set_camouflage(const int new_val);

    int set_lifetime(const int new_val);

    void set_speed(const double new_val);

};


#endif //CREATURE_H

