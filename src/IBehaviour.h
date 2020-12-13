#ifndef IBEHAVIOUR_H
#define IBEHAVIOUR_H

#include <memory>

class IBehaviour {

    private:
        void handle_border(ICreature* creature,Medium& my_medium, int new_x, int new_y);
    public:
        virtual std::unique_ptr<IBehaviour> clone_behaviour() = 0;
        virtual void next_step(ICreature* creature, Medium& my_medium) = 0;
};

#endif //IBEHAVIOUR_H