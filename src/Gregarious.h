#ifndef GREGARIOUS_H
#define GREGARIOUS_H

#include <memory>       // std::unique_ptr

#include "IBehaviour.h"
#include "ICreature.h"

class Gregarious : public IBehaviour{

    public:
        std::unique_ptr<IBehaviour> clone_behaviour();
        void next_step(ICreature* creature, Medium& my_medium);
};

#endif //GREGARIOUS_H