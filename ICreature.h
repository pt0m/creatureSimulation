#ifndef ICREATURE_H
#define ICREATURE_H

class ICreature {
    virtual void creature() = 0;

    virtual void creature(const ICreature &c) = 0;

    virtual void action(const Medium &myMedium) = 0;

    virtual void draw(UImg &support) = 0;

    virtual const bool is_detected(const ICreature &) = 0;

    virtual void init_coords(const int x, const int y) = 0;

    virtual const void get_speed() = 0;

    virtual void set_speed(const double new_val) = 0;

    virtual const double get_camouflage() = 0;

    virtual void set_camouflage(const int new_val) = 0;

    virtual const int get_lifetime() = 0;

    virtual int set_lifetime(const int new_val);

    virtual const bool is_collision_deadly() = 0;

};

#endif //ICREATURE_H
