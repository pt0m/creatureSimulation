#ifndef CREATURE_H
#define CREATURE_H

#include "ICreature.h"
#include "Medium.h"
#include "UImg.h"


class Creature : public ICreature {

private:
    static const double AFF_SIZE;
    static const double LIMIT_VIEW;
    static const double MAX_SPEED;


private:
    double camouflage;
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

    void action(const Medium &myMedium) override;

    void draw(UImg &support) override;

    void init_coords(const int x, const int y) override;

    const bool is_collision_deadly() override;

    const bool is_detected(const ICreature &c) override;

    const double get_camouflage() override;

    const int get_lifetime() override;

    const double get_speed() override;

    const int get_x() override;

    const int get_y() override;

    const double get_vx() override;

    const double get_vy() override;

    void set_camouflage(const int new_val) override;

    void set_lifetime(const int new_val) override;

    void set_speed(const double new_val) override;

};


#endif //CREATURE_H

