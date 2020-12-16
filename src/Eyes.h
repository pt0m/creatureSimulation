
#ifndef EYES_H
#define EYES_H

#include "CreatureDecorator.h"
#include "ICreature.h"
#include "UImg.h"

class Eyes: public CreatureDecorator {
private:
    float detection_capacity_eyes;
    float max_range;
    float max_angle;
public:
    Eyes(ICreature* c);
    bool is_detected(const ICreature &c) const override;
    void draw(UImg &support) const override;
    ICreature* clone() override;
};

#endif //EYES_H
