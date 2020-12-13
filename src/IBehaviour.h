#ifndef IBEHAVIOUR_H
#define IBEHAVIOUR_H

#include <memory>

#include "ICreature.h"
#include "Medium.h"


class IBehaviour {

    public:
        virtual std::unique_ptr<IBehaviour> clone_behaviour() = 0;
        virtual void next_step(ICreature* creature, Medium* my_medium) = 0;
    protected:
        void handle_border(ICreature* creature,Medium* my_medium, int new_x, int new_y);
};

#endif //IBEHAVIOUR_H