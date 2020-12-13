#ifndef FARSIGHTED_H
#define FARSIGHTED_H

#include <memory>       // std::unique_ptr

#include "IBehaviour.h"
#include "ICreature.h"

class Farsighted : public IBehaviour{
    private:
        unsigned int nb_dt_forecast;
    public:
        Farsighted();
        std::unique_ptr<IBehaviour> clone_behaviour();
        void next_step(ICreature* creature, Medium& my_medium);
};

#endif //FARSIGHTED_H