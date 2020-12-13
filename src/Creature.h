#ifndef CREATURE_H
#define CREATURE_H

#include "ICreature.h"
#include "Medium.h"
#include "UImg.h"


class Creature : public ICreature {

private:
    static const float AFF_SIZE;
    static const float LIMIT_VIEW;
    static const float MAX_SPEED;


private:
    float camouflage;
    int identity;
    int lifetime;
    float orientation;
    float size;
    float speed;
    float vx;
    float vy;
    int x;
    int y;

public:

    Creature();

    Creature(const Creature &c);

    void action(const Medium &myMedium) override;

    void draw(UImg &support) override;

    const bool is_detected(const ICreature &c) override;

    const bool is_collision_deadly() override;

    const float get_speed() override;

    const float get_camouflage() override;

    const int get_lifetime() override;

    const float get_size() override;

    const int get_x() override;

    const int get_y() override;

    const float get_vx() override;

    const float get_vy() override;

    void set_lifetime(const int new_val) override;

    void set_coords(const int x, const int y) override;

    void set_vx_vy(const int vx, const int vy) override;

};


#endif //CREATURE_H

