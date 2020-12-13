#ifndef MEDIUM_H
#define MEDIUM_H

#include <list>
#include <memory>       // std::unique_ptr

#include "Factory.h"
#include "ICreature.h"
#include "UImg.h"

// Mutual inclusion
class ICreature;


class Medium {
    private:
        std::list<ICreature*> list_creatures;
        Factory creature_factory;
        int max_birth;
        int width, height;
        float birthrate;
        float proba_clone;
    public:
        Medium();
        int get_width();
        int get_height();
        std::list<ICreature*>* get_list_creatures();
        void add_creature(const ICreature& creature);
        void collide(ICreature* c1, ICreature* c2);
        void kill_creature(ICreature* creature);
        std::unique_ptr<std::list<ICreature*>> list_neighbours(const ICreature* creature);
        void step();
};

#endif // MEDIUM_H
