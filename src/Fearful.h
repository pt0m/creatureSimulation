#ifndef FEARFUL_H
#define FEARFUL_H

#include <memory>       // std::unique_ptr

#include "IBehaviour.h"
#include "ICreature.h"

class Fearful : public IBehaviour{
    private:
        int too_crowded_limit;
        float scared_speed_boost;
        unsigned int scared_remain_duration;
        unsigned int scared_total_duration;
    public:
        Fearful();
        std::unique_ptr<IBehaviour> clone_behaviour();
        void next_step(ICreature* creature, Medium& my_medium);
};

#endif //FEARFUL_H