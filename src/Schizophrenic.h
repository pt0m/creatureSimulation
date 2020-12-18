#ifndef SCHIZOPHRENIC_H
#define SCHIZOPHRENIC_H

#include <memory>       // std::unique_ptr

#include "IBehaviour.h"
#include "ICreature.h"
#include "Medium.h"
#include "UImg.h"

//Number of atomic behaviours that can be used for the Schizophrenic
#define NB_BEHAVIOURS 4


class Schizophrenic : public IBehaviour{

    private:
        T color_farsighted[3]    = {229,0,0};
        T color_fearful[3]       = {170,170,0};
        T color_gregarious[3]    = {0,229,0};
        T color_kamikaze[3]      = {0,170,170};
        T* list_color[NB_BEHAVIOURS] = {color_farsighted, color_fearful,
                                        color_gregarious, color_kamikaze};
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