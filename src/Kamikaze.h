#ifndef KAMIKAZE_H
#define KAMIKAZE_H

#include <memory>       // std::unique_ptr

#include "IBehaviour.h"
#include "ICreature.h"

class Kamikaze : public IBehaviour{

    public:
        std::unique_ptr<IBehaviour> clone_behaviour();
        void next_step(ICreature* creature, Medium& my_medium);

};

#endif //KAMIKAZE_H