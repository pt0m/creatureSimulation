#ifndef CREATURE_H
#define CREATURE_H

#include "ICreature.h"
#include "Medium.h"
#include "IBehaviour.h"

#include "UImg.h"
#include <memory>

class Creature : public ICreature {

private:
    static uint NEXT_IDENTITY


private:
    float camouflage;
    int identity;
    int lifetime;
    float orientation;
    float size;
    double speed;
    int vx;
    int vy;
    int x;
    int y;
    IBehaviour behaviour;

    T * color;


 public:

    Creature(std::unique_ptr<IBehaviour> behaviour);

    ~Creature();

    void action(const Medium &myMedium) override;

    void draw(UImg &support) override;

    void set_coords(const int x, const int y) override;

    const bool is_collision_deadly() override;

    const bool is_detected(const ICreature &c) override;

    const float get_camouflage() override;

    const int get_lifetime() override;

    const int get_speed() override;

    const int get_x() override;

    const int get_y() override;

    const int get_vx() override;

    const int get_vy() override;

    void set_lifetime(const int new_val) override;

    void set_speed(const int new_val) override;


};

#endif //CREATURE_H

