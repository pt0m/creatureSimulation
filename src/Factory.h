#ifndef FACTORY_H
#define FACTORY_H

#include "ICreature.h"
#include "UImg.h"


class ICreature;

class Factory {
    private:
        T color_farsighted[3]    = {229,0,0};
        T color_fearful[3]       = {170,170,0};
        T color_gregarious[3]    = {0,229,0};
        T color_kamikaze[3]      = {0,170,170};
        T color_schizophrenic[3] = {100,100,100};
        //Behaviours proportions
        int pop_farsighted;
        int pop_fearful;
        int pop_gregarious;
        int pop_kamikaze;
        int pop_schizophrenic;
        int pop_total;
        //Accessories probabilities
        float proba_camouflage;
        float proba_ears;
        float proba_eyes;
        float proba_fin;
        float proba_shell;

        //Initial x,y
        int medium_width;
        int medium_height;

        //Speed
        int speed_min;
        int speed_max;

        //Size
        int size_min;
        int size_max;

        //Lifetime
        int lifetime_min;
        int lifetime_max;

    public:
        Factory();
        ICreature* create_creature();
};

#endif // FACTORY_H
