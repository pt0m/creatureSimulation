#ifndef ICREATURE_H
#define ICREATURE_H

#include "Medium.h"
#include "UImg.h"

// Mutual inclusion
class Medium;


class ICreature {
    // Define operations that can be altered by decorators
public:
    ~ICreature() = default;

class ICreature {
    // Define operations that can be altered by decorators
public:
    ~ICreature() = default;
    virtual void action(const Medium &myMedium) = 0;

    virtual void draw(UImg &support) = 0;

    virtual bool is_detected(const ICreature &c) = 0;

    virtual bool is_collision_deadly() = 0;

    virtual float get_speed() = 0;

    virtual float get_camouflage() = 0;

    virtual int get_lifetime() = 0;

    virtual float get_size() = 0;

    virtual int get_x() = 0;

    virtual int get_y() = 0;

    virtual float get_vx() = 0;

    virtual float get_vy() = 0;

    virtual void set_lifetime(const int new_val) = 0;

    virtual void set_coords(const int x, const int y) = 0;

    virtual void set_vx_vy(const int vx, const int vy) = 0;
};

#endif //ICREATURE_H
