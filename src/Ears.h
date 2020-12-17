#ifndef EARS_H
#define EARS_H

#include "CreatureDecorator.h"
#include "ICreature.h"
#include "UImg.h"

class Ears : public CreatureDecorator {
private:
    float detection_capacity_ears;
    float max_range;
public:
    Ears(ICreature* c);
    bool is_detected(const ICreature &c) const override;
    void draw(UImg &support) const override;
    ICreature *clone() override;
};


#endif //EARS_H
