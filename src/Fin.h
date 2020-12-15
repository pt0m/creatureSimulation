//
// Created by Ménard Luc on 15/12/2020.
//

#ifndef CREATURESIMULATION_FIN_H
#define CREATURESIMULATION_FIN_H


class Fin: public CreatureDecrorator{
public:
    Fin(ICreature* c);
    float get_speed() const override;
    void draw(UImg &support) const override;
};


#endif //CREATURESIMULATION_FIN_H
