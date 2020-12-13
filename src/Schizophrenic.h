#ifndef SCHIZOPHRENIC_H
#define SCHIZOPHRENIC_H

#include <memory>       // std::unique_ptr

#include "IBehaviour.h"
#include "ICreature.h"
#include "Medium.h"

//Number of atomic behaviours that can be used for the Schizophrenic
#define NB_BEHAVIOURS 4


class Schizophrenic : public IBehaviour{

    private:
        std::unique_ptr<IBehaviour> list_behaviours[NB_BEHAVIOURS];
        char current_behaviour;
        unsigned int phase_remain_duration;
        unsigned int phase_total_duration;

    public:
        Schizophrenic();
        std::unique_ptr<IBehaviour> clone_behaviour();
        void next_step(ICreature* creature, Medium* my_medium);
};

#endif //SCHIZOPHRENIC_H