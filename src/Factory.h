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

        //Camouflage
        float camouflage_min;
        float camouflage_max;
        //Ears properties
        float ears_distance_min;
        float ears_distance_max;
        float ears_quality_min;
        float ears_quality_max;
        //Eyes properties
        float eyes_angle_min;
        float eyes_angle_max;
        float eyes_distance_min;
        float eyes_distance_max;
        float eyes_quality_min;
        float eyes_quality_max;
        //Fin
        float fin_speed_boost_max;
        //Shell
        float shell_protect_max;
        float shell_speed_reduc;

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
